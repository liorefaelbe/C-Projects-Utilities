#ifndef __ILRD_SHARED_PTR_HPP__
#define __ILRD_SHARED_PTR_HPP__

#include <cstddef>  // size_t 

using namespace std;

namespace ilrd_166_7
{
template <typename T>
class SharedPtr
{
public:
    explicit SharedPtr(T* ptr) : m_ptr(ptr), m_ref_counter(new size_t(1)) { /* empty */ }
    ~SharedPtr() { Release(); }

    SharedPtr(const SharedPtr& other) : m_ptr(other.m_ptr), m_ref_counter(other.m_ref_counter) 
    {
        ++(*m_ref_counter);
    }
    
    template <typename X>
    SharedPtr(const SharedPtr<X>& other) : m_ptr(other.m_ptr), m_ref_counter(other.m_ref_counter) 
    {
        ++(*m_ref_counter);
    }
    template <typename X>
    friend class SharedPtr;

    SharedPtr& operator=(const SharedPtr& other)
    {
        SharedPtr tmp(other);
        swap(m_ptr, tmp.m_ptr);
        swap(m_ref_counter, tmp.m_ref_counter);
    
        return (*this);
    }   

    T* operator->() const { return (m_ptr); }
    T& operator*() const { return (*m_ptr); }
    
    size_t GetUseCount() { return (*m_ref_counter); }

private:
    T* m_ptr;
    size_t* m_ref_counter;

    void Release() 
    {
        if(*m_ref_counter > 1)
        {
            --(*m_ref_counter);
        }
        else
        { 
            delete m_ptr;
            m_ptr = nullptr;
            delete m_ref_counter;
            m_ref_counter = nullptr;
        }
    }

    void* operator new(size_t);
};
} // namespace ilrd_166_7

#endif //__ILRD_SHARED_PTR_HPP__