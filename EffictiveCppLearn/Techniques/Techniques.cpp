#include "stdafx.h"
#include "term25.h"
#include "term26.h"
using namespace std;



int main()
{
	// term25
	//NewLetter  ss(std::cin);
	//NewLetter  ss2 = ss;
	//ss2.print();
 //   std::cout << "Hello World!\n";

	// term26
	{
		std::shared_ptr<Printer>  Sptr( Printer::Create());   //会自动析构
	}

}
