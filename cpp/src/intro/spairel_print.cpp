#include <iostream>     // cout
#include <string>       // string
#include <algorithm>    // for_each
#include <array>        // array
#include <list>         // list
#include <iomanip>      // setw()

using namespace std;

/************************* Forward Declarations ************************/

template<size_t Rows, size_t Cols>
list<int> GetSpiralTraversal(const array<array<int, Cols>, Rows>& matrix); 

template<size_t Rows, size_t Cols>
void FillMatrix(array<array<int, Cols>, Rows>& matrix);

template<size_t Rows, size_t Cols>
void PrintMatrix(const array<array<int, Cols>, Rows>& matrix, const string& label);
void PrintList(const list<int>& vec, const string& label);

/******************************* Main **********************************/

int main() 
{
    constexpr size_t SIZE1 = 4;
    constexpr size_t SIZE2 = 4;
    auto matrix = array<array<int, SIZE2>, SIZE1>{};

    FillMatrix(matrix);
    PrintMatrix(matrix, "\033[1mMatrix:\033[0m");

    auto spiral = GetSpiralTraversal(matrix);

    PrintList(spiral, "\n\033[1mSpiral Order (starting from middle, outwards):\033[0m");
    
    return (0);
}

/*************************** Implementations ***************************/

template<size_t Rows, size_t Cols>
list<int> GetSpiralTraversal(const array<array<int, Cols>, Rows>& matrix) 
{
    list<int> result;

    int size = Rows * Cols;

    int top = 0;
    int bottom = Rows - 1;
    int left = 0;
    int right = Cols - 1;

    while (size > 0)
    {
        for (int i = left; i <= right && size > 0; ++i)
        {
            result.push_front(matrix[top][i]);
            --size;
        }
        ++top;

        for (int i = top; i <= bottom && size > 0; ++i)
        {
            result.push_front(matrix[i][right]);
            --size;
        }
        --right;

        for (int i = right; i >= left && size > 0; --i)
        {
            result.push_front(matrix[bottom][i]);
            --size;
        }
        --bottom;

        for (int i = bottom; i >= top && size > 0; --i)
        {
            result.push_front(matrix[i][left]);
            --size;
        }
        ++left;
    }
    
    return (result);
}

template<size_t Rows, size_t Cols>
void FillMatrix(array<array<int, Cols>, Rows>& matrix)
{
    int value = 1;
    for (auto& row : matrix) 
    {
        for (auto& cell : row) 
        {
            cell = value++;
        }
    }
}

template<size_t Rows, size_t Cols>
void PrintMatrix(const array<array<int, Cols>, Rows>& matrix, const string& label)
{
    cout << label << endl;
    for (const auto& row : matrix)
    {
        for (const auto& cell : row)
        {
            if (cell % 2 == 0)
            {
                cout << "\033[1m\033[32m" << setw(3) << cell << " \033[0m";
            }
            else
            {
                cout << "\033[1m\033[7m\033[35m" << setw(3) << cell << " \033[0m";
            }
        }
        cout << "\033[0m" << endl;
    }
}

void PrintList(const list<int>& list, const string& label)
{
    cout << label << endl;
    for (const auto& num : list)
    {
        cout << num << " ";
    }
    cout << endl;
}