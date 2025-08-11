#include <iostream> // std
#include <cstring> // strcmp
#include <sstream> // stringstream

#include "simple_string.hpp" // String
#include "test_func.hpp" // CheckValue

using namespace std;
using namespace ilrd_166_7;

/*************************Forward-Declaration*******************************/

static int TestConstructors(void);
static int TestMemberOperators(void);
static int TestMove(void);
static int TestOperatorPlus(void);
static int TestLength(void);
static int TestCStr(void);
static int TestFreeOperators(void);
static int TestStreamOperators(void);
static int TestFoo(void);
static String Foo(String s);

/*******************************Main*************************************/

int main()
{
    int status = 0;

	status += TestConstructors();
	status += TestMemberOperators();
    status += TestMove();
    status += TestOperatorPlus();
	status += TestLength();
    status += TestCStr();
	status += TestFreeOperators();
	status += TestStreamOperators();
    status += TestFoo();
    
    (status == 0) ? (cout << "\033[0;32mAll Good!\033[0m\n") : 
                    (cout << "\033[0;31m" << status << " FAILS! \033[0mTotal\n");

	return (0);
}

/*************************Static-Functions*******************************/

static int TestConstructors(void) 
{
    int status = 0;

	String s1;
	
    status += CheckValue(strcmp(s1.CStr(), ""), 0, "Ctor" , __LINE__);
	
	String s2(s1);
	
    status += CheckValue(strcmp(s2.CStr(), ""), 0, "CCtor" , __LINE__);
    status += CheckValue(strcmp(s1.CStr(), s2.CStr()), 0, "CCtor" , __LINE__);
	
	String s3("This is not a string");
	
	status += CheckValue(strcmp(s3.CStr(), "This is not a string"), 0, "CCtor" , __LINE__);

    return (status);
}

static int TestMemberOperators(void)
{
    int status = 0;

	String s1;
	String s2("This is not a string");
	
	String s3;
	s3 = s1 = s2;
	
    status += CheckValue(strcmp(s1.CStr(), s2.CStr()), 0, "Operator=" , __LINE__);
    status += CheckValue(strcmp(s3.CStr(), s2.CStr()), 0, "Operator=" , __LINE__);

	s1 = "This is a literal";

    status += CheckValue(strcmp("This is a literal", s1.CStr()), 0, "Operator=" , __LINE__);

	String s4("Hello");
    String s6 = s4;

	s4[0] = 'h';

    status += CheckValue(strcmp("hello", s4.CStr()), 0, "Operator[]" , __LINE__);
    status += CheckValue(s4.CStr() == s6.CStr(), false, "Operator[]" , __LINE__);

    return (status);
}

static int TestMove(void)
{
    int status = 0;

    String s1("Hello, World!");
    String s2(move(s1)); 
    
    status += CheckValue(s2 == "Hello, World!", true, "Move Ctor" , __LINE__);
    status += CheckValue(s1.CStr() == NULL, true, "Move Ctor" , __LINE__);
    
    String s3("Original content");
    s3 = move(s2);
    
    status += CheckValue(s3 == "Hello, World!", true, "Move Operator=" , __LINE__);
    status += CheckValue(s2.CStr() == NULL, true, "Move Operator=" , __LINE__);

    return (status);
}

static int TestOperatorPlus(void)
{
    int status = 0;

    String s1("Hello ");
    String s2("World");
    String s3 = s1 + s2;

    status += CheckValue(strcmp(s3.CStr(), "Hello World"), 0, "Operator+" , __LINE__);

    s1 += s2;

    status += CheckValue(strcmp(s1.CStr(), "Hello World"), 0, "Operator+=" , __LINE__);

    return (status);
}

static int TestLength(void)
{
    int status = 0;

	String s1 = "Hello";
    String s2;
	
    status += CheckValue(s1.Length(), 5UL, "Length()" , __LINE__);
    status += CheckValue(s2.Length(), 0UL, "Length()" , __LINE__);

    return (status);
}

static int TestCStr(void)
{
    int status = 0;

	String s1 = "Hello";
	
    status += CheckValue(strcmp(s1.CStr(), "Hello"), 0, "CStr()" , __LINE__);

    return (status);
}

static int TestFreeOperators(void)
{
    int status = 0;

	String s1("Hello");
	String s2("Hello");
    String s3("H");

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

    String s1("Hello");
    stringstream is;
    is << s1;
    
    status += CheckValue(is.str() == "Hello", true, "Operator<<" , __LINE__);

    String s2;
    stringstream os;
    
    os << "Hello";
    os >> s2;
    
    status += CheckValue(strcmp(s2.CStr(), "Hello"), 0, "Operator>>" , __LINE__);

    return (status);
}

static int TestFoo(void)
{
    int status = 0;

    String s1("Hello");

    String s2 = Foo(s1);

    status += CheckValue(strcmp(s1.CStr(), s2.CStr()), 0, "Foo" , __LINE__);

    return (status);
}

static String Foo(String s)
{
    return (s);
}