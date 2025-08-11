#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*q2 - enum 
enum E {AA,BB,CC,DD};
enum E2 {TT,KK};
enum E e = AA;
enum E2 e2 = KK;
E2 e22 = KK;
++e;
const int i = e;*/

/*q3 - bool
bool b;
int main()
{
	bool b1 = false;
	bool b2;
	bool b3;
	int i = b1;
	i = 7;
	b2 = i;
	printf("%d\n", b);
	printf("%d\n", b1);
	printf("%d\n", b2);
	printf("%d\n", b3);
	printf("%ld\n", sizeof(b2));
}*/

/*q4 - casting
typedef struct person
{
	int age;
}person_t;

typedef struct list
{
	person_t* lior;
}list_t;

void* ll_find(list_t* ll, int key)
{
	return (ll->lior);
}

void foo(list_t* ll, int key, int age)
{
	void* vv = ll_find(ll, key);
	person_t* p = static_cast<person_t*>(ll);
	p->age = age;
}

int main()
{
	list_t list = {0};
	person_t p = {0};
	p.age = 32;
	list.lior = &p;

	foo(&list, 1, 22);

	printf("%d\n", list.lior->age);

	return (0);
}*/

/*q5 - Function declarations 
int main()
{
	//foo();
	printf(6,5);
	return (0);
}*/

/*q6 - Local variables definations 
int main()
{
	int x = 0;

	x += 34;

	int y = 45;
	printf("%d",y);
	return (0);
}*/

/*q7 - Operators new and delete
int main()
{
	float* f = new float(12.6);
	cout << *f << '\n';
	delete f;

	f = new float[15];
	f[3] = 12.2;
	cout << f[0] << '\n';
	cout << f[15] << '\n';
	cout << f[3] << '\n';
	
	free(f);
	delete (int*)0;

	return (0);
}*/

/*q8 - <iostream>
int main()
{
	int i = 0;
	cin >> i;
	cout << "dadad "<< i << '\n';
	cerr << "dadad " << i << '\n';

	return (0);
}*/

/*q9 - Default parameters
void foo(int a, int b = 3, float c = 5.5)
{
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	foo(3);
	foo(3, 1.1);
	foo(6,5);
	foo(4,7,8.7);

	return (0);
}*/

/*q12 - Function overloading
int main()
{
	int v = 4;
	char c = 's';
	double z = 2323.77;
	float s = 223.77;
	foo(0);
	foo(5);
	foo(z);
	foo(s);
	foo('d');
	foo();
	foo(&v);
	foo(&c);
	
	return (0);
}
	
//DLL Implicit:
-> g++ -c -fPIC foo.c
-> g++ -fPIC -shared foo.o -o libfoo.so -L ./ 
-> g++ intro.c -lfoo -L ./ -Wl,-rpath,./
	
//DLL Explicit:
-> g++ -c -fPIC foo.c
-> g++ -fPIC -shared foo.o -o libfoo.so -L ./
-> g++ -ldl intro.c

#include <stddef.h>
#include <dlfcn.h>
#include <stdio.h>

typedef void (*foo_t)(int);

int main()
{
	void* handle = NULL;
	foo_t foo;
	
	const char* filename = "./libfoo.so";
	const char* symbol = "bar";
	
	handle = dlopen(filename, RTLD_LAZY);
	if(!handle)
	{
		printf("dlopen FAILURE\n");
	}
	
	foo = reinterpret_cast<foo_t>(dlsym(handle, symbol));
	//foo = dlsym(handle, symbol);
	if(!foo)
	{
		printf("dlsym FAILURE\n");
	}
	
	foo(5);

	dlclose(handle);
	
	return (0);
}
#ifdef __cplusplus
extern "C" {
#endif

#include "foo.h"

#ifdef __cplusplus
}
#endif

int main()
{
	bar(5);
	
	return (0);
}*/

