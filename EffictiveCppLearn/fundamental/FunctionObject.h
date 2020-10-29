#pragma once
/*函数对象的学习
 函数对象：实际就是给某个类定义了一系列的，没有具体名称的函数，这些函数可以通过对象直接调用。
 因此也叫，重载调用用算符。
*/
class SumObject
{
public:
	SumObject() {}
	SumObject(int a, int b);
	int  operator()(int a,int b);
	double  operator()(double a, double b);
};

