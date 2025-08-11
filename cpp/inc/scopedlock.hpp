#ifndef __ILRD_SCOPEDLOCK_HPP__
#define __ILRD_SCOPEDLOCK_HPP__

#include <iostream> // std

using namespace std;

namespace ilrd_166_7
{
template <typename T>
class ScopedLock
{
    public:
        explicit ScopedLock(T& lock) : m_lock(lock) 
        {
            m_lock.lock();
            // cout << "locked\n";
        }
        ~ScopedLock()
        {
            m_lock.unlock();
            // cout << "unlocked\n";
        }

    private:
        T& m_lock;
        ScopedLock& operator=(const ScopedLock& other); // non-copyable
        ScopedLock(const ScopedLock& other); // non-copyable
};

class LockClass
{
public:
    void lock() { cout << "locked\n"; }
    void unlock(){ cout << "unlocked\n"; }
};

} // namespace ilrd_166_7

#endif //__ILRD_REG_FILE_HPP__