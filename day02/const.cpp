/*************************************************************************
	> File Name: const.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Thu 06 Jan 2022 08:17:07 PM CST
 ************************************************************************/

#include <iostream>
using std::cout;
using std::endl;

//一个程序所有要经过的阶段:
//编辑  --> 预编译(预处理) --> 编译 --> 汇编 --> 链接 --> 运行

//宏定义与const的差别是什么？
//1. 发生的时机: 
//		#define 是在预编译阶段, 只是做字符串的替换，没有类型检查
//		const 就在编译阶段, 有类型检查， 更安全一些
//2. 尽量使用const替换宏定义
#define kMax 100   
 
int test0(void)
{
	int number = 10;
	cout << number * kMax << endl;

	return 0;
}

int test1()
{
	const int number = 10;//const关键字修饰之后，不能再修改该值
	//number = 11;//error
	
	//const int val;//error  const关键字修饰的值必须要进行初始化

	return 0;
}

//int (*arr)[]      int * arr[]
//数组指针    vs    指针数组
//
//int(*pfunc)(int)    int * func(int)
//函数指针    vs    指针函数
//
//常量指针    vs    指针常量



void test2()
{
	int a = 100;
	int * pa = &a;
	&a;//a变量的地址
	&pa;//pa指针变量的地址
	pa;//地址值

	int b = 1000;
	const int * pb = &a;//常量指针(pointer to const)
	//*pb = 1;//error, 不能通过pb指针修改其所指变量的值
	pb = &b;//ok, 可以改变pb指针的指向
	a = 10;
	cout << "a = " << a << endl;

	int const * pc = &a;// 跟pb效果是一样的
	//*pc = 1;//error
	pc = &b;

	int * const pd = &a;//指针常量(const pointer)
	*pd = 1;//可以通过pd指针改变所指变量的值
	//pd = &b;//error  不能改变指针的指向
	cout << "a = " << a << endl;


	const int * const pe = &a;// 两者都不能进行修改
}

int main(void)
{
	test2();
	return 0;
}

