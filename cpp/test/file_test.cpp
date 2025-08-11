#include <iostream> // std
#include <cstring> // strcmp

#include "file.hpp" // File
#include "dir.hpp" // Dir
#include "reg_file.hpp" // RegFile
#include "test_func.hpp" // CheckValue

using namespace std;
using namespace ilrd_166_7;

/*************************Forward-Declaration*******************************/

static int Test(void);

/*******************************Main****************************************/

int main()
{
    int status = 0;
    
    status += Test();
    
    (status == 0) ? (cout << "\033[0;32mAll Good!\033[0m\n") : 
                    (cout << "\033[0;31m" << status << " FAILS! \033[0mTotal\n");
    
    return (0);
}

/*****************************Static-Functions******************************/

static int Test(void) 
{
    int status = 0;
    
	RegFile f1;
    string str("Untitled");
	
    status += CheckValue(f1.GetFileName(), str, "Ctor" , __LINE__);

    str = "f1";
    f1.Rename(str);

    status += CheckValue(f1.GetFileName(), str, "FileRename" , __LINE__);


	RegFile a("File_1", "twas brillig in the slithy toves");
	RegFile b("File_3", "All mimsy were the borogoves, and the mome raths outgrabe.");
	RegFile c("File_2", "beware the jaberwock my son, the jaws that bite the claws that catch");
	RegFile d("File_5", "Beware the jubjub bird and shun the frumious bandersnatch");
	RegFile e("File_4", "He took his vorpal sword in hand; long time the manxome foe he sought—");
	
	Dir dir1("DIR_1");
	Dir dir2("DIR_2");
	Dir dir3("DIR_3");
	
	dir1.AddFile(&a);
	dir1.AddFile(&b);
	dir1.AddFile(&c);
	
	dir1.AddFile(&dir2);
	
	dir2.AddFile(&d);
	dir2.AddFile(&dir3);
	dir3.AddFile(&e);
	dir1.Print();
	
	dir1.RemoveFile(&a);
	dir2.RemoveFile(&d);

	b.Rename("a ridiculous name if there ever was one");
	
	cout << "....................." << endl;
	File* x = a.Clone();
	x->Print();
	cout << "....................." << endl;
	File* z = dir1.Clone();
	z->Print();
	
	delete x;
    delete z;
	
    return (status);
}