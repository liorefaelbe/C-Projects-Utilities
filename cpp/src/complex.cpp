/*
	Author: Lior Refael Berkovits
	Reviewed by: Ella
	Date: 10/03/2025
*/

#include <iostream> // ostream, istream
#include <cmath> 	// sqrt, atan2
#include <cassert> 	// assert

#include "complex.hpp"

using namespace std;
namespace ilrd_166_7
{

/***********************************Constractors****************************************************/

Complex::Complex(double real_, double img_) : real(real_), img(img_){}

/***********************************Member Functions************************************************/

Complex& Complex::operator+=(const Complex& other)
{
	real += other.real;
	img += other.img;

	return (*this);
}

Complex& Complex::operator-=(const Complex& other)
{
	real -= other.real;
	img -= other.img;

	return (*this);
}

Complex& Complex::operator*=(const Complex& other)
{
	double a = real;
	double b = img;
	double c = other.real;
	double d = other.img;

	this->real = ((a * c) - (b * d));
	this->img = ((a * d) + (b * c));

	return (*this);
}

Complex& Complex::operator/=(const Complex& other)
{
	double a = real;
    double b = img;
    double c = other.real;
    double d = other.img;

	assert(0 != (c * c) + (d * d));

	this->real = ((a * c) + (b * d)) / ((c * c) + (d * d));
	this->img = ((b * c) - (a * d)) / ((c * c) + (d * d));

	return (*this);
}

double Complex::GetReal() const
{
	return (real);
}

double Complex::GetImg() const
{
	return (img);
}

/***************************************Free functions**********************************************/

double GetMagnitude(const Complex& num)
{
	return (sqrt(pow(num.GetReal(), 2) + pow(num.GetImg(), 2)));
}

double GetPhase(const Complex& num)
{
	return (atan2(num.GetImg(), num.GetReal()));
}

/*****************************************Operators*************************************************/

const Complex operator+(const Complex& num1, const Complex& num2)
{
	Complex num(num1);

	return (num += num2);
}

const Complex operator-(const Complex& num1, const Complex& num2)
{
	Complex num(num1);

	return (num -= num2);
}

const Complex operator*(const Complex& num1, const Complex& num2)
{
	Complex num(num1);

	return (num *= num2);
}

const Complex operator/(const Complex& num1, const Complex& num2)
{
	Complex num(num1);

	return (num /= num2);
}

bool operator==(const Complex& num1, const Complex& num2)
{
	double e = 0.0001;

	return ((num1.GetReal() - num2.GetReal()) < e) && ((num1.GetImg() - num2.GetImg()) < e);
}

bool operator!=(const Complex& num1, const Complex& num2)
{
	return (!(num1 == num2));
}

std::ostream& operator<<(std::ostream& os, const Complex& num)
{
	char sign = (num.GetImg() > 0) ? '+' : '-';

	if(num.GetReal() != 0 || num.GetImg() == 0)
	{
		os << num.GetReal();
	}

	if(num.GetImg() != 0)
	{
		os << " " << sign << " " << abs(num.GetImg()) << "i";
	}

    return (os);
}

std::istream& operator>>(std::istream& is, Complex& num)
{
    double real = 0;
    double img = 0;

	is >> real >> img;
	
    num = Complex(real,img);

    return (is);
}
} // namespace ilrd_166_7