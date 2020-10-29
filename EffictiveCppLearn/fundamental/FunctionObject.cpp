#include "FunctionObject.h"

SumObject::SumObject(int a, int b)
{

}

int SumObject::operator()(int a, int b)
{
	return a + b;
}

double  SumObject::operator()(double a, double b) 
{
	return a + b;
}