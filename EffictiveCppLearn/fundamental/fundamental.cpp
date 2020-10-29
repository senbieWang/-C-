#include <iostream>
#include"FunctionObject.h"
int main()
{
	SumObject sum(10,15);
    std::cout << SumObject()(10,15)<<"Hello World!\n";
}
