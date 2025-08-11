#ifndef __ILRD_COMPLEX_HPP__
#define __ILRD_COMPLEX_HPP__

#include <iosfwd> // ostream, istream

namespace ilrd_166_7
{
class Complex
{
public:
    Complex(double real = 0.0, double img = 0.0); // non explicit by design
    
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator/=(const Complex& other);
    Complex& operator*=(const Complex& other);

    double GetReal() const;
    double GetImg() const;
    
private:
    double real;
    double img;
};

double GetMagnitude(const Complex& num);
double GetPhase(const Complex& num);

const Complex operator+(const Complex& num1, const Complex& num2);
const Complex operator-(const Complex& num1, const Complex& num2);
const Complex operator*(const Complex& num1, const Complex& num2);
const Complex operator/(const Complex& num1, const Complex& num2);

bool operator==(const Complex& num1, const Complex& num2);
bool operator!=(const Complex& num1, const Complex& num2);

std::ostream& operator<<(std::ostream& os, const Complex& num);
std::istream& operator>>(std::istream& is, Complex& num);

} //ilrd_166_7

#endif //__ILRD_COMPLEX_HPP__