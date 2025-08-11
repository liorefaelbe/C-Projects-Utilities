#ifndef __ILRD_SHAPES_H__
#define __ILRD_SHAPES_H__

#include <iostream> // ostream, istream
#include <string>   // string
#include <cmath>    // M_PI

using namespace std;

namespace ilrd_166_7
{
class Shape
{
public:
    virtual void Draw(void) = 0;
    void Move(void) { m_pos += "\t"; }
    string GetPos(void) { return (m_pos); }
private:
    string m_pos;
};

/*******************************************************************************/

class OpenShape : public Shape
{
public:
    virtual double GetLength(void) = 0;
};

class Line : public OpenShape
{
public:
    virtual void Draw(void) { cout << GetPos() << "➖\n"; }
    double GetLength(void) { return (m_len); };
    void SetLine(double len = 1.0) { m_len = len; };
private:
    double m_len;
};

/*******************************************************************************/

class CloseShape : public Shape
{
public:
    virtual double GetArea(void) = 0;
};

class Circle : public CloseShape
{
public:
    virtual void Draw(void) { cout << GetPos() << "🟢\n"; }
    double GetArea(void) { return (M_PI * m_r * m_r); };
    double GetCircumference(void) { return (2 * M_PI * m_r); };
    void SetCircle(double r = 1.0) { m_r = r; };
private:
    double m_r;
};

class Triangle : public CloseShape
{
public:
    virtual void Draw(void) { cout << GetPos() << "🔺\n"; }
    double GetSideSum(void) { return (m_a + m_b + m_c); };
    void SetTriangle(double a = 1.0, double b = 1.0, double c = 1.0) { m_a = a; m_b = b; m_c = c;};
    double GetArea(void)
    { 
        double s = (m_a + m_b + m_c) / 2;
        return (sqrt((s - m_a) * (s - m_b) * (s - m_c)));
    };
private:
    double m_a;
    double m_b;
    double m_c;
};

class Square : public CloseShape
{
    public:
    virtual void Draw(void) { cout << GetPos() << "🟧\n"; }
    double GetArea(void) { return (m_a * m_a); };
    double GetSideSum(void) { return (m_a * 4); };
    void SetSquare(double a = 1.0) { m_a = a;};
private:
    double m_a;
};

class Rectangle : public CloseShape
{
    public:
    virtual void Draw(void) { cout << GetPos() << "🟦🟦\n"; }
    double GetArea(void) { return (m_a * m_b); };
    double GetSideSum(void) { return (m_a * 2 + m_b * 2); };
    void SetRectangle(double a = 1.0, double b = 1.0) { m_a = a; m_b = b;};
private:
    double m_a;
    double m_b;
};

void Foo(void);

} // namespace ilrd_166_7

#endif // __ILRD_SHAPES_H__