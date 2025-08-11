#ifndef __ILRD_RCSTRING_HPP__
#define __ILRD_RCSTRING_HPP__

#include <cstddef>  // size_t
#include <iosfwd>   // ostream, istream

namespace ilrd_166_7
{
struct RCSData
{
    size_t ref_counter;
    char m_buffer[1];
};

class RCString
{
public:
    RCString(const char* str = ""); // not explicit
    RCString(const RCString& other);
    ~RCString();

    RCString& operator=(const RCString& other);
    char operator[](size_t index) const;
    char& operator[](size_t index);
    
    const char* CStr() const;
    size_t Length() const;

private:
    RCSData* m_data; 
    RCSData* Duplicate(const char* src, size_t length);
    RCSData* Copy(RCSData* data);
};

bool operator==(const RCString& str1, const RCString& str2);
bool operator!=(const RCString& str1, const RCString& str2);
bool operator<(const RCString& str1, const RCString& str2);
bool operator>(const RCString& str1, const RCString& str2);
std::ostream& operator<<(std::ostream& os, const RCString& src);
std::istream& operator>>(std::istream& is, RCString& dst);

} // namespace ilrd_166_7

#endif //__ILRD_RCSTRING_HPP__