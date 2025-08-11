#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <pthread.h>
#include <unistd.h>
#include <cmath>
#include <sstream>

using namespace std;

// a.
double Square(double x)
{
    return x * x;
}

// b.
void Log(const string& log)
{
    static FILE* log_file = fopen("log.txt", "w");
    
    fprintf(log_file, "%s\n", log.c_str());
}

// c.
std::vector<int> g_vector;
void UpdateData(int data)
{
    g_vector.push_back(data);
}

// d.
double Calculate(double x,double y)
{
    static bool cached = false;
    static double result_cache_x;
    static double result_cache_y;
    static double result_cache;

    if (cached && result_cache_x == x && result_cache_y == y)
    {
        return (result_cache);
    }

    double result = sqrt(x * x + y * y);

    result_cache_x = x;
    result_cache_y = y;
    result_cache = result;
    cached = true;  

    return (result);
}

// Thread Function
void* ThreadTask(void* arg) 
{
    int id = *(int*)arg;

    // 1. Square
    double sq = Square(id);
    cout << "Square(" << id << ") = " << sq << "\n";

    // 2. Log
    stringstream ss;
    ss << "Logging from thread " << id;
    Log(ss.str());

    // 3. UpdateData
    UpdateData(id);

    // 4. Calculate
    double result = Calculate(id * 1.1, id * 2.2);
    cout << "Calculate(" << id * 1.1 << ", " << id * 2.2 << ") = " << result << "\n";

    return (NULL);
}

/*******************************Main*************************************/

int main() 
{
    const int NUM_THREADS = 4;
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) 
    {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, ThreadTask, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i) 
    {
        pthread_join(threads[i], NULL);
    }

    cout << "All threads complete.\n";

    return (0);
}
