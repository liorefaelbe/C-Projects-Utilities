#include <iostream>
#include <cmath>
#include <string>

using namespace std;

template <typename T>
int CheckValue(T received, T expected, string func_name, int lineNumber)
{
    if (expected == received)
    {
        cout << "Test-" << func_name << " \033[0;32mSUCCESS!\033[0m" << endl;
        return (0);
    }
    else
    {
        cout << "Test-" << func_name << " \033[0;31mFAILURE! \033[0mline: " << lineNumber << " | expected: " << expected << " | received: " << received << endl;
        return (1);
    }
}

template <>
int CheckValue (double received, double expected, string func_name, int lineNumber)
{
    const double EPSILON = 1e-5; 
    
    if (fabs(expected - received) < EPSILON)
    {
        cout << "Test-" << func_name << " \033[0;32mSUCCESS!\033[0m" << endl;
        return (0);
	}
	else
	{
        cout << "Test-" << func_name << " \033[0;31mFAILURE! \033[0mline: " << lineNumber << " expected: " << expected << " received: " << received << endl;
        return (1);
	}
}