#include <iostream>                 // std                
// #include <boost/thread/mutex.hpp>   // mutex
#include <pthread.h>                // thread

#include "scopedlock.hpp"           // ScopedLock
#include "test_func.hpp"            // CheckValue

static const size_t thread_num = 5;
static size_t sherd_i = 0;
// static boost::mutex m;

using namespace std;
using namespace ilrd_166_7;

/*************************Forward-Declaration*******************************/

// static int TestInt(void);
static int TestMutex(void);
static int TestLockClass(void);
static int TestThreads(void);
void* Worker(void* index);

/*******************************Main*************************************/

int main()
{
    int status = 0;

    // status += TestInt();
	status += TestMutex();
    status += TestLockClass();
    status += TestThreads();
    
    (status == 0) ? (cout << "\033[0;32mAll Good!\033[0m\n") : 
                    (cout << "\033[0;31m" << status << " FAILS! \033[0mTotal\n");

	return (0);
}

/*************************Static-Functions*******************************/

/* static int TestInt(void) 
{
    int status = 0;
	
    int m = 10;

    ScopedLock<int> lock(m);

    return (status);
} */

static int TestMutex(void) 
{
    int status = 0;

    // ScopedLock<boost::mutex> lock(m);

    return (status);
}

static int TestLockClass(void) 
{
    int status = 0;
    
    cout << endl;

    LockClass m;

    ScopedLock<LockClass> lock(m);

    return (status);
}

static int TestThreads(void) 
{
    int status = 0;

    pthread_t th_id[thread_num] = {0};

    cout << endl;

    for (size_t i = 0; i < thread_num; ++i)
    {
		pthread_create(&th_id[i], NULL, &Worker, (void*)i);
	}

	for(size_t i = 0; i < thread_num; ++i)
	{
		pthread_join(th_id[i], NULL);
	}

    return (status);
}

/**********************************************************************************************/

/*Worker*/
void* Worker(void* index)
{
    // ScopedLock<boost::mutex> lock(m);

    ++sherd_i;

    cout << "Thread: " << (size_t)index << "    |   sherd_i: " << sherd_i << endl;
    // sleep(1);

    return (NULL);
}