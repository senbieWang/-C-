#include"stdafx.h"
#include"term25.h"


NewLetter::NewLetter(std::istream& str)
{
	while (str)
	{
		components.push_back(readComponent(str));
	}
}

//����һ�� textblock  ����  graphic ���󣬾����ɶ���� str��������
//���ڲ����¶���������Ϊ����  constructor,�����ܲ�����ͬ���͵Ķ��� ������Ϊ virtual constructor.
NLComponent* NewLetter::readComponent(std::istream& str) 
{
	//if str == graph  new Griphic
	//if str == textblock  new TextBlock
}