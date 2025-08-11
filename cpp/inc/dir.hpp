#ifndef __ILRD_DIR_HPP__
#define __ILRD_DIR_HPP__

#include <set> // set

#include "file.hpp" // File

namespace ilrd_166_7
{
class Dir : public File
{
public:
    explicit Dir(const string& dir_name = "Untitled");
    virtual ~Dir();

    virtual void Print();
    virtual File* Clone();

    void AddFile(File* const file);
    void RemoveFile(File* file);
private:
    set<File*> m_set;
};

} // namespace ilrd_166_7

#endif //__ILRD_DIR_HPP__