/*q13 - namespace
namespace useless
{
	unsigned int g_w[400];
	extern int g_n;
	void foo()
	{
		cout << "foo useless\n";
	}

	namespace wasteoftime
	{
		void foo()
		{
			cout << "foo wasteoftime\n";
		}
	}
}

namespace stupid
{
	void foo()
	{
		cout << "foo stupid\n";
	}
	void bar()
	{
		cout << "bar stupid\n";
	}
	void DoNothing(unsigned int)
	{
		cout << "DoNothing stupid\n";
	}
}

namespace useless
{
	void DoNothing(unsigned int)
	{
		cout << "DoNothing useless\n";
	}
}

using namespace useless;

void DoStuff()
{
	stupid::bar();
	foo();

	using stupid::foo;
	foo();
	DoNothing(g_w[3] + 1);
}

void foo()
{
	cout << "foo\n";
}

using namespace stupid;
namespace comeon = useless::wasteoftime;

void DoMoreStuff()
{
	using ::foo;
	foo();
	bar();
	using useless::DoNothing;
	DoNothing(g_w[3] + 1);
}

namespace useless
{
	void DoUseLessStuff()
	{
		DoNothing(g_w[3] + 1);
	}
}

int main()
{
	cout << "DoStuff\n";
	DoStuff();
	cout << "\nDoMoreStuff\n";
	DoMoreStuff();
	cout << "\nDoUseLessStuff\n";
	DoUseLessStuff();
}*/

/*q14 - Const and literals
const char s = 'f';
int r = 3;
int c;
int main()
{
	const int i = 3;
	int* ip = (int*)&i;
	*ip = 5;
	int arr[i];

	printf("i = %d *ip = %d\n", i, *ip);
	printf("&i = %p\nip = %p\n", &i, ip);
	printf("size arr: %ld\n", sizeof(arr) / 4);
	return (0);
}*/

/*q15 - Inline functions
#include "foo.h"
int main()
{
	foo();
	return (0);
}*/

/*q16 - Template functions
#include "foo.h"

int main()
{
	int arr[12];

	cout << Max(3,5) << endl << Max<double>(3.5,12.6) << endl;
	cout << Max<int*>(arr,arr + 8) << endl;
	cout << Max<char>('a','b') << endl;
	cout << Max<float>(233.4,23.4) << endl;

	return (0);
}*/

/*q17 - Overloading regular functions and function templates
template <typename T>
void foo(T t)
{
	cout << t << " Generic foo for " << typeid(t).name() << endl;
}

template <>
void foo(int t)
{
	cout << t << " Specialized foo (for int param)\n";
}

int main()
{
	foo(4.2);
	foo(5);
	foo<int>(5);

	return (0);
}*/

/*q18 - References
int main()
{
	int i = 5;
	int a = 2;
	int& ip = i;
	ip = 9;
	cout << ip << " size:" << sizeof(ip) << endl;
	ip = a;
	cout << ip << " size:" << sizeof(ip) << endl;

	char c = 'd';
	char& cp = c;
	cp = 'e';

	cout << i << endl;
	cout << &i << endl;
	cout << ip << " size:" << sizeof(ip) << endl;
	cout << &ip << endl;
	cout << c << endl;
	cout << cp << " size:" << sizeof(cp) << endl;

	return (0);
}*/

/*q19 - Reference parameters
void foo(const double& x)
{
	cout << "x value: " << x << "	x adrress: " << &x << endl;
}

void bar(double& x)
{
	cout << "x value: " << x << "	x adrress: " << &x << endl;
}

int main()
{
	int a = 5;
	int& p = a;

	foo(p);
	bar(reinterpret_cast<double&>(p));

	return (0);
}*/

