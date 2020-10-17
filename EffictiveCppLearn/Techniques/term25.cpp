#include"stdafx.h"
#include"term25.h"


NewLetter::NewLetter(std::istream& str)
{
	while (str)
	{
		NLComponent* res= readComponent(str);
		if(res)
			components.push_back(res);
	}
}


NewLetter::NewLetter(const NewLetter& rhs)
{
	for (auto it = rhs.components.begin(); it != rhs.components.end(); ++it) 
	{
		components.push_back((*it)->clone());
	}
}


void NewLetter::print()
{
	for (auto it = components.begin(); it != components.end(); ++it)
	{
		//NLComponent& ss = *(*it);
		std::cout << *(*it);
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


