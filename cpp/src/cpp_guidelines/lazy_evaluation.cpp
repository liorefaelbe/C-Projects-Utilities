#include <iostream>     // cout, endl
#include <vector>       // vector

using namespace std;

static const int ONE_MEGA = 1024*1024;
/* 
template<typename T, size_t SIZE>
class Sum2Vectors
{
public:
    Sum2Vectors(const vector<T>& v1 , const vector<T>& v2);
    const T& operator[](size_t index);
private:
    vector<T> m_vector_sum;
};

template<typename T, size_t SIZE>
Sum2Vectors<T,SIZE>::Sum2Vectors(const vector<T>& v1 , const vector<T>& v2)
{
    m_vector_sum.reserve(SIZE);
    for (size_t i = 0 ; i < SIZE ; ++i)
    {
        m_vector_sum[i] = v1[i] + v2[i];
    }
}

template<typename T,size_t SIZE>
const T& Sum2Vectors<T,SIZE>::operator[](size_t index)
{
    return (m_vector_sum[index]);
} */

template<typename T, size_t SIZE>
class Sum2Vectors
{
public:
    Sum2Vectors(const std::vector<T>& v1 , const std::vector<T>& v2) : m_v1(v1), m_v2(v2) {}

    T operator[](size_t index) const
    {
        return m_v1[index] + m_v2[index];
    }

private:
    const std::vector<T>& m_v1;
    const std::vector<T>& m_v2;
};

int main()
{
    vector<int> v_a;
    v_a.reserve(ONE_MEGA);

    vector<int> v_b;
    v_b.reserve(ONE_MEGA);

    v_a[102] = 5;
    v_b[102] = 3;

    Sum2Vectors<int,ONE_MEGA> sum(v_a,v_b);
   
    cout << "v_a[102] : " << v_a[102] << endl;
    cout << "v_b[102] : " << v_b[102] << endl;
    cout << "sum : " << sum[102] << endl;

    return (0);
}