/*q20 - Ctors
struct X
{
    explicit X(); // Initialization function without parameters is named default constructor (often abbreviated as: default ctor).
    explicit X(int a_, int b_ = 8); // Regular (non default) Ctor.
    ~X(); //Deinitialization function is called destructor (Dtor).
    X(const X& other_); //Copy initialization function is called copy costructor or CCtor.
    X& operator=(const X& other_); //Assignment operator.
	X& operator*=(const X& other_); // operator.

    int m_a;
    const int m_b;
};

X::X(): m_a(3), m_b(4) //Implementation of the default Ctor. Why the X::X? The code after the colon is called an initialization list.
{
    // m_a = 3; 
    // m_b = 4;
    cout << "this:" << this <<
            " X default Ctor. m_a:" << m_a << 
            " m_b:" << m_b << endl;
}

X::X(int a_, int b_): m_a(a_), m_b(b_) //Implementation of the second Ctor. 
{
    cout<< "this:" << this <<
        " X int int Ctor. m_a:" << m_a << 
        " m_b:" << m_b << endl;
}

X::X(const X& other_): m_a(other_.m_a), m_b(other_.m_b) //Implementation of the copy Ctor.
{
    cout<< "this:" << this <<
        " X copy Ctor. m_a:" << m_a << 
        " m_b:" << m_b << endl;
}

X& X::operator=(const X& other_)
{
    m_a= other_.m_a;
    //  m_b= other_.m_b;
    cout << "this:" << this <<
        " X assignment operator. m_a:" << m_a << 
        " does not change m_b:" << m_b << endl;    
    return *this;
}

X& X::operator*=(const X& other_)
{
    m_a *= other_.m_a;
    // m_b *= other_.m_b;
    cout << "this:" << this <<
        " X * operator. m_a:" << m_a << " does not change m_b:" << m_b << endl;     
    return *this;
}

X::~X()
{
    cout << "this:" << this <<
        " X Dtor. m_a:" << m_a << 
        " m_b:" << m_b << endl;    
}

struct Y
{
    X m_x; 
    int m_i;
};

int main()
{
    X x1;
    X x2(7);
    X *px = new X(x2);
    X x3(9,10);
    X x4(x1);

    x1 = x3;
	x1 *= x3;
	cout << sizeof(X) << endl;

	//q21
	X* xp= new X[10];
    delete[] xp;
    delete px; px = 0;

	//q22
	Y y1;
    y1.m_x.m_a = 250;
    Y y2(y1);
    Y y3;

	y1.m_i = 7;
	
    y3 = y1;
	cout << y1.m_i << endl;
	
    return 0;
}*/

/*q23 - Generated functions
struct X
{
    explicit X();
    explicit X(int a_, int b_ = 8);
    ~X();
    X(const X& other_);
    X& operator=(const X& other_);

    int m_a;
    int m_b;
};

X::X(int a_, int b_): m_a(a_), m_b(b_)
{
    cout << "this:" << this << " X int int Ctor. m_a:" << m_a << " m_b:" << m_b << endl;
}

X::X(const X& other_): m_a(other_.m_a), m_b(other_.m_b)
{
    cout << "this:" << this << " X copy Ctor. m_a:" << m_a << " m_b:" << m_b << endl;
}

X& X::operator=(const X& other_)
{
    m_a= other_.m_a;
    m_b= other_.m_b;
    cout << "this:" << this << " X * operator. m_a:" << m_a << " m_b:" << m_b << endl;     
    return *this;
}

X::~X()
{
    cout << "this:" << this <<
        " X Dtor. m_a:" << m_a << 
        " m_b:" << m_b << endl;    
}

int main()
{
    X x1;
    X x2(7);
    X x3(x2);

    x1 = x3;
	
    return (0);
}*/

/*q24 - Member functions
struct X
{
    X(int a_, int b_);

    void Inc();
    void Dec();

    int m_a;
    int m_b;
};

X::X(int a_, int b_): m_a(a_), m_b(b_)
{
	cout << "this:" << this << " X Init m_a:" << m_a << " m_b:" << m_b << endl;
}

void X::Inc()
{
    ++m_a;
    ++m_b;
	cout << "this:" << this << " X Inc m_a:" << m_a << " m_b:" << m_b << endl;
}

void X::Dec()
{
    --m_a;
    --m_b;
	cout << "this:" << this << " X Dec m_a:" << m_a << " m_b:" << m_b << endl;
}

void Inc(X x)
{
	++(x.m_a);
	++(x.m_b);
	cout << " X Dec m_a:" << x.m_a << " m_b:" << x.m_b << endl;
}

int main()
{
    X x1(7,-55);
    X x2(x1);

    Inc(x1);
    x1.Inc();
    x1.Inc();
    x2.Dec();

    return 0;
}*/

/*q25 - const
struct X 
{ 
	explicit X(); 
    explicit X(int m_a); 
    ~X(); 
    void Foo(); 
    void Bar() const; 

    int m_a; 
    int *m_p; 
}; 

X::X(int a_): m_a( a_ ), m_p(new int(a_)) {} 

X::~X() { delete m_p; m_p=0; } 

void X::Foo() { ++m_a; --(*m_p); } 

void X::Bar() const 
{ 
    cout << m_a << endl;
	cout << &m_a << endl; 
    cout << *m_p << endl; 
    cout << m_p << endl;    
    //m_a = 0; //---1---
    //m_p = 0; //---2---
    *m_p = 5; //---3---
	cout << *m_p << endl; 
    cout << m_p << endl;
    //Foo(); //---5---
} 

void Fifi(const X& x_) 
{ 
    //x_.Foo(); //---4---
    x_.Bar(); 
} 

int main() 
{ 
    X x1(1); 

    x1.Foo(); 
    Fifi(x1); 

    return 0; 
}*/
 
