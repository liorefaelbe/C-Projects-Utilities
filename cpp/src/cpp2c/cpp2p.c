/*q2 - C Structs
#include <stdio.h>

struct A
{ };

struct B
{
    int x;
    int y;
};

int main()
{
    printf("%ld\n", sizeof(struct A));
    printf("%ld\n", sizeof(struct B));

    return (0);
}*/

/*q3 - C++ Classes vs. C Structs
#include <iostream>

using namespace std;

class A
{
public:
    int m_a;
};

union B
{
public:
    int a;
    double b;
    char c;
    void Foo() const;
};

class C
{
public:
    int m_c;
};

int main()
{
    union B b1 = {2};

    cout << b1.a << endl;

    return (0);
}*/

/*q5 - Phase 5: C++ Classes
class Point
{
public:
    Point();
    Point(int x,int y);
private:
    int m_x;
    int m_y;
};

Point::Point() {}
Point::Point(int x,int y):m_x(0),m_y(0) {}

class A
{};

class B
{
private:
    int x;
    int y;
    Point p;
};

int main()
{
    A a;
    B b;
    B b2(b);
    b2 = b;

    return (0);
}

-------------------------------------------------------------

typedef struct
{
    int m_x;
    int m_y;
}Point;

void PointDefultCtor(Point* const point) { (void)point; }
void PointCtor(Point* const point, int x, int y)
{
    point->m_x = x;
    point->m_y = y;
}
void PointCCtor(Point* const point1, Point* const point2)
{
    point1->m_x = point2->m_x;
    point1->m_y = point2->m_y;
}
void PointDtor(Point* const point) { (void)point; }
void PointAssignment(Point* const point1, Point* const point2)
{
    PointCCtor(point1, point2);
}

typedef struct
{} A;

void DefultCtor(A* const a) { (void)a; }
void ACtor(A* const a) { (void)a; }
void ACCtor(A* const a) { (void)a; }
void ADtor(A* const a) { (void)a; }
void AAssignment(A* const a) { (void)a; }

typedef struct
{
    int m_x;
    int m_y;
    Point m_p;
}B;

void BDefultCtor(B* const b) { (void)b; }
void BCtor(B* const b, int x, int y, Point* p)
{
    b->m_x = x;
    b->m_y = y;
    PointCCtor(&b->m_p, p);
}
void BCCtor(B* const b1, B* b2)
{
    b1->m_x = b2->m_x;
    b1->m_y = b2->m_x;
    PointCCtor(&b1->m_p, &b2->m_p);
}
void BDtor(B* const b) { (void)b; }
void BAssignment(B* const b1, B* const b2)
{
    BCCtor(b1, b2);
}

int main()
{
    A a;
    B b;
    Point p;
    B b2;

    ACtor(&a);
    PointCtor(&p, 1, 1);
    BCtor(&b, 1, 1, &p);

    BCCtor(&b2, &b);
    BAssignment(&b2, &b);

    BDtor(b2);
    PointDtor(p);
    BDtor(b);
    ADtor(a);

    return (0);
}*/

/*q6-7 - C++ Class Methods - Allocation and Deletion
class B
{
public:
    void SetX(int in_x);
    void SetY(int in_y);
private:
    int x;
    int y;
};

void B::SetX(int in_x)
{
    x = in_x;
}

void B::SetY(int in_y)
{
    y = in_y;
}

int main()
{
    B b;
    b.SetX(5);
    b.SetY(6);

    B* p = new B;
    p->SetX(5);
    p->SetY(6);

    delete p;

    return (0);
}

-------------------------------------------------------------------------------------

typedef struct
{
    int m_x;
    int m_y;
}B;

void BDefultCtor(B* const b) { (void)b; }
void BCtor(B* const b, int x, int y)
{
    b->m_x = x;
    b->m_y = y;
}
void BCCtor(B* const b1, B* const b2)
{
    b1->m_x = b2->m_x;
    b1->m_y = b2->m_x;
}
void BDtor(B* const b) { (void)b; }
void BAssignment(B* const b1, B* const b2)
{
    BCCtor(b1, b2);
}

static void SetX(B* const b, int in_x)
{
    b->m_x = in_x;
}

static void SetY(B* const b, int in_y)
{
    b->m_y = in_y;
}

int main()
{
    B b;

    BDefultCtor(&b);

    SetX(&b, 5);
    SetY(&b, 6);

    B* p = malloc(sizeof(B));
    SetX(&p, 5);
    SetY(&p, 6);

    free(p);

    BDtor(&b);

    return (0);
}*/

