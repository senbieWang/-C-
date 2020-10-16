#pragma once
//抽象的实时信息
class NLComponent 
{
public:
	virtual void  fun() = 0;
	virtual NLComponent* clone() const = 0;
};

//文字新闻
class TextBlock :public NLComponent  
{
public:
	void  fun() {}
	virtual TextBlock* clone() const  //virtual  copy constructor
	{
		return new TextBlock(*this);
	}
};

//图片新闻
class Griphic : public NLComponent 
{
public:
	void  fun() {}
	virtual Griphic* clone() const
	{
		return new Griphic(*this);
	}

};

//新闻报志 （可能由 文字新闻、图片新闻组成）
class NewLetter 
{
public:
	NewLetter(std::istream& str);  //从stream中读取新闻
	NewLetter(const NewLetter& rhs);
private:
	static NLComponent* readComponent(std::istream& str);  //virtual constructor 
private:
	std::list<NLComponent*>  components;
};