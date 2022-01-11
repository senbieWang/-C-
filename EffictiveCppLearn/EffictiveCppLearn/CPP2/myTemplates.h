#pragma once
#include<iostream>
#include<vector>
namespace  MyCPP2 
{
	/***************************************************************
	1������������ ģ����� ����   ��׼��   tuple���ǻ��ڸ÷�ʽ�Ķ���
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

	/****************************************************************
	2��ģ�庯�� ֻ��ȫ�ػ���û��ƫ�ػ�
	*/
	template<class T>
	void  funtest(T var) 
	{
		std::cout << "var1" << std::endl;
	}

	//����ָ����ػ�  ���󣬺���ģ��ֻ��ȫ�ػ�
	//template<class T>
	//void  funtest<T*>(T var)
	//{
	//	std::cout << "var2" << std::endl;
	//}

	//ȫ�ػ�
	template<>
	void  funtest(int var)
	{
		std::cout << "var4" << std::endl;
	}


	/****************************************************************
	3����ģ��ȫ�ػ���ƫ�ػ�
	*/
	template<class T, class Y>
	class ATemp 
	{
	public:
		static void  print(const   T lh, const   Y rh)
		{
			std::cout << "T1" << "Y1" << std::endl;
		}
	};

	//ת��Ϊ��������
	template<>
	class ATemp<int,float>
	{
	public:
		static void  print(const   int lh, const  float rh)
		{
			std::cout << "T2" << "Y2" << std::endl;
		}
	};

	//�ػ�Ϊָ�룬���ã�const ����
	template<class T, class Y>
	class ATemp<T*,Y*>
	{
	public:
		static void  print(const  T lh, const  Y rh)
		{
			std::cout << "T3" << "Y4" << std::endl;
		}
	};


	//�ػ�Ϊ��һ��ģ��
	template<class T, class Y>
	class ATemp <std ::vector<T>, Y>
	{
	public:
		static void  print(const  T lh, const  Y rh)
		{
			std::cout << "T5" << "Y5" << std::endl;
		}
	};



};

