/*************************************************************************
	> File Name: inline.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Thu 06 Jan 2022 08:55:50 PM CST
 ************************************************************************/

#include <iostream>
using std::cout;
using std::endl;


#define max(x,y)  ((x)>(y)?(x):(y))
#define multipy(x,y) (x)*(y)

//内联函数在功能上与带参数的宏定义是一样的
//在实际调用时，会直接用函数执行体的内容替换掉
//
//相比带参数的宏定义的好处是 有类型检查，还是看成一个函数
//
//尽可能用inline函数代替带参数的宏定义，这样做可以最大程度
//降低犯错误的可能
inline
int Max(int x, int y)
{
	return x > y ? x : y;
}

inline
int Multipy(int x, int y)
{
	return x * y;
}
 
int main(void)
{
	int a = 3, b = 4;
	cout << max(a, b) << endl;
	cout << multipy(a,b) << endl;

	// a+b*a = 15
	cout << multipy(a + b, a) << endl;// (a+b) * a = 21

	return 0;
}

