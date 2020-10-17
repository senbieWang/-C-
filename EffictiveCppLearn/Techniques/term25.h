#pragma once
//抽象的实时信息
class NLComponent 
{
public:
	virtual void  fun() = 0;
	virtual NLComponent* clone() const = 0;
	virtual std::ostream& print(std::ostream& s) const = 0;
};

//文字新闻
class TextBlock :public NLComponent  
{
public:
	void  fun() {}

	virtual std::ostream& print(std::ostream& s) const
	{
		s << "TextBlock print" <<std::endl;
		return s;
	}

	virtual TextBlock* clone() const  //virtual  copy constructor
	{
		std::cout << "TextBlock clone" << std::endl;
		return new TextBlock(*this);
	}



};

//图片新闻
class Griphic : public NLComponent 
{
public:
	void  fun() {}

	virtual std::ostream& print(std::ostream& s) const
	{
		s << "Griphic print" << std::endl;
		return s;
	}

	virtual Griphic* clone() const
	{
		std::cout << "Griphic clone" << std::endl;
		return new Griphic(*this);
	}

};

inline std::ostream& operator<<(std::ostream& s, const NLComponent& c) 
{
	return c.print(s);
}


//新闻报志 （可能由 文字新闻、图片新闻组成）
class NewLetter 
{
public:
	NewLetter(std::istream& str);  //从stream中读取新闻
	NewLetter(const NewLetter& rhs);
	void print();
private:
	static NLComponent* readComponent(std::istream& str);  //virtual constructor 
private:
	std::list<NLComponent*>  components;
};