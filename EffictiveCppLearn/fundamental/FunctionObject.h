#pragma once
/*���������ѧϰ
 ��������ʵ�ʾ��Ǹ�ĳ���ඨ����һϵ�еģ�û�о������Ƶĺ�������Щ��������ͨ������ֱ�ӵ��á�
 ���Ҳ�У����ص����������
*/
class SumObject
{
public:
	SumObject() {}
	SumObject(int a, int b);
	int  operator()(int a,int b);
	double  operator()(double a, double b);
};

