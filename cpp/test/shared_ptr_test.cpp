#include <iostream>         // std
#include <cstring>          // strcmp                  

#include "shared_ptr.hpp"   // SharedPtr
#include "shapes.hpp"       // Shape
#include "test_func.hpp"    // CheckValue

using namespace std;
using namespace ilrd_166_7;

class Base
{
public:
    int m_i;
};
class Derived : public Base
{
public:
    int m_s;
};
class NotDerived
{
public:
    int m_a;
};

/*************************Forward-Declaration*******************************/

static int TestInt(void);
static int TestConstructors(void);
static int TestOperators(void);

/*******************************Main*************************************/

int main()
{
    int status = 0;

    status += TestInt();
    status += TestConstructors();
    status += TestOperators();
    
    (status == 0) ? (cout << "\033[0;32mAll Good!\033[0m\n") : 
                    (cout << "\033[0;31m" << status << " FAILS! \033[0mTotal\n");

	return (0);
}

/*************************Static-Functions*******************************/

static int TestInt(void) 
{
    int status = 0;

    SharedPtr<int> s_ptr1(new int(1));
    SharedPtr<int> s_ptr2(new int(2));
    
    status += CheckValue(s_ptr1.GetUseCount(), 1UL, "Ctor" , __LINE__);
    status += CheckValue(s_ptr2.GetUseCount(), 1UL, "Ctor" , __LINE__);

    SharedPtr<int> s_ptr3(s_ptr2);

    status += CheckValue(s_ptr3.GetUseCount(), 2UL, "CCtor" , __LINE__);

    s_ptr1 = s_ptr2;

    status += CheckValue(s_ptr1.GetUseCount(), 3UL, "Operator=" , __LINE__);
    status += CheckValue(s_ptr2.GetUseCount(), 3UL, "Operator=" , __LINE__);

    *s_ptr1 = 5;

    status += CheckValue(*s_ptr1, 5, "Operator*" , __LINE__);

    *s_ptr2 = 4;

    status += CheckValue(*s_ptr1, 4, "Operator*" , __LINE__);
    status += CheckValue(*s_ptr2, 4, "Operator*" , __LINE__);

    status += CheckValue(s_ptr1.GetUseCount(), 3UL, "GetUseCount" , __LINE__);
    status += CheckValue(s_ptr2.GetUseCount(), 3UL, "GetUseCount" , __LINE__);

    return (status);
}

static int TestConstructors(void) 
{
    int status = 0;

    SharedPtr<Base> s_b_ptr1(new Base);
    SharedPtr<Derived> s_d_ptr1(new Derived);

    status += CheckValue(s_b_ptr1.GetUseCount(), 1UL, "Ctor" , __LINE__);
    status += CheckValue(s_d_ptr1.GetUseCount(), 1UL, "Ctor" , __LINE__);

    // SharedPtr<Derived>* s_d_ptr3 = new SharedPtr<Derived>;
    // SharedPtr<NotDerived> s_nd_ptr(s_d_ptr1);

    SharedPtr<Derived> s_d_ptr2(s_d_ptr1);
    SharedPtr<Base> s_b_ptr2(s_d_ptr2);

    status += CheckValue(s_d_ptr2.GetUseCount(), 3UL, "CmoptCtor" , __LINE__);
    status += CheckValue(s_b_ptr2.GetUseCount(), 3UL, "CmoptCtor" , __LINE__);

    return (status);
}

static int TestOperators(void)
{
    int status = 0;

    SharedPtr<Derived> s_d_ptr1(new Derived);

    SharedPtr<Derived> s_d_ptr2 = s_d_ptr1;

    status += CheckValue(s_d_ptr1.GetUseCount(), 2UL, "Operator=" , __LINE__);
    status += CheckValue(s_d_ptr2.GetUseCount(), 2UL, "Operator=" , __LINE__);

    SharedPtr<Base> s_b_ptr1 = s_d_ptr1;

    status += CheckValue(s_d_ptr1.GetUseCount(), 3UL, "Operator=" , __LINE__);
    status += CheckValue(s_b_ptr1.GetUseCount(), 3UL, "Operator=" , __LINE__);

    s_b_ptr1->m_i = 5;

    status += CheckValue(s_b_ptr1->m_i, 5, "Operator->" , __LINE__);
    status += CheckValue(s_b_ptr1->m_i, s_d_ptr1->m_i, "Operator->" , __LINE__);

    (*s_b_ptr1).m_i = 3;

    status += CheckValue((*s_b_ptr1).m_i, 3, "Operator*" , __LINE__);

    return (status);
}