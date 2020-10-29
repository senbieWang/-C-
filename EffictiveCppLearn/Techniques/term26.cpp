#include"stdafx.h"
#include"term26.h"

size_t Printer::numObjects = 0;

Printer* Printer::Create()
{
	return new Printer();
}

Printer* Printer::Create(const Printer& rhs)
{
	return new Printer(rhs);
}

Printer::~Printer() 
{
	numObjects--;
	std::cout << "deconstrcuter object = " << numObjects << std::endl;	
}

Printer::Printer() 
{
	if (numObjects > maxObjects)
	{
		throw TooManyObject();
	}
	numObjects++;
	//��Ա������ʼ��
	std::cout << "create object num = " << numObjects << std::endl;
}

Printer::Printer(const Printer& rhs)
{
	if (numObjects > maxObjects)
	{
		throw TooManyObject();
	}
	numObjects++;
	//��Ա��������
	std::cout << "create  res object num = " << numObjects << std::endl;
}

