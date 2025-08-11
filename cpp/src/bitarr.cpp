/*
	Author: Lior Refael Berkovits
	Reviewed by: Avi
	Date: 10/04/2025
*/

#include <iostream>     // out_of_range

#include "bitarr.hpp"   // BitArr

static const size_t bit_num = (sizeof(size_t) * 8);

using namespace std;
namespace ilrd_166_7
{

/********************************Forward-Declaration************************************************/

static size_t SetBit(size_t bitmap, const size_t index, const int value);

// BitArr
/***********************************Constractors****************************************************/

BitArr::BitArr() : m_bitmap(0) { /* empty */ }
  
/*************************************Operators*****************************************************/

bool BitArr::operator[](size_t index) const
{
    if (index >= bit_num)
    {
        throw out_of_range("Index out of range");
    }
    
    return ((m_bitmap >> index) & 1);
}

BitArr::BitProxy BitArr::operator[](size_t index)
{
    if (index >= bit_num)
    {
        throw out_of_range("Index out of range");
    }

    return (BitArr::BitProxy(*this, index));
}

// BitProxy
/***********************************Constractors****************************************************/

BitArr::BitProxy::BitProxy(BitArr& self, const size_t index) : m_bitarr(self), m_index(index) { /* empty */ }

BitArr::BitProxy::~BitProxy() { /* empty */ }
        
/*************************************Operators*****************************************************/

BitArr::BitProxy& BitArr::BitProxy::operator=(const BitProxy& other)
{
    m_bitarr.m_bitmap = SetBit(m_bitarr.m_bitmap, m_index, other);

    return (*this);
}

BitArr::BitProxy& BitArr::BitProxy::operator=(const bool b)
{   
    m_bitarr.m_bitmap = SetBit(m_bitarr.m_bitmap, m_index, b);

    return (*this);
}

BitArr::BitProxy::operator bool() const
{
    return ((m_bitarr.m_bitmap >> m_index) & 1);
}

/**********************************Static-Functions*************************************************/

static size_t SetBit(size_t bitmap, const size_t index, const int value)
{
	if (value == 1)
	{
		return (bitmap | (1UL << index));
	}
	else if (value == 0)
	{
		return (bitmap & ~(1UL << index));
	}

    return (bitmap);
}
}