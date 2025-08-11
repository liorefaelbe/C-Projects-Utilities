/*
	Author: Lior Refael Berkovits
	Reviewed by: Alex
	Date: 05/03/2025
*/

#include <cstring> // strlen, memcpy
#include <cstdio> // new, delete
#include <iostream> // ostream, istream

#include "simple_string.hpp"

using namespace std;
namespace ilrd_166_7
{

/***********************************Constractors****************************************************/

String::String(const char* str):m_buffer(Duplicate(str, strlen(str) + 1))
{
    //empty Ctor
}

String::String(const String& other):m_buffer(Duplicate(other.m_buffer, strlen(other.m_buffer) + 1))
{
    //empty CCtor
}

String::String(String&& other) noexcept : m_buffer(other.m_buffer) 
{
    other.m_buffer = NULL;
}

String::~String()
{
    delete[] m_buffer;
}

/***********************************Member Functions************************************************/

size_t String::Length() const
{
    return (strlen(m_buffer));
}

char* String::CStr() const
{
    return (m_buffer);
}

char* String::Duplicate(const char* src, size_t length)
{
    m_buffer = new char[length];
    memcpy(m_buffer, src, length);
    
    return (m_buffer);
}

/***************************************Operators***************************************************/

String& String::operator=(const String& other)
{
    String tmp(other);

    swap(m_buffer, tmp.m_buffer);

    return (*this);
}

String& String::operator+=(const String& str)
{
    size_t length = Length() + str.Length() + 1;
    char* tmp = new char[length];

    memcpy(tmp, m_buffer, Length() + 1);
    strcat(tmp, str.CStr());
    
    *this = String(tmp);
    delete[] tmp;

    return (*this);
}

char& String::operator[](size_t index)
{
    return (m_buffer[index]);
}

String& String::operator=(String&& other) noexcept
{
    if (this != &other) 
    {
        delete[] m_buffer;
        m_buffer = other.m_buffer;
        other.m_buffer = NULL;
    }

    return (*this);
}

String operator+(const String& str1, const String& str2)
{
    String s(str1);

	return (s += str2);
}

bool operator==(const String& str1, const String& str2)
{
    return (!strcmp(str1.CStr(), str2.CStr()));
}

bool operator!=(const String& str1, const String& str2)
{
    return (strcmp(str1.CStr(), str2.CStr()));
}

bool operator<(const String& str1, const String& str2)
{
    return (strcmp(str1.CStr(), str2.CStr()) < 0);
}

bool operator>(const String& str1, const String& str2)
{
    return (strcmp(str1.CStr(), str2.CStr()) > 0);
}

std::ostream& operator<<(std::ostream& os, const String& src)
{
    return (os << src.CStr());
}

std::istream& operator>>(std::istream& is, String& dst)
{
    char tmp[BUFSIZ] = {0};
    is >> tmp;

    dst = String(tmp);

    return (is);
}
} // namespace ilrd_166_7