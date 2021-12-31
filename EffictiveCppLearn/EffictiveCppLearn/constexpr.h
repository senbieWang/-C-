#pragma once
#include <type_traits>
/*
   �������ʽ��C++11�� C++14
   1�����������㹻�������ڱ�����ȥ����constexpr���εı��ʽ���Ż��������⵽func�Ĳ�����һ����������ֵ��ʱ��
      �������Ż�ȥ�������Ż���������Ȼ�Ὣ����������������ʱ����
   2������������ԣ�constexpr�����Ա�����ʵ�ֱ����ڵ�type traits������STL�е�is_const������ʵ�֣�
   3��constexpr ���Ϊ�����ĳ������ڱ����ڼ���㣻  ����ǳ������������ڼ��㡣   �ôʴ����ԣ������ж�
      һ��ĳ������ ����Ƿ��г�������
*/

//�����ڼ���Լ����Ϊ����
constexpr int func() 
{
    return 10;
}

//��� n Ϊconstexpr  const ���ͣ������ڿ���ȷ��Ϊ�������ʽ��������Ҫ����ʱ����ȷ��Ϊ�������ʽ
constexpr int func( int n)
{
    return 10 + n;
}

class  T1 
{
};


void TestConstexpr()
{
    int arraySize = 5;
    func(arraySize);    //���Ա���ͨ������������ֵ
    //int arr[func(arraySize)]{0};  //�޷�����ͨ����������Ҫ�����������ڼ��޷�����������ʽ��
    
    //�ж�ĳ�� class �Ƿ� ����const����  ʹ���˳������ʽ���ڱ�������������
    typedef const T1  T1C;
    auto s1 = std::is_const<T1>::value;    // false
    auto ss = std::is_const<T1C>::value;   //true
}

// ����ģ��(C++14 ��)   

//����Ϊstl�ж����
//template <class>
//constexpr bool is_const_v = false;     //��const Ϊ false

//template <class _Ty>
//constexpr bool is_const_v<const _Ty> = true;   //const Type Ϊtrue





