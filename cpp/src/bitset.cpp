#include <string>      // string

#include "bitset.hpp"  // Functors

/***************************** LUT ****************************/

namespace ilrd_166_7
{
const unsigned char BIT_COUNT_LUT[256] = 
{
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8
};

/************************** Functors **************************/

void FlipWord::operator()(size_t& word)
{
    word ^= ~0;
}

size_t CountSetBitsInByte::operator()(size_t sum, unsigned char byte) const
{
    return (sum + BIT_COUNT_LUT[byte]);
}

void WordToString::operator()(size_t word)
{
    for (size_t i = 0; i < BITS_WORD; ++i)
    {
        m_result += ((word >> (BITS_WORD - 1 - i)) & 1) ? '1' : '0';
    }
} 

string& WordToString::GetResult() 
{ 
    return (m_result); 
}

ShiftRightByN::ShiftRightByN(size_t shifts) : m_shifts(shifts), m_carry(0) { /* empty */ }

void ShiftRightByN::operator()(size_t& word)
{
    size_t carry = m_carry;

    size_t carry_mask = ~0UL >> (BITS_WORD - m_shifts);
    m_carry = (carry_mask & word) << (BITS_WORD - m_shifts);

    word >>= m_shifts;
    word |= carry;
}

ShiftLeftByN::ShiftLeftByN(size_t shifts) : m_shifts(shifts), m_carry(0) { /* empty */ }

void ShiftLeftByN::operator()(size_t& word)
{
    size_t carry = m_carry;

    size_t carry_mask = ~0UL << (BITS_WORD - m_shifts);
    m_carry = (carry_mask & word) >> (BITS_WORD - m_shifts);

    word <<= m_shifts;
    word |= carry;
}
} // ilrd_166_7