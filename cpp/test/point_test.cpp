#include <iostream>         // std
#include <sstream>          // stringstream
#include <cstring>          // strcmp

#include "point.hpp"        // Point<int>
#include "test_func.hpp"    // CheckValue

using namespace std;
using namespace ilrd_166_7;

/*************************Forward-Declaration*******************************/

static int TestConstructors(void);
static int TestAssignmentOperator(void);
static int TestOperatorPlus(void);
static int TestOperatorMinus(void);
static int TestOperatorMultiply(void);
static int TestOperatorDivide(void);
static int TestOperatorEqual(void);
static int TestOperatorNotEqual(void);
static int TestCout(void);
static int TestCin(void);

/*******************************Main****************************************/

int main()
{
    int status = 0;
    
    status += TestConstructors();
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
    
	Point<int> p1;
	
    status += CheckValue(p1.GetX(), 0, "Ctor" , __LINE__);
    status += CheckValue(p1.GetY(), 0, "Ctor" , __LINE__);
	
	Point<int> p2(p1);
	
    status += CheckValue(p2.GetX(), 0, "CCtor" , __LINE__);
    status += CheckValue(p2.GetY(), 0, "CCtor" , __LINE__);
	
	Point<int> p3(3, 4);
	
    status += CheckValue(p3.GetX(), 3, "CCtor" , __LINE__);
    status += CheckValue(p3.GetY(), 4, "CCtor" , __LINE__);
    
    return (status);
}

static int TestAssignmentOperator(void)
{
    int status = 0;

    Point<int> p1(3, 4);

    Point<int> p2 = p1;

    status += CheckValue(p2.GetX(), 3, "Operator=" , __LINE__);
    status += CheckValue(p2.GetY(), 4, "Operator=" , __LINE__);

    return (status);
}

static int TestOperatorPlus(void)
{
    int status = 0;

    Point<int> p1(3, 4);
    Point<int> p2(1, 2);
    Point<int> result = p1 + p2;

    status += CheckValue(result.GetX(), 4, "Operator+" , __LINE__);
    status += CheckValue(result.GetY(), 6, "Operator+" , __LINE__);

    p1 += p2;

    status += CheckValue(p1.GetX(), 4, "Operator+=" , __LINE__);
    status += CheckValue(p1.GetY(), 6, "Operator+=" , __LINE__);

    int x = 4;

    p1 += x;

    status += CheckValue(p1.GetX(), 8, "Operator+=" , __LINE__);
    status += CheckValue(p1.GetY(), 10, "Operator+=" , __LINE__);

    return (status);
}

static int TestOperatorMinus(void)
{
    int status = 0;

    Point<int> p1(3, 4);
    Point<int> p2(1, 2);
    Point<int> result = p1 - p2;

    status += CheckValue(result.GetX(), 2, "Operator-" , __LINE__);
    status += CheckValue(result.GetY(), 2, "Operator-" , __LINE__);

    p1 -= p2;

    status += CheckValue(p1.GetX(), 2, "Operator-=" , __LINE__);
    status += CheckValue(p1.GetY(), 2, "Operator-=" , __LINE__);

    return (status);
}

static int TestOperatorMultiply(void)
{
    int status = 0;

    Point<int> p1(3, 4);
    Point<int> p2(1, 2);
    Point<int> result = p1 * p2;

    status += CheckValue(result.GetX(), 3, "Operator*" , __LINE__);
    status += CheckValue(result.GetY(), 8, "Operator*" , __LINE__);

    p1 *= p2;

    status += CheckValue(p1.GetX(), 3, "Operator*=" , __LINE__);
    status += CheckValue(p1.GetY(), 8, "Operator*=" , __LINE__);

    return (status);
}

static int TestOperatorDivide(void)
{
    int status = 0;

    Point<int> p1(8, 4);
    Point<int> p2(1, 2);
    Point<int> result = p1 / p2;

    status += CheckValue(result.GetX(), 8, "Operator/" , __LINE__);
    status += CheckValue(result.GetY(), 2, "Operator/" , __LINE__);

    p1 /= 2;

    status += CheckValue(p1.GetX(), 4, "Operator/=" , __LINE__);
    status += CheckValue(p1.GetY(), 2, "Operator/=" , __LINE__);

    return (status);
}

static int TestOperatorEqual(void)
{
    int status = 0;

    Point<int> p1(3, 4);
    Point<int> p2(3, 4);
    Point<int> p3(1, 2);

    status += CheckValue(p1 == p2, true, "Operator==" , __LINE__);
    status += CheckValue(p1 == p3, false, "Operator==" , __LINE__);

    return (status);
}

static int TestOperatorNotEqual(void)
{
    int status = 0;

    Point<int> p1(3, 4);
    Point<int> p2(3, 4);
    Point<int> p3(1, 2);

    status += CheckValue(p1 != p2, false, "Operator!=" , __LINE__);
    status += CheckValue(p1 != p3, true, "Operator!=" , __LINE__);

    return (status);
}

static int TestCout(void)
{
    int status = 0;
    
    Point<int> p1(3,4);
    std::stringstream ss;

    ss << p1;
    
    status += CheckValue(ss.str() == "(3,4)", true, "Operator<<" , __LINE__);

    return (status);
}

static int TestCin(void)
{
    int status = 0;
    
    Point<int> p1(3,4);
    std::stringstream ss;
    
    ss << "5 1";
    ss >> p1;
    
    status += CheckValue(p1.GetX(), 5, "Operator>>" , __LINE__);
    status += CheckValue(p1.GetY(), 1, "Operator>>" , __LINE__);
    
    return (status);
}