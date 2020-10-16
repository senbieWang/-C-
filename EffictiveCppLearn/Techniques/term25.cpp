#include"stdafx.h"
#include"term25.h"


NewLetter::NewLetter(std::istream& str)
{
	while (str)
	{
		components.push_back(readComponent(str));
	}
}

//产生一个 textblock  或者  graphic 对象，具体由读入的 str来决定，
//由于产生新对象，所以行为放入  constructor,由于能产生不同类型的对象， 可以视为 virtual constructor.
NLComponent* NewLetter::readComponent(std::istream& str) 
{
	//if str == graph  new Griphic
	//if str == textblock  new TextBlock
}