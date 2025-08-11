#include <iostream> // std
#include <cstring> // strcmp
#include <sstream> // stringstream

#include "rcstring.hpp" // RCString
#include "test_func.hpp" // CheckValue

using namespace std;
using namespace ilrd_166_7;

/*************************Forward-Declaration*******************************/

static int TestConstructors(void);
static int TestMemberOperators(void);
static int TestLength(void);
static int TestCStr(void);
static int TestFreeOperators(void);
static int TestStreamOperators(void);

/*******************************Main*************************************/

int main()
{
    int status = 0;

	status += TestConstructors();
	status += TestMemberOperators();
	status += TestLength();
    status += TestCStr();
	status += TestFreeOperators();
	status += TestStreamOperators();
     
    (status == 0) ? (cout << "\033[0;32mAll Good!\033[0m\n") : 
                    (cout << "\033[0;31m" << status << " FAILS! \033[0mTotal\n");

	return (0);
}

/*************************Static-Functions*******************************/

static int TestConstructors(void) 
{
    int status = 0;

	RCString s1;
	
    status += CheckValue(strcmp(s1.CStr(), ""), 0, "Ctor" , __LINE__);
	
	RCString s2(s1);
	
    status += CheckValue(strcmp(s2.CStr(), ""), 0, "CCtor" , __LINE__);
    status += CheckValue(strcmp(s1.CStr(), s2.CStr()), 0, "CCtor" , __LINE__);
    status += CheckValue(s1.CStr(), s2.CStr(), "CCtor" , __LINE__);
	
	RCString s3("This is not a string");
	
	status += CheckValue(strcmp(s3.CStr(), "This is not a string"), 0, "CCtor" , __LINE__);

    return (status);
}

static int TestMemberOperators(void)
{
    int status = 0;

	RCString s1;
	RCString s2("This is not a string");
	
	RCString s3;
	s3 = s1 = s2;
	
    status += CheckValue(strcmp(s1.CStr(), s2.CStr()), 0, "Operator=" , __LINE__);
    status += CheckValue(strcmp(s3.CStr(), s2.CStr()), 0, "Operator=" , __LINE__);
    status += CheckValue(s1.CStr(), s2.CStr(), "Operator=" , __LINE__);
    status += CheckValue(s3.CStr(), s2.CStr(), "Operator=" , __LINE__);
    status += CheckValue(s2.CStr(), s3.CStr(), "Operator=" , __LINE__);

	s1 = "This is a literal";

    status += CheckValue(strcmp("This is a literal", s1.CStr()), 0, "Operator=" , __LINE__);

	RCString s4("Hello");
    RCString s6 = s4;

	s4[0] = 'h';

    status += CheckValue(strcmp("hello", s4.CStr()), 0, "Operator[]" , __LINE__);
    status += CheckValue(s4.CStr() == s6.CStr(), false, "Operator[]" , __LINE__);

    s4 = s4;

    status += CheckValue(s4.CStr() == s6.CStr(), false, "Operator[]" , __LINE__);

    const RCString s5 = "Hello";
    RCString s7 = s5;
	char c = s5[1];

	status += CheckValue(c, s5[1], "Operator[] const" , __LINE__);
    status += CheckValue(s5.CStr() == s7.CStr(), true, "Operator[]" , __LINE__);

    return (status);
}

static int TestLength(void)
{
    int status = 0;

	RCString s1 = "Hello";
    RCString s2;
	
    status += CheckValue(s1.Length(), 5UL, "Length()" , __LINE__);
    status += CheckValue(s2.Length(), 0UL, "Length()" , __LINE__);

    return (status);
}

static int TestCStr(void)
{
    int status = 0;

	RCString s1 = "Hello";
	
    status += CheckValue(strcmp(s1.CStr(), "Hello"), 0, "CStr()" , __LINE__);

    return (status);
}

static int TestFreeOperators(void)
{
    int status = 0;

	RCString s1("Hello");
	RCString s2("Hello");
    RCString s3("H");

	status += CheckValue(s1 == s2, true, "Operator==" , __LINE__);
    status += CheckValue(s1 == s3, false, "Operator==" , __LINE__);
    status += CheckValue("Hello" == s2, true, "Operator==" , __LINE__);
    status += CheckValue(s1 == "H", false, "Operator==" , __LINE__);

    status += CheckValue(s1 != s2, false, "Operator!=" , __LINE__);
    status += CheckValue(s1 != s3, true, "Operator!=" , __LINE__);
    status += CheckValue("Hello" != s2, false, "Operator!=" , __LINE__);
    status += CheckValue(s1 != "H", true, "Operator!=" , __LINE__);

    status += CheckValue(s1 > s2, false, "Operator>" , __LINE__);
    status += CheckValue(s1 > s3, true, "Operator>" , __LINE__);
    status += CheckValue("Hello" > s2, false, "Operator>" , __LINE__);
    status += CheckValue(s1 > "H", true, "Operator>" , __LINE__);

    status += CheckValue(s1 < s2, false, "Operator<" , __LINE__);
    status += CheckValue(s1 < s3, false, "Operator<" , __LINE__);
    status += CheckValue("Hello" < s2, false, "Operator<" , __LINE__);
    status += CheckValue(s1 < "H", false, "Operator<" , __LINE__);

	return (status);
}

static int TestStreamOperators(void)
{
    int status = 0;

    RCString s1("Hello");
    std::stringstream is;
    is << s1;
    
    status += CheckValue(is.str() == "Hello", true, "Operator<<" , __LINE__);

    RCString s2;
    std::stringstream os;
    
    os << "Hello";
    os >> s2;
    
    status += CheckValue(strcmp(s2.CStr(), "Hello"), 0, "Operator>>" , __LINE__);

    return (status);
}