/*q26 - class
#include <cstdio>

class X
{
public:
	explicit X();
    explicit X(int a_);
    void Foo();
	int GetMA();


    unsigned char m_a;
};

X::X(): m_a(12){}

X::X(int a_): m_a(a_){}

void X::Foo()
{
    printf("X::Foo: %d\n", m_a);
}

int X::GetMA()
{
    return(m_a);
}

void Foo(const X& x_)
{
    printf("Foo: %d\n", const_cast<X&>(x_).GetMA());
}

int main()
{
    X x1(10);
	X x2;

    printf("\nx1: %d\n", x1.GetMA());
    x1.Foo();
    Foo(x1);

    printf("\nx2: %d\n", x2.GetMA());
	x2.Foo();
    Foo(x2);
	printf("\n");

    return 0;
}*/

/*q28 - Operator overloading
class X
{
public:
    explicit X(int a_ = 12);
	~X();
    bool operator==(const X& o_) const { return m_a == o_.m_a; }
    friend ostream& operator<<(ostream& os_, const X& x_);
	friend int operator+(const X& x1_, const X& x2_);
	friend int operator-(const X& x1_, const X& x2_);
	friend int operator*(const X& x1_, const X& x2_);
private:
    int m_a;
};

X::X(int a_): m_a(a_){}

X::~X() { cout << "bye!\n"; } 

int main()
{
    X x1(5);
    X x2(3);

    cout << "x1 + x2: " << x1 + x2 << endl <<
			"x1 - x2: " << x1 - x2 << endl <<
			"x1 * x2: " << x1 * x2 << endl <<
           	"x1 == x2 ? " << (((x1 == x2) == 1) ? "YES" : "NO") << endl <<
           	"x1: " << x1 << endl <<
           	"x2: " << x2 << endl;

    return 0;
}

ostream& operator<<(ostream& os_, const X& x_) 
{
    return os_ << x_.m_a;
}

int operator+(const X& x1_, const X& x2_)
{
    return (x1_.m_a + x2_.m_a);
}

int operator-(const X& x1_, const X& x2_)
{
    return (x1_.m_a - x2_.m_a);
}

int operator*(const X& x1_, const X& x2_)
{
    return (x1_.m_a * x2_.m_a);
}*/

/*q29 - Conversions
#include <iostream>

class X
{
public:
    explicit X();
    X(int a_);
    explicit X(int a_, int b_);

    operator int() const;
    void Print() const;

private:
    int m_a;
}; 

X::X() : m_a(0) { }
X::X(int a_) : m_a(a_) { }
X::X(int a_, int b_) : m_a(a_ + b_) { }

X::operator int()const 
{ 
    return m_a;
}

void X::Print()const
{ 
    cout << "X::Print() " << m_a << endl;
}

void Fifi(X& x_)
{
    cout << "Fifi() " << x_ << endl;
    x_.Print();
}

int main()
{
    X x1(7);

    Fifi(x1);     // (1)
	Fifi(X(7));   // (2)
	Fifi(X{7});   // (2)
    Fifi(static_cast<X>(7));   // (2)
    Fifi(9);      // (3)
    Fifi(X(3, 4)); // (4)

    return x1 * 3; //(5)
}*/

/*q30 - Static members
class X
{
public:
    X() : m_id(++s_cntr) {}
    int GetId() { cout << m_id << endl; return m_id;}
private:
    int m_id;
    static int s_cntr;
};

int X::s_cntr = 0;

int main()
{
    X x1;
    X x2;

    x1.GetId();
    x2.GetId();

    return 0;   
}*/

