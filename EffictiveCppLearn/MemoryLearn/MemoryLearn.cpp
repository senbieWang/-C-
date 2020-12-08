// operator new  operator delete

#include <iostream>

class MyMemoryClass 
{
public:
	//operator new   会隐藏系统定义的new  和placement new
	void* operator new(size_t size) 
	{
		return ::operator new(size);
	}

	void operator delete(void *ptr) 
	{
		::operator delete(ptr);
	}

	//palcement new   C++ 提供了实现 ，用户可以直接使用， 用户冲在了 placementnew  必须实现 placementselete
	//void* operator new(size_t size, void* ptr)
	//{
	//	return ptr;
	//}

	//void operator delete(void* pmemory, void* ptr)
	//{
	//	return;
	//}

	MyMemoryClass() 
	{
		int xxx = 0;
	}

	~MyMemoryClass()
	{
		int xxx = 0;
	}
private:
	int x;
};

int main()
{
	{
		//new operator 
		MyMemoryClass* dd = new MyMemoryClass();  //1、先调用重载的operator new    2、调用MyMemoryClass() 构造函数
		delete dd;   //1、先调用析构  2、调用重载的 operator delete

		//placement new
		//char *ptr = new char(sizeof(MyMemoryClass)*10);
		//MyMemoryClass* pnew = new(ptr)MyMemoryClass();
	}
	std::cout << "Hello World!\n";
}

