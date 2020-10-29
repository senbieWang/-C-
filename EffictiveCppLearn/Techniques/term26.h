#pragma once

class  Printer 
{
public:
	class TooManyObject {};
	static Printer* Create();
	static Printer* Create(const Printer& rhs);
	~Printer();  //把create的对象放到智能指针中,智能指针对象到期不会自动释放。 ？？？？
private:
	static size_t numObjects;
	const static size_t maxObjects = 10;
	Printer();              //构造和 拷贝 不让外部使用
	Printer(const Printer& rhs);
	
};