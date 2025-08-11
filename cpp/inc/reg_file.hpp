#ifndef __ILRD_REG_FILE_HPP__
#define __ILRD_REG_FILE_HPP__

#include "file.hpp" // File

namespace ilrd_166_7
{
class RegFile : public File
{
public:
    explicit RegFile(const string& file_name = "Untitled", const string& content = "");
    virtual ~RegFile();
    virtual void Print();
    virtual File* Clone();
private:
    string m_content;
};

} // namespace ilrd_166_7

#endif //__ILRD_REG_FILE_HPP__