/*q32 - Inheritance
class B
{
public:
    B(int a_):m_a(a_){ cout << "B::Ctor" << endl; }    
	virtual ~B(){ cout << "B::Dtor" << endl; }

    virtual void Print1() const;
    virtual void Print2() const;
    virtual void Print3() const;
private:
    int m_a;
};

void B::Print1() const
{ 
    cout << "B::Print1 B::m_a - " << m_a << endl;
}

void B::Print2() const
{
    cout << "B::Print2" << endl;
}

void B::Print3() const
{ 
    cout << "B::Print3" << endl; 
}    

class X: public B
{
public:
    X():m_b(0) { cout<< "X::Ctor" << endl; }

    ~X(){ cout << "X::Dtor" << endl;}

    virtual void Print1()const
    { 
        cout << "X::Print1 X::m_b - " << m_b << endl;
        // B::Print1();
        cout << "X::Print1 end" << endl; 
    }

    void Print2() const { cout << "X::Print2" << endl; }
private:
    int m_b;
};

int main()
{
    B *b1= new B;
    B *b2= new X;
	
	cout<< endl << "sizeof(X): " << sizeof(X) << endl;
	cout<< "sizeof(B): " << sizeof(B) << endl;
	cout<< "sizeof(b1): " << sizeof(b1) << endl;
	cout<< "sizeof(b2): " << sizeof(b2) << endl;

    cout<< endl << "main b1:" << endl;
    b1->Print1();
    b1->Print2();
    b1->Print3();

    cout << endl << "main b2:" << endl;
    b2->Print1();
    b2->Print2();
    b2->Print3();

    X *xx= static_cast<X*>(b2);
    cout << endl << "main xx:" << endl;
    xx->Print2();
    b2->Print2();

    delete b1;
    delete b2;

    return (0);
}*/

/*q33 - Exceptions
#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>

using namespace std; 

class X
{   
public:
    X(int a_ = 3): a(a_) { cout << "X::Ctor\n";} 
	~X() { cout << "X::Dtor\n";}

private:
	int a;
}; 


struct BadDog: public runtime_error 
{   
	BadDog(const string& s_ = "This is a bad dog"): runtime_error(s_) {} 
}; 

struct Avi: public BadDog 
{   
	Avi(const string& s_ = "This is a bad Avi"): BadDog(s_) {} 
}; 

void Fifi() 
{ 
    // throw BadDog("bad pup");
	throw Avi("bad Avi");
	cerr << "Fifi() after throw" << endl; 
} 

void Foo() 
{ 
    X x1;     
    Fifi();     
    cerr << "Foo() after Fifi()" << endl; 
} 

void Bar() 
{ 
    Foo(); 
    cerr << "Bar() after Foo()" << endl; 
}

int main() 
{     
    try     
    {         
        Bar();     
    } 
	catch(runtime_error&)     
	{         
		cerr << "runtime_error! exiting." << endl;
		exit(2);     
	}     
	catch(BadDog& b)     
	{         
		cerr << "Bad dog exception: " << b.what() << endl;
		exit(3);     
	}     
	catch(Avi& a)     
    {         
        cerr << "Avi exception: " << a.what() << endl;
		exit(4);     
    } 
    catch(bad_alloc&)     
    {         
        cerr << "Out of memory! exiting." << endl;
		exit(2);     
    }
        
    catch( exception& r )
    {
        cerr << "unknown exception: " << r.what() << endl;
        exit(4);     
    }
	
    return 0; 
}*/

/*q34 - Dynamic exception specification
#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>

void T(void)
{
	cerr << "Terminate!\n"; 
}

void F(void)
{
	cerr << "Unexpected!\n"; 
}

int Foo(int a) throw(int)
{
	cout << "I'm Foo! " << a << endl; 

	throw bad_alloc();

	return (a);
}

int main()
{
	set_terminate(T);
	set_unexpected(F);

	Foo(6);

	return (0);
}*/

/*q35 - Crashed program
#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>

void Foo(void) throw(int)
{
	cout << "I'm Foo!\n";

	throw bad_alloc();
}

int main()
{
	Foo();
	
	return (0);
}*/

/*q36 - Exception safety – resources
void Foo()
{
    int *ip = new int;
    Bar(ip);
    Fishi();
    Fifi(ip);
    Dodo();
    delete ip;
}*/

