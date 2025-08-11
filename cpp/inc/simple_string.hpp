#ifndef __ILRD_SIMPLE_STRING_HPP__
#define __ILRD_SIMPLE_STRING_HPP__

#include <cstddef>  // size_t 
#include <iosfwd>   // ostream, istream

namespace ilrd_166_7
{
class String
{
public:
    String(const char* str = "");
    String(const String& other);
    String(String&& other) noexcept;
    ~String();

    String& operator=(const String& other);
    String& operator+=(const String& str);
    char& operator[](size_t index);

    String& operator=(String&& other) noexcept;

    size_t Length() const;
    char* CStr() const;
    
private:
    char* m_buffer;
    char* Duplicate(const char* src, size_t length);
};

String operator+(const String& str1, const String& str2);
bool operator==(const String& str1, const String& str2);
bool operator!=(const String& str1, const String& str2);
bool operator<(const String& str1, const String& str2);
bool operator>(const String& str1, const String& str2);
std::ostream& operator<<(std::ostream& os, const String& src);
std::istream& operator>>(std::istream& is, String& dst);

} // namespace ilrd_166_7

#endif //__ILRD_SIMPLE_STRING_HPP__