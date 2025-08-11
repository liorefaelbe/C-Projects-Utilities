/*
	Author: Lior Refael Berkovits
	Reviewed by: Dana
	Date: 01/04/2025
*/

#include <iostream> // ostream, istream

#include "file.hpp"

using namespace std;
namespace ilrd_166_7
{

/***********************************Constractors****************************************************/

File::File(const string& file_name) : m_file_name(file_name) { /* empty */ }

File::~File() { /* empty */ }

/***********************************Member Functions************************************************/

const string& File::GetFileName() const
{
    return (m_file_name);
}

void File::Rename(const string& file_name)
{
    m_file_name = file_name;
}
}