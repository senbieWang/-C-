#pragma once
//抽象的实时信息
class NLComponent 
{
public:
	virtual void  fun() = 0;
};

//文字新闻
class TextBlock :public NLComponent  
{
public:

};

//图片新闻
class Griphic : public NLComponent 
{
public:

};

//新闻报志 （可能由 文字新闻、图片新闻组成）
class NewLetter 
{
public:
	NewLetter(std::istream& str);  //从stream中读取新闻
private:
	static NLComponent* readComponent(std::istream& str);
private:
	std::list<NLComponent*>  components;
};