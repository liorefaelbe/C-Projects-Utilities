#include <iostream>      // cout

#include "bitset.hpp"    // BitSet
#include "test_func.hpp" // CheckValue

using namespace std;
using namespace ilrd_166_7;

/************************* Forward Declarations ************************/

static int TestConstructors(void);
static int TestSetGetFlipCount(void);
static int TestOperators(void);
static int TestBitProxy(void);
static int TestToString(void);
static int TestShift(void);
static int TestException(void);

/******************************* Main **********************************/

int main()
{
    int status = 0;

    status += TestConstructors();
    status += TestSetGetFlipCount();
    status += TestOperators();
    status += TestBitProxy();
    status += TestToString();
    status += TestShift();
    status += TestException();

    (status == 0) ? (cout << "\033[0;32mAll Good!\033[0m\n")
                  : (cout << "\033[0;31m" << status << " FAILS! \033[0mTotal\n");

    return (0);
}

/**************************** Test Cases *******************************/

static int TestConstructors()
{
    int status = 0;

    BitSet<8> b;
    for (size_t i = 0; i < 8; ++i)
    {
        status += CheckValue(b[i] == 0UL, true, "Ctor", __LINE__);
    }

    return (status);
}

static int TestSetGetFlipCount()
{
    int status = 0;

    BitSet<8> b;
    b.Set(3, true);
    b.Set(7, true);

    status += CheckValue(b.Get(3), true, "Set/Get", __LINE__);
    status += CheckValue(b.Get(7), true, "Set/Get", __LINE__);
    status += CheckValue(b.CountSetBit(), 2UL, "CountSetBit", __LINE__);

    b.Flip(3);

    status += CheckValue(b.Get(3), false, "Flip(index)", __LINE__);
    status += CheckValue(b.CountSetBit(), 1UL, "CountSetBit", __LINE__);

    b.Flip();

    status += CheckValue(b.CountSetBit(), 7UL, "Flip(all)", __LINE__);

    b.Reset();

    status += CheckValue(b.CountSetBit(), 0UL, "Reset", __LINE__);

    return (status);
}

static int TestOperators()
{
    int status = 0;

    BitSet<8> b1, b2;
    b1.Set(0, true).Set(2, true);
    b2.Set(2, true).Set(3, true);

    BitSet<8> b3 = b1;
    b3 |= b2;

    status += CheckValue(b3.Get(0), true, "|=", __LINE__);
    status += CheckValue(b3.Get(2), true, "|=", __LINE__);
    status += CheckValue(b3.Get(3), true, "|=", __LINE__);

    b3 = b1;
    b3 &= b2;

    status += CheckValue(b3.Get(2), true, "&=", __LINE__);
    status += CheckValue(b3.CountSetBit(), 1UL, "&=", __LINE__);

    b3 = b1;
    b3 ^= b2;

    status += CheckValue(b3.Get(0), true, "^=", __LINE__);
    status += CheckValue(b3.Get(3), true, "^=", __LINE__);

    BitSet<8> b4 = b3;

    status += CheckValue(b3 == b4, true, "==", __LINE__);
    status += CheckValue(b3 != b2, true, "!=", __LINE__);

    return (status);
}

static int TestBitProxy()
{
    int status = 0;

    BitSet<8> b1, b2;
    b2.Set(4, true);

    b1[4] = b2[4];

    status += CheckValue(b1.Get(4), true, "BitProxy assign", __LINE__);

    if (b1[4])
    {
        status += CheckValue(true, true, "BitProxy bool context", __LINE__);
    }

    return (status);
}

static int TestToString()
{
    int status = 0;

    BitSet<8> b;
    b.Set(0, true);
    b.Set(7, true);

    status += CheckValue(b.ToString() == "10000001", true, "ToString", __LINE__);

    return (status);
}

static int TestShift()
{
    int status = 0;

    BitSet<8> b;
    b.Set(0, true);
    b <<= 2;

    status += CheckValue(b.Get(2), true, "<<=", __LINE__);

    b >>= 1;
    status += CheckValue(b.Get(1), true, ">>=", __LINE__);

    return (status);
}

static int TestException(void)
{
    int status = 0;
    
    BitSet<50> b;

    int is_catched = 0;

    try
    {
        b[80] = false;
    }
    catch (const out_of_range& e)
    {
        is_catched = 1;
        cout << "out_of_range\n";
    }

    status += CheckValue(is_catched, 1, "out_of_range" , __LINE__);

    is_catched = 0;

    try
    {
        b.Set(80, false);
    }
    catch (const out_of_range& e)
    {
        is_catched = 1;
        cout << "out_of_range\n";
    }

    status += CheckValue(is_catched, 1, "out_of_range" , __LINE__);

    return (status);
}