#include "bitarr.hpp" // BitArr
#include "test_func.hpp" // CheckValue

using namespace std;
using namespace ilrd_166_7;

/*************************Forward-Declaration******************************/

static int TestOperators(void);
static int TestSetBitArr(void); 
static int TestException(void);

/*********************************Main*************************************/

int main()
{
    int status = 0;
    
    status += TestOperators();
    status += TestSetBitArr(); 
    status += TestException();
    
    (status == 0) ? (cout << "\033[0;32mAll Good!\033[0m\n") : 
                    (cout << "\033[0;31m" << status << " FAILS! \033[0mTotal\n");
    
    return (0);
}

/****************************Static-Functions******************************/

static int TestOperators(void) 
{
    int status = 0;
    
    BitArr b1;
	BitArr b2;

    status += CheckValue(b1[0] == false, true, "Ctor" , __LINE__);
	
	b1[0] = true;
	
	status += CheckValue(b1[0] == true, true, "Operator[]" , __LINE__);
	
	b1[0] = b2[0];

    status += CheckValue(b1[0] == false, true, "Operator=" , __LINE__);
    status += CheckValue(b2[1] == false, true, "Operator=" , __LINE__);

    BitArr b;
    b[4] = true;
    b[5] = b[4];

    status += CheckValue(b[5] == true, true, "Operator=" , __LINE__);

	bool flag = true;
    flag = b1[0];

    status += CheckValue(flag == false, true, "operator bool" , __LINE__);
   
    return (status);
}

static int TestSetBitArr(void)
{
    int status = 0;

    BitArr b3;
    for (size_t i = 0; i < 64; ++i)
    {
        int n = rand() % 100;
        b3[i] = (n & 1);
    }

    for (size_t i = 0; i < 64; ++i)
    {
        cout << b3[i];
        if ((i + 1) % 4 == 0)
        {
            cout << " ";
        }
    }
    cout << endl;

    return (status);
} 

static int TestException(void)
{
    int status = 0;
    
    BitArr b1;

    int is_catched = 0;

    try
    {
        b1[80] = false;
    }
    catch (const out_of_range& e)
    {
        is_catched = 1;
        cout << "out_of_range\n";
    }

    status += CheckValue(is_catched, 1, "out_of_range" , __LINE__);

    return (status);
}