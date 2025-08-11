#include <iostream>

// Primary template: Fibonacci<N> computes fib(N)
template<int N>
struct Fibonacci
{
    static const int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

// Specializations for base cases
template<>
struct Fibonacci<0>
{
    static const int value = 0;
};

template<>
struct Fibonacci<1>
{
    static const int value = 1;
};

int main()
{
    std::cout << "Fibonacci<0> = " << Fibonacci<0>::value << "\n";
    std::cout << "Fibonacci<1> = " << Fibonacci<1>::value << "\n";
    std::cout << "Fibonacci<2> = " << Fibonacci<2>::value << "\n";
    std::cout << "Fibonacci<3> = " << Fibonacci<3>::value << "\n";
    std::cout << "Fibonacci<4> = " << Fibonacci<4>::value << "\n";
    std::cout << "Fibonacci<5> = " << Fibonacci<5>::value << "\n";
    std::cout << "Fibonacci<10> = " << Fibonacci<10>::value << "\n";
    std::cout << "Fibonacci<15> = " << Fibonacci<15>::value << "\n";    
    
    return (0);
}