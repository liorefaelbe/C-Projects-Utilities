#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <pthread.h>
#include <unistd.h>
#include <cmath>
#include <sstream>

using namespace std;

// Mutexes
pthread_mutex_t log_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t cache_mutex = PTHREAD_MUTEX_INITIALIZER;

// 1. Square
double Square(double x) 
{
    return (x * x);
}

// 2. Log (thread-safe)
void Log(const string& log) 
{
    static FILE* log_file = fopen("log.txt", "w");

    pthread_mutex_lock(&log_mutex);

    fprintf(log_file, "%s\n", log.c_str());
    fflush(log_file);

    pthread_mutex_unlock(&log_mutex);
}

// 3. UpdateData (thread-local vector)
thread_local vector<int> g_vector;

void UpdateData(int data) 
{
    g_vector.push_back(data);
    cout << "Thread " << pthread_self() << " added: " << data << "\n";
}

// 4. Calculate (thread-safe cache)
double Calculate(double x, double y) 
{
    static bool cached = false;
    static double result_cache_x, result_cache_y, result_cache;

    pthread_mutex_lock(&cache_mutex);
    if (cached && result_cache_x == x && result_cache_y == y) 
    {
        cout << "Cache hit for (" << x << ", " << y << ")\n";
        double result = result_cache;
        pthread_mutex_unlock(&cache_mutex);

        return (result);
    }
    pthread_mutex_unlock(&cache_mutex);

    double result = sqrt(x * x + y * y);

    pthread_mutex_lock(&cache_mutex);
    result_cache_x = x;
    result_cache_y = y;
    result_cache = result;
    cached = true;
    cout << "Cache updated for (" << x << ", " << y << ")\n";
    pthread_mutex_unlock(&cache_mutex);

    return (result);
}

// Thread Function
void* ThreadTask(void* arg) 
{
    int id = *(int*)arg;

    // // 1. Square
    // double sq = Square(id);
    // cout << "Square(" << id << ") = " << sq << "\n";

    // // 2. Log
    // stringstream ss;
    // ss << "Logging from thread " << id;
    // Log(ss.str());

    // // 3. UpdateData
    // UpdateData(id);

    // 4. Calculate
    double result = Calculate(id * 1.1, id * 2.2);
    cout << "Calculate(" << id * 1.1 << ", " << id * 2.2 << ") = " << result << "\n";

    return (NULL);
}

/*******************************Main*************************************/

int main() 
{
    const int threds_num = 4;
    pthread_t threads[threds_num];
    int ids[threds_num];

    for (int i = 0; i < threds_num; ++i) 
    {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, ThreadTask, &ids[i]);
    }

    for (int i = 0; i < threds_num; ++i) 
    {
        pthread_join(threads[i], NULL);
    }

    cout << "All threads complete.\n";

    return (0);
}
