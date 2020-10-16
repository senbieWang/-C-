#pragma once
//�����ʵʱ��Ϣ
class NLComponent 
{
public:
	virtual void  fun() = 0;
	virtual NLComponent* clone() const = 0;
};

//��������
class TextBlock :public NLComponent  
{
public:
	void  fun() {}
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
	virtual Griphic* clone() const
	{
		std::cout << "Griphic clone" << std::endl;
		return new Griphic(*this);
	}

};

//���ű�־ �������� �������š�ͼƬ������ɣ�
class NewLetter 
{
public:
	NewLetter(std::istream& str);  //��stream�ж�ȡ����
	NewLetter(const NewLetter& rhs);
private:
	static NLComponent* readComponent(std::istream& str);  //virtual constructor 
private:
	std::list<NLComponent*>  components;
};