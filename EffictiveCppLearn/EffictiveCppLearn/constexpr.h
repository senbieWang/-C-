#pragma once
#include <type_traits>
/*
   常量表达式：C++11、 C++14
   1、给编译器足够的信心在编译期去做被constexpr修饰的表达式的优化（当其检测到func的参数是一个常量字面值的时候，
      编译器才会去对其做优化，否则，依然会将计算任务留给运行时）。
   2、基于这个特性，constexpr还可以被用来实现编译期的type traits，比如STL中的is_const的完整实现：
   3、constexpr 如果为真正的常量，在编译期间计算；  如果非常量，在运行期计算。   用词次特性，可以判断
      一个某个类型 标记是否有常量属性
*/

//编译期间可以计算出为常量
constexpr int func() 
{
    return 10;
}

//如果 n 为constexpr  const 类型，编译期可以确定为常量表达式，否则需要运行时才能确定为常量表达式
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
    func(arraySize);    //可以编译通过，运行期求值
    //int arr[func(arraySize)]{0};  //无法编译通过，数组需要产量，编译期间无法求出常量表达式。
    
    //判断某个 class 是否 具有const属性  使用了常量表达式，在编译器计算类型
    typedef const T1  T1C;
    auto s1 = std::is_const<T1>::value;    // false
    auto ss = std::is_const<T1C>::value;   //true
}

// 变量模板(C++14 起)   

//以下为stl中定义的
//template <class>
//constexpr bool is_const_v = false;     //非const 为 false

//template <class _Ty>
//constexpr bool is_const_v<const _Ty> = true;   //const Type 为true