/*q37 - Exception safety – Dtors
#include <exception>
#include <cstdlib>

class X
{
public:
	X(int a = 10) : m_a(a) { cout << "X Ctor\n";}
	~X();

private:
	int m_a;
};

struct bad_cast: public runtime_error 
{   
	bad_cast(const string& s_ = "This is a bad_cast"): runtime_error(s_) {} 
}; 

int Foo(int a) throw(bad_alloc)
{
	cerr << "Foo bad_alloc: " << a << endl;
	throw bad_alloc();
	return (a);
}

X::~X()
{   
	cout << "X Dtor\n"; 
	try
    {
		cerr << Foo(m_a) << endl;
	}
	catch(bad_alloc&)     
    {         
        cerr << "Out of memory! exiting." << endl; 
		exit(1);   
    }
}

void Bar() throw(bad_cast)
{
	throw bad_cast("bad_cast");
}

void Fishi()
{
    X x1;
    Bar();
}

int main()
{
	// Fishi();
	try
	{
		Fishi();
	}
	catch(bad_cast& a)     
    {         
        cerr << "bad_cast exception: " << a.what() << endl;
		exit(4);     
    } 

	return (0);
}*/

/*q38 - Exception safety – Ctors
#include <exception>
#include <typeinfo>

struct X
{
    X() { cerr << "X Ctor" << endl; throw bad_cast(); }
    X(int) { cerr << "X Ctor (int)" << endl; }
    ~X() { cerr << "X Dtor" << endl; }
};

struct Y
{
    Y() { cerr << "Y Ctor" << endl; }
    ~Y(){ cerr << "Y Dtor" << endl; }
};

class L
{
public:
    L() :m_x(2) { cerr << "L Ctor" << endl; }
    ~L() { cerr << "L Dtor" << endl; }
private:
    Y m_y;
    X m_x;
};

class M
{
public:
    M() { cerr << "M Ctor" << endl; }
    ~M() { cerr << "M Dtor" << endl; }
private:
    X m_x;
    Y m_y;
};

class N
{
public:
    N() { cerr << "N Ctor" << endl; }
    ~N() { cerr << "N Dtor" << endl; }
private:
    Y m_y;
    X m_x;
};

class J
{
public:
    J(): m_y(new Y), m_x(new X) { cerr << "J Ctor" << endl;}
    ~J() { cerr << "J Dtor" << endl; delete m_x; delete m_y; }
private:
    Y *m_y;
    X *m_x;
};

class K
{
public:
    K() { cerr << "K Ctor" << endl; m_y= new Y; m_x= new X; }
    ~K() { cerr << "K Dtor" << endl; delete m_x; delete m_y; }
private:
    Y *m_y;
    X *m_x;
};

int main()
{
    try
    {
        // X var1;
		// Y var1;
		// L var1;
		// M var1;
		// N var1;
		// J var1;
		K var1;
    }
    catch(exception& e)
    {
        cerr << "exception caught. what:" << e.what() << endl;
		
    }

    return 0;
}*/

/*q40 -Inheritance dynamic allocation pitfall
class X
{
public:
	X() { cout << "X Ctor - " << this << " sizeof X - " << sizeof(*this) << endl; }
    virtual ~X() { cout << "X Dtor - " << this << endl; }

private:
	int m_a;
};

class Y: public X
{
public:
	Y() { cout << "Y Ctor - " << this << " sizeof Y - " << sizeof(*this) <<  endl; }
    ~Y() { cout << "Y Dtor - " << this << endl; }
	
private:
    int m_b;
};

int main()
{ 
    X *xp= new Y[2];

    delete[] xp;

    return 0;
}*/

/*q41 - Slicing
class X
{
public:
	X() { cout << "X Ctor - " << this << " sizeof X - " << sizeof(*this) << endl; }
	explicit X(const X& other) {}
    virtual ~X() { cout << "X Dtor - " << this << endl; }

private:
	int m_a;
};

class Y: public X
{
public:
	Y() { cout << "Y Ctor - " << this << " sizeof Y - " << sizeof(*this) <<  endl; }
    ~Y() { cout << "Y Dtor - " << this << endl; }
	
private:
    int m_b;
	int m_c;
};

void Foo(X x)
{
	cout << "X - " << &x << " sizeof X - " << sizeof(x) << endl;
}

int main()
{ 
    Y y1;
    Foo(y1);

    return 0;
}*/

/*q42 - Inheritance assignment pitfall
class X
{
public:
    X(double d_) :m_a(d_) {}
    virtual ~X() {}

private:
    double m_a;
};

class Y: public X
{
public:
    Y(double d_, int i_): X(d_), m_b(i_) {}
private:
    int m_b;
};

int main()
{
    Y y1(0.0, 0), y2(14.2, 5);
    Y y3(0.0, 0), y4(14.2, 5);

    X &x1 = y1;
    X &x2 = y2;

    x1 = x2;
    y3 = y4;

    return 0;
}*/

