#include"stdafx.h"
#include"term25.h"


NewLetter::NewLetter(std::istream& str)
{
	while (str)
	{
		components.push_back(readComponent(str));
	}
}


NewLetter::NewLetter(const NewLetter& rhs)
{
	for (auto it = rhs.components.begin(); it != rhs.components.end(); ++it) 
	{
		components.push_back((*it)->clone());
	}
}


//����һ�� textblock  ����  graphic ���󣬾����ɶ���� str��������
//���ڲ����¶���������Ϊ����  constructor,�����ܲ�����ͬ���͵Ķ��� ������Ϊ virtual constructor.
NLComponent* NewLetter::readComponent(std::istream& str) 
{
	int type = 0;
	str >> type;
	if (type == 1)
	{
		return new TextBlock();
	}

	if (2 == type)
	{
		return new Griphic();
	}
	return nullptr;
}