/*q8 - Arrays
#include <iostream>

using namespace std;

class B
{
public:
    B() { cout << "B Ctor\n"; }
    ~B() { cout << "B Dtor\n"; }
    int m_a;
};

void Foo()
{
    B array1[2];

    B* array2 = new B[2];

    delete array2;
}

int main()
{
    Foo();

    return (0);
}

------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int m_a;
}B;

void BCtor(B* const b)
{
    (void)b;

    printf("B Ctor\n");
}

void BDtor(B* const b)
{
    (void)b;

    printf("B Dtor\n");
}

#define SIZE (2)

void New(B* bptr, size_t size)
{
    size_t i = 0;

    bptr = malloc(sizeof(B) * size);

    for(i = 0; i < size; ++i)
    {
        BCtor(bptr + i);
    }
}

void Delete(B* bptr, size_t size)
{
    size_t i = 0;

    for(i = 0; i < size; ++i)
    {
        BDtor(bptr + ( size - 1) - i);
    }

    free(bptr);
}

void Foo()
{
    int i = 0;

    B array1[SIZE];
    B* array2 = NULL;

    for(i = 0; i < SIZE; ++i)
    {
        BCtor(&array1[i]);
    }

    New(array2, SIZE);

    Delete(array2, SIZE);

    for(i = SIZE - 1; i >= 0; --i)
    {
        BDtor(&array1[i]);
    }
}

int main()
{
    Foo();

    return (0);
}*/

/*q9 - Pass by Value, Pass by Reference
B Bar(B b1,B* b2,B& b3)
{
    return b1;
}

-----------------------------------------

typedef struct
{
    int m_a;
}B;

B Bar(B b1, B* b2, B* const B3)
{
    return (b1);
}

int main()
{
    return (0);
}*/

/*q10 - Static Methods
class B
{
public:
    // ...
    static void Bla();
};
void B::Bla()
{

}
int main()
{
    // ...
    B::Bla();

    // ...
    B b;
    b.Bla();
}

-------------------------------------------------

void Bla(void);*/

/*q11 - Inheritance
class Base
{
    int x;
    int y;
};

class Derived : public Base
{
    int z;
};

------------------------------------------------

typedef struct
{
    int x;
    int y;
}Base;

typedef struct
{
    Base b;
    int z;
}Derived;*/

/*q12 - 16 - Object Construction Order
class Base
{
public:
    Base(int inX,int inY);
private:
    int x;
    int y;
};

Base::Base(int inX,int inY):x(inX),y(inY) {}

class Derived : public Base
{
public:
    Derived(int inX,int inY,int inZ);
private:
    int z;
};

Derived::Derived(int inX,int inY,int inZ):Base(inX,inY),z(inZ) {}

--------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    void (*pdtor)(void*);
    void (*pfoo)(void);
}VTable;

typedef struct
{
    VTable* vptr;
    int m_x;
    int m_y;
}Base;

void BaseDefultCtor(Base* const this) { (void)this; }
void BaseCCtor(Base* const this, Base* const other)
{
    this->m_x = other->m_x;
    this->m_y = other->m_y;
}
void BaseDtor(Base* const this) { printf("Base - Dtor - %ld\n", (size_t)this); }
void BaseAssignment(Base* const this, Base* const other)
{
    BaseCCtor(this, other);
}

void BaseFoo(void)
{
    printf("Foo Base\n");
}

VTable base_vtable = {(void (*)(void*))&BaseDtor, &BaseFoo};

void BaseCtor(Base* const this, int x, int y)
{
    this->m_x = x;
    this->m_y = y;
    this->vptr = &base_vtable;

    printf("Base - Ctor - %ld\n", (size_t)this);
}

typedef struct
{
    VTable* vptr;
    Base m_b;
    int m_z;
}Derived;

void DerivedDefultCtor(Derived* const this) { (void)this; }
void DerivedCCtor(Derived* const this, Derived* const other)
{
    BaseCCtor(&this->m_b, &other->m_b);
    this->m_z = other->m_z;
}
void DerivedDtor(Derived* const this)
{
    printf("Derived - Dtor - %ld\n", (size_t)this);
    this->m_b.vptr->pdtor(&this->m_b);
}
void DerivedAssignment(Derived* const this, Derived* const other)
{
    DerivedCCtor(this, other);
}

void DerivedFoo(void)
{
    printf("Foo Derived\n");
}

VTable derived_vtable = {(void (*)(void*))&DerivedDtor, &DerivedFoo};

void DerivedCtor(Derived* const this, int x, int y, int z)
{
    BaseCtor(&(this->m_b), x, y);
    this->m_z = z;
    this->vptr = &derived_vtable;

    printf("Derived - Ctor - %ld\n", (size_t)this);
}

int main()
{
    Base* p_base = malloc(sizeof(Derived));
    DerivedCtor((Derived*)p_base, 5, 6, 7);

    p_base->vptr->pfoo();

    p_base->vptr->pdtor(p_base);

    free(p_base);

    return (0);
}*/

/*q21 - Templates
#include <stdio.h>

#include "max.h"

TEMPLATE_MAX(int)
TEMPLATE_MAX(double)

int main()
{
    int a = Max_int(5, 6);
    float b = Max_double(5.5, 6.5);

    printf("%d  %f\n", a, b);

    return (0);
}*/