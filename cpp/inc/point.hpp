#ifndef __ILRD_POINT_HPP__
#define __ILRD_POINT_HPP__

#include <iostream> // ostream, istream
#include <cassert>  // assert

using namespace std;

namespace ilrd_166_7
{
template <typename T>
class Point
{
public:
    Point(const T x = 0) : m_x(x), m_y(x) { /* empty */ } 
    Point(const T x, const T y) : m_x(x), m_y(y) { /* empty */ }

    T GetX() const { return (m_x); }
    T GetY() const { return (m_y); }

    Point& operator+=(const Point& other)
    {
        m_x += other.m_x;
        m_y += other.m_y;

        return (*this);
    }

    Point& operator-=(const Point& other)
    {
        m_x -= other.m_x;
        m_y -= other.m_y;

        return (*this);
    }

    Point& operator*=(const Point& other)
    {
        m_x *= other.m_x;
        m_y *= other.m_y;

        return (*this);
    }

    Point& operator/=(const Point& other)
    {
        assert(other.m_x != 0 && other.m_y != 0);

        m_x /= other.m_x;
        m_y /= other.m_y;

        return (*this);
    }

private:
    T m_x;
    T m_y;
};

template <typename T>
bool operator==(const Point<T>& p1, const Point<T>& p2)
{
    return (p1.GetX() == p2.GetX() && p1.GetY() == p2.GetY());
}

template <typename T>
bool operator!=(const Point<T>& p1, const Point<T>& p2)
{
    return (!(p1 == p2));
}

template <typename T>
const Point<T> operator+(const Point<T>& p1, const Point<T>& p2)
{
    Point<T> p3(p1);

    return (p3 += p2);
}

template <typename T>
const Point<T> operator-(const Point<T>& p1, const Point<T>& p2)
{
    Point<T> p3(p1);

    return (p3 -= p2);
}

template <typename T>
const Point<T> operator*(const Point<T>& p1, const Point<T>& p2)
{
    Point<T> p3(p1);

    return (p3 *= p2);
}

template <typename T>
const Point<T> operator/(const Point<T>& p1, const Point<T>& p2)
{
    Point<T> p3(p1);

    return (p3 /= p2);
}

template <typename T>
ostream& operator<<(ostream& os, const Point<T>& src)
{
    os << "(" << src.GetX() << "," << src.GetY() << ")";
    return (os);
}

template <typename T>
istream& operator>>(istream& is, Point<T>& dst)
{
    T x = 0;
    T y = 0;

	is >> x >> y;
	
    dst = Point<T>(x,y);

    return (is);
}
} // namespace ilrd_166_7

#endif //__ILRD_POINT_HPP__