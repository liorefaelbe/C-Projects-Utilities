/*
	Author: Lior Refael Berkovits
	Reviewed by: Dana
	Date: 01/04/2025
*/

#include <iostream> // ostream, istream

#include "dir.hpp"

using namespace std;
namespace ilrd_166_7
{

const size_t indent_size = 2;

/***********************************Constractors****************************************************/

Dir::Dir(const string& str) : File(str) { /* empty */ }

Dir::~Dir() { /* empty */ }

/***********************************Member Functions************************************************/

void Dir::Print()
{
	static size_t indent = 0;

	set<File*>::iterator it = m_set.begin();
    set<File*>::iterator end = m_set.end();

	cout << "\033[34m" << GetFileName() << "\033[0m" << endl;

	indent += indent_size;
	for (; it != end; ++it)
	{
		cout << string(indent, ' ');
		cout << "|";

		(*it)->Print();
	}
	indent -= indent_size;
}

File* Dir::Clone()
{
	return (new Dir(*this));
}

void Dir::AddFile(File* const file)
{
    m_set.insert(file);
}

void Dir::RemoveFile(File* file)
{
    m_set.erase(file);
}
}
