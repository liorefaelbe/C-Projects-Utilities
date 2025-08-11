#ifndef __ILRD_FILE_HPP__
#define __ILRD_FILE_HPP__

#include <string> // string

using namespace std;

namespace ilrd_166_7
{
class File
{
public:
    explicit File(const string& file_name = "Untitled");
    virtual ~File();

    const string& GetFileName() const;
    void Rename(const string& str);

    virtual void Print() = 0;
    virtual File* Clone() = 0;
private:
    string m_file_name;
};

} // namespace ilrd_166_7

#endif //__ILRD_FILE_HPP__