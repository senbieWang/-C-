#pragma once
#include<iostream>
#include<vector>
namespace  MyCPP2 
{
	/***************************************************************
	1、数量不定的 模板参数 函数   标准库   tuple就是基于该方式的定义
	*/

	// 函数1    模板函数递归结束的时候调用。
	void  print()
	{

	}
	// 函数2 
	template  <typename T, typename... Types>   //...  Types 是任意数量的 
	void  print(const T& firstArg, const Types&... args)    //任意个数的参数化
	{
		std::cout << firstArg << "  "<<sizeof...(args)<<std::endl;  //参数包有几个参数
		print(args...);
	}

	// 函数3   可以与函数2的并存， 调用的时候会优先调用 函数2
	template  <typename... Types>   //...  Types 是任意数量的 
	void  print(const Types&... args)    //任意个数的参数化
	{
		std::cout << sizeof...(args) << std::endl;  //参数包有几个参数
		print(args...);
	}

	/****************************************************************
	2、模板函数 只有全特化、没有偏特化
	*/
	template<class T>
	void  funtest(T var) 
	{
		std::cout << "var1" << std::endl;
	}

	//基于指针的特化  错误，函数模板只有全特化
	//template<class T>
	//void  funtest<T*>(T var)
	//{
	//	std::cout << "var2" << std::endl;
	//}

	//全特化
	template<>
	void  funtest(int var)
	{
		std::cout << "var4" << std::endl;
	}


	/****************************************************************
	3、类模板全特化、偏特化
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

	//转换为绝对类型
	template<>
	class ATemp<int,float>
	{
	public:
		static void  print(const   int lh, const  float rh)
		{
			std::cout << "T2" << "Y2" << std::endl;
		}
	};

	//特化为指针，引用，const 类型
	template<class T, class Y>
	class ATemp<T*,Y*>
	{
	public:
		static void  print(const  T lh, const  Y rh)
		{
			std::cout << "T3" << "Y4" << std::endl;
		}
	};


	//特化为另一个模板
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

