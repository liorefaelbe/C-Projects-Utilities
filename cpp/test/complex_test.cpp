#include <iostream> // std
#include <cmath> // abs
#include <cstring> // strcmp
#include <sstream> // stringstream

#include "complex.hpp" // Complex
#include "test_func.hpp" // CheckValue

using namespace std;
using namespace ilrd_166_7;

/*************************Forward-Declaration*******************************/

static int TestConstructors(void);
static int TestGetMagnitude(void);
static int TestGetPhase(void);
static int TestOperatorPlus(void);
static int TestAssignmentOperator(void);
static int TestOperatorMinus(void);
static int TestOperatorMultiply(void);
static int TestOperatorDivide(void);
static int TestOperatorEqual(void);
static int TestOperatorNotEqual(void);
static int TestCout(void);
static int TestCin(void);

/*******************************Main*************************************/

int main()
{
    int status = 0;
    
    status += TestConstructors();
    status += TestGetMagnitude();
    status += TestGetPhase();
    status += TestAssignmentOperator();
    status += TestOperatorPlus();
    status += TestOperatorMinus();
    status += TestOperatorMultiply();
    status += TestOperatorDivide();
    status += TestOperatorEqual();
    status += TestOperatorNotEqual();
    status += TestCout();
    status += TestCin();
    
    (status == 0) ? (cout << "\033[0;32mAll Good!\033[0m\n") : 
                    (cout << "\033[0;31m" << status << " FAILS! \033[0mTotal\n");
    
    return (0);
}

/*****************************Static-Functions******************************/

static int TestConstructors(void) 
{
    int status = 0;
    
	Complex c1;
	
    status += CheckValue(c1.GetReal(), 0.0, "Ctor" , __LINE__);
    status += CheckValue(c1.GetImg(), 0.0, "Ctor" , __LINE__);
	
	Complex c2(c1);
	
    status += CheckValue(c2.GetReal(), 0.0, "CCtor" , __LINE__);
    status += CheckValue(c2.GetImg(), 0.0, "CCtor" , __LINE__);
	
	Complex c3(3.0, 4.0);
	
    status += CheckValue(c3.GetReal(), 3.0, "CCtor" , __LINE__);
    status += CheckValue(c3.GetImg(), 4.0, "CCtor" , __LINE__);
    
    return (status);
}

static int TestGetMagnitude(void)
{
    int status = 0;

    Complex c1(3.0, 4.0);

    status += CheckValue(GetMagnitude(c1), 5.0, "GetMagnitude" , __LINE__);

    return (status);
}

static int TestGetPhase(void)
{
    int status = 0;

    Complex c1(3.0, 4.0);

    status += CheckValue(GetPhase(c1), 0.927295, "GetPhase" , __LINE__);

    return (status);
}

static int TestAssignmentOperator(void)
{
    int status = 0;

    Complex c1(3.0, 4.0);

    Complex c2 = c1;

    status += CheckValue(c2.GetReal(), 3.0, "Operator=" , __LINE__);
    status += CheckValue(c2.GetImg(), 4.0, "Operator=" , __LINE__);

    return (status);
}

static int TestOperatorPlus(void)
{
    int status = 0;

    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex result = c1 + c2;

    status += CheckValue(result.GetReal(), 4.0, "Operator+" , __LINE__);
    status += CheckValue(result.GetImg(), 6.0, "Operator+" , __LINE__);

    c1 += c2;

    status += CheckValue(c1.GetReal(), 4.0, "Operator+=" , __LINE__);
    status += CheckValue(c1.GetImg(), 6.0, "Operator+=" , __LINE__);

    int x = 4;

    c1 += x;

    status += CheckValue(c1.GetReal(), 8.0, "Operator+=" , __LINE__);
    status += CheckValue(c1.GetImg(), 6.0, "Operator+=" , __LINE__);

    char c = '\0';

    c1 += c;

    status += CheckValue(c1.GetReal(), 8.0, "Operator+=" , __LINE__);
    status += CheckValue(c1.GetImg(), 6.0, "Operator+=" , __LINE__);

    return (status);
}

static int TestOperatorMinus(void)
{
    int status = 0;

    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex result = c1 - c2;

    status += CheckValue(result.GetReal(), 2.0, "Operator-" , __LINE__);
    status += CheckValue(result.GetImg(), 2.0, "Operator-" , __LINE__);

    c1 -= c2;

    status += CheckValue(c1.GetReal(), 2.0, "Operator-=" , __LINE__);
    status += CheckValue(c1.GetImg(), 2.0, "Operator-=" , __LINE__);

    return (status);
}

static int TestOperatorMultiply(void)
{
    int status = 0;

    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex result = c1 * c2;

    status += CheckValue(result.GetReal(), -5.0, "Operator*" , __LINE__);
    status += CheckValue(result.GetImg(), 10.0, "Operator*" , __LINE__);

    c1 *= c2;

    status += CheckValue(c1.GetReal(), -5.0, "Operator*=" , __LINE__);
    status += CheckValue(c1.GetImg(), 10.0, "Operator*=" , __LINE__);

    return (status);
}

static int TestOperatorDivide(void)
{
    int status = 0;

    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex result = c1 / c2;

    status += CheckValue(result.GetReal(), 2.2, "Operator/" , __LINE__);
    status += CheckValue(result.GetImg(), -0.4, "Operator/" , __LINE__);

    c1 /= c2;

    status += CheckValue(c1.GetReal(), 2.2, "Operator/=" , __LINE__);
    status += CheckValue(c1.GetImg(), -0.4, "Operator/=" , __LINE__);

    return (status);
}

static int TestOperatorEqual(void)
{
    int status = 0;

    Complex c1(3.0, 4.0);
    Complex c2(3.0, 4.0);
    Complex c3(1.0, 2.0);

    status += CheckValue(c1 == c2, true, "Operator==" , __LINE__);
    status += CheckValue(c1 == c3, false, "Operator==" , __LINE__);

    return (status);
}

static int TestOperatorNotEqual(void)
{
    int status = 0;

    Complex c1(3.0, 4.0);
    Complex c2(3.0, 4.0);
    Complex c3(1.0, 2.0);

    status += CheckValue(c1 != c2, false, "Operator!=" , __LINE__);
    status += CheckValue(c1 != c3, true, "Operator!=" , __LINE__);

    return (status);
}

static int TestCout(void)
{
    int status = 0;
    
    Complex c1(3.0, 4.0);
    std::stringstream ss;

    ss << c1;
    
    status += CheckValue(ss.str() == "3 + 4i", true, "Operator<<" , __LINE__);
    
    return (status);
}

static int TestCin(void)
{
    int status = 0;
    
    Complex c1(3.0, 4.0);
    std::stringstream ss;
    
    ss << "3.42-4.33i";
    ss >> c1;
    
    status += CheckValue(c1.GetReal(), 3.42, "Operator>>" , __LINE__);
    status += CheckValue(c1.GetImg(), -4.33, "Operator>>" , __LINE__);
    
    return (status);
}