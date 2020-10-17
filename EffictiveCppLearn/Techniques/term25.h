#pragma once
//�����ʵʱ��Ϣ
class NLComponent 
{
public:
	virtual void  fun() = 0;
	virtual NLComponent* clone() const = 0;
	virtual std::ostream& print(std::ostream& s) const = 0;
};

//��������
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

//ͼƬ����
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


//���ű�־ �������� �������š�ͼƬ������ɣ�
class NewLetter 
{
public:
	NewLetter(std::istream& str);  //��stream�ж�ȡ����
	NewLetter(const NewLetter& rhs);
	void print();
private:
	static NLComponent* readComponent(std::istream& str);  //virtual constructor 
private:
	std::list<NLComponent*>  components;
};