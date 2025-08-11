#include <string>       // string
#include <algorithm>    // for_each, fill
#include <numeric>      // accumulate
#include <stdexcept>    // out_of_range

using namespace std;

namespace ilrd_166_7
{
/******************************* Constants ********************************/

const size_t BYTES_WORD = 8;
const size_t BITS_WORD = (sizeof(size_t) * BYTES_WORD);

/********************** Forward Declarations Functors *********************/

class FlipWord
{
public:
    void operator()(size_t& word);
};

class CountSetBitsInByte
{
public:
    size_t operator()(size_t sum, unsigned char byte) const;
};

class WordToString
{
public:
    void operator()(size_t word);
    string& GetResult();

private:
    string m_result;
};

class ShiftLeftByN
{
public:
    explicit ShiftLeftByN(size_t n);
    void operator()(size_t& word);

private:
    size_t m_shifts;
    size_t m_carry;
};

class ShiftRightByN
{
public:
    explicit ShiftRightByN(size_t n);

    void operator()(size_t& word);
private:
    size_t m_shifts;
    size_t m_carry;
};

/****************************** BitSet Class ******************************/

template<size_t Size>
class BitSet
{
private: 
    class BitProxy;

public:
    explicit BitSet() // Ctor
    {   
        Reset();
    }
   
/******************************* Operators ********************************/

    bool operator[](size_t index) const // throw out_of_range
    {
        return (Get(index));
    }

    BitProxy operator[](size_t index) // throw out_of_range
    {
        RangeCheck(index);

        return (BitProxy(*this, index));
    }
    
    BitSet& operator|=(const BitSet& other)
    {
        transform(m_bits, m_bits + m_word_num, other.m_bits, m_bits, bit_or<size_t>());

        return (*this);
    }

    BitSet& operator&=(const BitSet& other)
    {
        transform(m_bits, m_bits + m_word_num, other.m_bits, m_bits, bit_and<size_t>());

        return (*this);       
    }

    BitSet& operator^=(const BitSet& other)
    {
        transform(m_bits, m_bits + m_word_num, other.m_bits, m_bits, bit_xor<size_t>());

        return (*this);       
    }    
    
    bool operator==(const BitSet& other) const
    {
        return (equal(m_bits, m_bits + m_word_num, other.m_bits));
    }

    bool operator!=(const BitSet& other) const
    {
        return (!(*this == other));
    }    
    
    BitSet& operator<<=(size_t n_shifts)
    {
        n_shifts = min(Size, n_shifts); 

        size_t word_shifts = n_shifts / BITS_WORD;
        size_t bit_shifts = n_shifts % BITS_WORD;

        // shift words
        copy_backward(m_bits, m_bits + m_word_num - word_shifts, m_bits + m_word_num);
        fill(m_bits, m_bits + word_shifts, 0UL);

        // shift bits
        ShiftLeftByN fun(bit_shifts);
        for_each(m_bits, m_bits+ m_word_num, fun);

        CleanUpPadding();

        return (*this);
    }

    BitSet& operator>>=(size_t n_shifts)
    {
        n_shifts = min(Size, n_shifts); 

        size_t word_shifts = n_shifts / BITS_WORD;
        size_t bit_shifts = n_shifts % BITS_WORD;

        // shift words
        copy(m_bits + word_shifts, m_bits + m_word_num, m_bits);
        fill(m_bits + m_word_num - word_shifts, m_bits + m_word_num,  0UL);

        // shift bits
        reverse_iterator<size_t*> start(m_bits + m_word_num);
        reverse_iterator<size_t*> end(m_bits);
        ShiftRightByN fun(bit_shifts);

        for_each(start, end, fun);
        
        return (*this);
    }
    
 /*************************** Member Functions ****************************/

    BitSet& Set()
    {
        fill(m_bits, m_bits + m_word_num, ~0UL);

        CleanUpPadding();

        return (*this);
    }

    BitSet& Set(size_t index, bool value) // throw out_of_range
    {
        RangeCheck(index);

        size_t val = static_cast<size_t>(value);

        size_t bit_i = index % BITS_WORD;
        size_t set_i = index / BITS_WORD; 

        m_bits[set_i] = ((m_bits[set_i] & ~(1UL << bit_i)) | (val << bit_i));

        return (*this);
    }

    BitSet& Reset()
    {
        fill(m_bits, m_bits + m_word_num, 0UL);
        
        return (*this);
    }

    bool Get(size_t index) const // throw out_of_range
    {
        RangeCheck(index);

        size_t bit_i = index % BITS_WORD;
        size_t set_i = index / BITS_WORD; 

        return ((m_bits[set_i] >> bit_i) & 1UL);
    }

    BitSet& Flip()
    {
        for_each(m_bits, m_bits + m_word_num, FlipWord());
        CleanUpPadding();

        return (*this);
    }

    BitSet& Flip(size_t index) // throw out_of_range
    {
        RangeCheck(index);

        size_t bit_i = index % BITS_WORD;
        size_t set_i = index / BITS_WORD; 

        m_bits[set_i] ^= 1UL << bit_i;

        return (*this);
    }

    size_t CountSetBit() const
    {
        const unsigned char* char_arr = reinterpret_cast<const unsigned char*>(m_bits);

        return (accumulate(char_arr, char_arr + (m_word_num * BYTES_WORD), 0, CountSetBitsInByte()));
    }

    string ToString() const
    {
        reverse_iterator<const size_t*> start(m_bits + m_word_num);
        reverse_iterator<const size_t*> end(m_bits);
        
        WordToString fun;
        fun = for_each(start, end, fun);

        string result = fun.GetResult();

        return (result.substr(pad_size));
    }
    
private:
    static const size_t m_word_num = ((Size - 1) / BITS_WORD) + 1;
    static const size_t pad_size = m_word_num * BITS_WORD - Size;
    
    size_t m_bits[(Size - 1) / BITS_WORD + 1];

    void CleanUpPadding()
    {
        m_bits[m_word_num - 1] <<=  pad_size;
        m_bits[m_word_num - 1] >>=  pad_size;
    }

    void RangeCheck(size_t index) const
    {
        if ( index >= Size)
        {
            throw out_of_range("index out of range");
        }
    }

/********************************** BitProxy Class ************************************/

    class BitProxy
    {
    public:
        BitProxy(BitSet& self, size_t index) : m_bitset(self), m_index(index) { /* empty */ }
        
        BitProxy& operator=(const BitProxy& other)
        {
            m_bitset.Set(m_index, other.m_bitset.Get(other.m_index));
            
            return (*this);
        }

        BitProxy& operator=(const bool b)
        {
            m_bitset.Set(m_index, b);

            return (*this);
        }

        operator bool() const
        {
            return (m_bitset.Get(m_index));
        }
        
    private:
        BitSet& m_bitset;
        size_t m_index;
    }; // BitProxy
}; // BitSet
} // ilrd_166_7
