#include "CPP2/myTemplates.h"
#include <bitset>
#include <tuple>
#include <string>

using namespace MyCPP2;
int main() 
{
    MyCPP2::print(7.5,"Hello",std::bitset<16>(377),42);  

    std::tuple<int,float,std::string,int>  tupleDemo(10,10.1,"hello",10);
    std::cout << std::tuple_size<decltype(tupleDemo)>::value << std::endl;
    //std::cout << std::tuple_element<>();
    std::cout << std::get<0>(tupleDemo) << std::endl;

    return 0;
}