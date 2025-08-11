#include <iostream> // ostream, istream

using namespace std;

class PointInt
{
public:
    PointInt(const int x = 0) : m_x(x), m_y(x) { cout << "Ctor\n"; } 
    PointInt(const int x, const int y) : m_x(x), m_y(y) { cout << "Ctor\n"; }
    PointInt(const PointInt& other) : m_x(other.m_x), m_y(other.m_y) { cout << "CCtor\n"; }
    ~PointInt() { cout << "Dtor\n"; }  

    int GetX() const { return m_x; }
    int GetY() const { return m_y; }

    // Overloading the + operator using RVO
    PointInt operator+(const PointInt& other) const
    {
        return PointInt(m_x + other.m_x, m_y + other.m_y);  // RVO in action
    }
    /* 
    // use: g++ -fno-elide-constructors | to disable copy elision
    PointInt operator+(const PointInt& other)
    {
        PointInt p(m_x + other.m_x, m_y + other.m_y);

        return (p);
    } 
    */
private:
    int m_x;
    int m_y;
};

/******************************************************************************/

int main()
{
    PointInt p1(1,1);

    p1 = p1 + p1;

    return (0);
}