/*
	Author: Lior Refael Berkovits
	Reviewed by: Dana
	Date: 01/04/2025
*/

#include <iostream>     // ostream
#include <string>       // memcpy

#include "reg_file.hpp" // RegFile

using namespace std;
namespace ilrd_166_7
{

/***********************************Constractors****************************************************/

RegFile::RegFile(const string& file_name, const string& content) : File(file_name), m_content(content) { /* empty */ }

RegFile::~RegFile() { /* empty */ }

/***********************************Member Functions************************************************/

void RegFile::Print()
{
	cout << "\033[32m" << GetFileName() << "\033[0m";
	cout << " (\033[33mContent: " << m_content << "\033[0m)" << endl;
}

File* RegFile::Clone()
{
	return (new RegFile(*this));
}
}
