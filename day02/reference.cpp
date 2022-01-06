/*************************************************************************
	> File Name: reference.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Thu 06 Jan 2022 08:32:06 PM CST
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;


//值传递 --> 复制
#if 0
void swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}
#endif


//地址传递 --> 值传递 --> 复制
void swap(int * px, int * py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}

//引用作为函数的参数
// 可以减少复制的开销，加快程序的执行效率
void swap(int & x, int & y)
{
	int temp = x;
	x = y;
	y = temp;
}



//引用与指针的区别？
//相同点：
//		都有"地址"的概念
//不同点:
//	1. 引用不能单独存在，必须要绑定一个实体上; 
//	   指针是可以单独存在的，就是一个独立的实体
//  2. 引用必须要进行初始化；指针可以不进行初始化
//  3. 指针可以设为空指针，但引用不行
 
int test0(void)
{
	int * p;
	int number = 10;
	int & ref = number;//引用, 就是一个变量的别名
	//int & ref1;//error  引用必须要进行初始化，不能独立存在
	
	ref = 100;
	cout << "number = " << number << endl;
	cout << "ref = " << ref << endl;
	printf("&number = %p\n", &number);
	printf("&ref = %p\n", &ref);

	//int & ref2 = 10;//字面值, 因为其不能取地址
	//&10;
	
	const int & ref2 = 10;//const引用可以绑定到右值(不能取地址)
	cout << "ref2 = " << ref2 << endl;

	return 0;
}

void test1()
{
	int a = 3, b = 4;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	swap(a, b);
	//swap(&a, &b);
	cout << "执行函数swap之后:" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}


int func0()
{
	int number = 10;
	return number;//在执行return时，都会进行复制
}

int arr[5] = {1, 2, 3, 4, 5};

//引用可以作为函数的返回值, 返回的变量其生命周期要是大于函数的
//
//在执行return时是没有进行复制的
int & func(int idx)
{
	return arr[idx];
}

//不要返回一个局部变量的引用
int & func2()
{
	int number = 10;//因为number是一个局部变量,当执行完func2时，其已经被销毁
	return number;
}

//不要返回一个局部变量的指针
int * func3()
{
	int number = 10;
	return &number;
}

//不要轻易返回一个堆空间变量的引用,
//除非已经有了回收内存的策略
int & func4()
{
	int * pint = new int(100);
	return *pint;
}

void test2()
{
	int number = func(1);
	cout << "number = " << number << endl;
	func(0) = 10;
	cout << "arr[0] = " << arr[0] << endl;

	//cout << "func2() = " << func2() << endl;
	cout << "func4() = " << func4() << endl;//引起内存泄漏
	int & ref = func4();
	cout << "ref = " << ref << endl;
	delete &ref;//不够直观, 返回常规思维
}

int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}

