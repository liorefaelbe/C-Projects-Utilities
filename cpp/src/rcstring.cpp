/*
	Author: Lior Refael Berkovits
	Reviewed by: Maor
	Date: 13/03/2025
*/

#include <cstring> // strlen, memcpy
#include <cstdio> // new, delete
#include <iostream> // ostream, istream

#include "rcstring.hpp" // RCString

using namespace std;
namespace ilrd_166_7
{

static const size_t buffer_offset = offsetof(RCSData, m_buffer);

/***********************************Constractors****************************************************/

RCString::RCString(const char* str):m_data(Duplicate(str, strlen(str) + 1))
{
    //empty Ctor
}

RCString::RCString(const RCString& other):m_data(Copy(other.m_data))
{
    //empty CCtor
}

RCString::~RCString()
{
    if(m_data->ref_counter > 1)
    {
        --(m_data->ref_counter);
    }
    else
    {
        operator delete(m_data);
        m_data = NULL;
    }
}

/***********************************Member-Functions************************************************/

size_t RCString::Length() const
{
    return (strlen(m_data->m_buffer)); 
}

const char* RCString::CStr() const
{
    return (m_data->m_buffer);
}

RCSData* RCString::Duplicate(const char* src, size_t length)
{
    m_data = static_cast<RCSData*>(operator new(buffer_offset + length));

    memcpy(m_data->m_buffer, src, length);
    m_data->ref_counter = 1;

    return (m_data);
}

RCSData* RCString::Copy(RCSData* data)
{
    m_data = data;
    ++(m_data->ref_counter);

    return (m_data);
}

/*****************************************Operators*************************************************/

RCString& RCString::operator=(const RCString& other)
{
    RCString tmp(other);

    swap(this->m_data, tmp.m_data);

    return (*this);
}

char RCString::operator[](size_t index) const
{
    return (m_data->m_buffer[index]);
}

char& RCString::operator[](size_t index)
{
    if(m_data->ref_counter > 1)
    {
        RCString new_s(m_data->m_buffer);
        *this = new_s;
    }

    return (m_data->m_buffer[index]);
}

bool operator==(const RCString& str1, const RCString& str2)
{
    return (!strcmp(str1.CStr(), str2.CStr()));
}

bool operator!=(const RCString& str1, const RCString& str2)
{
    return (strcmp(str1.CStr(), str2.CStr()));
}

bool operator<(const RCString& str1, const RCString& str2)
{
    return (strcmp(str1.CStr(), str2.CStr()) < 0);
}

bool operator>(const RCString& str1, const RCString& str2)
{
    return (strcmp(str1.CStr(), str2.CStr()) > 0);
}

std::ostream& operator<<(std::ostream& os, const RCString& src)
{
    return (os << src.CStr());
}

std::istream& operator>>(std::istream& is, RCString& dst)
{
    char tmp[BUFSIZ] = {0};
    is >> tmp;

    dst = RCString(tmp);

    return (is);
}
} // namespace ilrd_166_7