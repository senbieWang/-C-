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


//产生一个 textblock  或者  graphic 对象，具体由读入的 str来决定，
//由于产生新对象，所以行为放入  constructor,由于能产生不同类型的对象， 可以视为 virtual constructor.
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


