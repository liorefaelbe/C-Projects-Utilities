#ifndef __ILRD_BIT_ARRAY_HPP__
#define __ILRD_BIT_ARRAY_HPP__

#include <cstddef>  // size_t

namespace ilrd_166_7
{
class BitArr
{
private:
    class BitProxy;
public:
    explicit BitArr();
    //~BitArr(); generated
    //BitArr& operator=(const BitArr& other); generated
    
    bool operator[](size_t index) const; 
    BitProxy operator[](size_t index);
private:
    size_t m_bitmap;
    
    class BitProxy
    {
    public:
        BitProxy(BitArr& self, const size_t index);
        ~BitProxy();
        
        BitArr::BitProxy& operator=(const BitProxy& other);
        BitArr::BitProxy& operator=(const bool b);
        operator bool() const;
    private:
        BitArr& m_bitarr;
        size_t m_index;
    };
};
} // namespace ilrd_166_7

#endif //__ILRD_BIT_ARRAY_HPP__