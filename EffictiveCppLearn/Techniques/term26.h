#pragma once

class  Printer 
{
public:
	class TooManyObject {};
	static Printer* Create();
	static Printer* Create(const Printer& rhs);
	~Printer();  //��create�Ķ���ŵ�����ָ����,����ָ������ڲ����Զ��ͷš� ��������
private:
	static size_t numObjects;
	const static size_t maxObjects = 10;
	Printer();              //����� ���� �����ⲿʹ��
	Printer(const Printer& rhs);
	
};