#pragma once
#include<iostream>
namespace  MyCPP2 
{
	/*
	Ҫ��:
	1������������ ģ�����  ����
	   ...  ������ν�İ� package
	*/

	// ����1    ģ�庯���ݹ������ʱ����á�
	void  print()
	{

	}
	// ����2 
	template  <typename T, typename... Types>   //...  Types ������������ 
	void  print(const T& firstArg, const Types&... args)    //��������Ĳ�����
	{
		std::cout << firstArg << "  "<<sizeof...(args)<<std::endl;  //�������м�������
		print(args...);
	}

	// ����3   �����뺯��2�Ĳ��棬 ���õ�ʱ������ȵ��� ����2
	template  <typename... Types>   //...  Types ������������ 
	void  print(const Types&... args)    //��������Ĳ�����
	{
		std::cout << sizeof...(args) << std::endl;  //�������м�������
		print(args...);
	}

	//��׼��   tuple���ǻ��ڸ÷�ʽ�Ķ���



};

