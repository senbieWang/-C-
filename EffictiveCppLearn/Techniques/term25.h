#pragma once
//�����ʵʱ��Ϣ
class NLComponent 
{
public:
	virtual void  fun() = 0;
};

//��������
class TextBlock :public NLComponent  
{
public:

};

//ͼƬ����
class Griphic : public NLComponent 
{
public:

};

//���ű�־ �������� �������š�ͼƬ������ɣ�
class NewLetter 
{
public:
	NewLetter(std::istream& str);  //��stream�ж�ȡ����
private:
	static NLComponent* readComponent(std::istream& str);
private:
	std::list<NLComponent*>  components;
};