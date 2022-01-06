/*************************************************************************
	> File Name: namespace4.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Thu 06 Jan 2022 08:02:05 PM CST
 ************************************************************************/

#include <stdio.h>   //都位于C++的匿名命名空间
#include <iostream>

int number = 10;

namespace A
{
//可以在某一范围内使用
using std::cout;
using std::endl;
int number = 100;

void display(int number)
{
	cout << "形参number = " << number << endl;
	cout << "A::number = " << A::number << endl;
	cout << "全局变量number = " << ::number << endl;
}
}//end of namespace A
 
int main(void)
{
	//cout << "hello,world" << endl;//error
	A::display(3);
	return 0;
}