/*q43 - Virtual static binding
class Base 
{
public:
    Base() 
	{
        cout << "Base constructor\n";
        func();  // Statically bound (calls Base::func)
    }

    virtual ~Base() 
	{
        cout << "Base destructor\n";
        func();  // Statically bound (calls Base::func)
    }

    virtual void func() 
	{
        cout << "Base::func (virtual)\n";
    }
};

class Derived : public Base 
{
public:
    Derived() 
	{
        cout << "Derived constructor\n";
		func();
    }

    ~Derived() 
	{
        cout << "Derived destructor\n";
		func();
    }

    void func() 
	{
        cout << "Derived::func (overridden)\n";
    }
};

int main() 
{
    cout << "Creating object directly:\n";
    Derived obj;  // Static binding in constructor/destructor
	cout << "\n";

    cout << "Using pointer:\n";
    Base* ptr = new Derived();  // Dynamic binding (virtual function table used)
	cout << "\n";

    ptr->func();  // Calls Derived::func dynamically
	cout << "\n";

    delete ptr;   // Ensures correct destructor sequence

    return 0;
}*/

/*q44 - protected keyword
class Base 
{ 
protected: 
    int id_protected; 
}; 
  
class Derived : public Base 
{ 
public: 
    void setId(int id) 
    { 
        id_protected = id; 
    } 
  
    void displayId() 
    { 
        cout << "id_protected is: " << id_protected << endl; 
    } 
}; 
 
int main() 
{ 
  
    Derived obj1; 
  
    obj1.setId(81); 
    obj1.displayId(); 

    return 0; 
}*/

/*q45 - Pure virtual method - Abstract class
class Base 
{
public:
    virtual void fun() = 0;
    int getX() { return x; }
private:
    int x;
};

class Derived : public Base 
{	
public:
    void fun() { cout << "fun() called\n"; }
private:
	int y;
};

int main(void)
{
    Derived d;

    d.fun();

    return 0;
}*/

/*q46 - Template classes
template <typename T>
class Square
{ 
public:
    Square(T side) : side_length(side) {}

    T GetSideLength() const { return side_length; }
    void SetSideLength(T side) { side_length = side; }

    T Area() const { return side_length * side_length; }
private:
        T side_length;
};

int main() 
{
    Square<int> int_square(5);
    cout << "int_square     Side: " << int_square.GetSideLength() << ",    Area: " << int_square.Area() << endl;

    int_square.SetSideLength(3);
    cout << "int_square     Side: " << int_square.GetSideLength() << ",    Area: " << int_square.Area() << endl;

    Square<double> double_square(5.5);
    cout << "double_square  Side: " << double_square.GetSideLength() << ",  Area: " << double_square.Area() << endl;

    double_square.SetSideLength(9.1);
    cout << "double_square  Side: " << double_square.GetSideLength() << ",  Area: " << double_square.Area() << endl;

    return (0);
}*/

/*q47 - Some Finalizers
class Base
{
public:
    virtual ~Base() {}  // Always declare base class destructor as virtual for polymorphism

    virtual Base* Clone() const = 0; // Pure virtual function for cloning
    virtual void Show() const = 0;   // Another virtual function to demonstrate polymorphism
};

class Derived : public Base 
{
public:
    Derived(double v1, int v2 = 5.5) : value1(v1), value2(v2) {}
    
    virtual Derived* Clone() const { return (new Derived(*this)); } // Override Clone() to return a copy of Derived
    virtual void Show() const
    { 
        cout << "Derived Size: " << sizeof(*this) << endl;
        cout << "Derived value1: " << value1 << endl;
        cout << "Derived value2: " << value2 << endl;
    }   // Example method to show data
private:
    double value1;
    double value2;
};
  
void Foo(Base* b)
{
    cout << "Foo: ";
    b->Show();
}

int main() 
{
    Base* original = new Derived(42.5);  // Create a Derived object via Base pointer
    Base* clone = original->Clone();    // Clone the object polymorphically
    Base* copy = original;

    Derived d(42.5);

    cout << "Original: ";
    original->Show();

    cout << "Clone: ";
    clone->Show();

    cout << "Copy: ";
    copy->Show();

    Foo(&d);

    delete original;
    delete clone;

    return (0);
}*/