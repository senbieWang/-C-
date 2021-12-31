#pragma once
#include<iostream>
namespace  MyCPP2 
{
	/*
	要点:
	1、数量不定的 模板参数  函数
	   ...  就是所谓的包 package
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

	//标准库   tuple就是基于该方式的定义



};

