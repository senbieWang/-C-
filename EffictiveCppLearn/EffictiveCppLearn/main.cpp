#include "CPP2/myTemplates.h"
#include <bitset>
#include <tuple>
#include <string>
#include <vector>
#include <complex>

using namespace MyCPP2;
int main() 
{
    MyCPP2::print(7.5,"Hello",std::bitset<16>(377),42);  

    //1��tuple
    std::tuple<int,float,std::string,int>  tupleDemo(10,10.1,"hello",10);
    std::cout << std::tuple_size<decltype(tupleDemo)>::value << std::endl;
    //std::cout << std::tuple_element<>();
    std::cout << std::get<0>(tupleDemo) << std::endl;

    //2��auto  ������Ϊ������ ����ֵ


    //3��initializer_list ͳһ��ʼ��  ��������ֱ��{}  ������������ʼ��{}��������һ�� initializer_list<T>,  -> �ڲ� array<T,n>
    int  arrays[]{1,2,3};
    std::vector<int>  vec{1,2,3};
    std::vector<std::string> citys{"beijing","shanghai","guanzhou"};
    std::complex<double>  c{ 4.0,5.0 };

    int i;   // û�г�ʼֵ
    int j{}; //��ʼֵΪ0��
    int* p;  // û�г�ʼֵ
    int* q{}; //��ʼֵΪnullptr��


    return 0;
}