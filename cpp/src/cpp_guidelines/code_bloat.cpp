#include <string>   // string
#include <iostream> // cout

using namespace std;

void PrintNumbersUpToSizeof(std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        std::cout << i << ",";
    }
    std::cout << std::endl;
}

template <typename T>
void PrintNumbersUpToSizeof()
{
    PrintNumbersUpToSizeof(sizeof(T));
}

struct Person
{
    string name;
};

struct Point
{
    float x;
    float y;
};

int main()
{ 
    PrintNumbersUpToSizeof<char>();
    PrintNumbersUpToSizeof<short>();
    PrintNumbersUpToSizeof<int>();
    PrintNumbersUpToSizeof<long>();
    PrintNumbersUpToSizeof<float>();
    PrintNumbersUpToSizeof<double>();
    PrintNumbersUpToSizeof<void*>();
    PrintNumbersUpToSizeof<string>();
    PrintNumbersUpToSizeof<Person>();
    PrintNumbersUpToSizeof<Point>();

    return (0);
}