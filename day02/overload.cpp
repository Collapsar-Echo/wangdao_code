/*************************************************************************
	> File Name: overload.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Thu 06 Jan 2022 08:46:49 PM CST
 ************************************************************************/


#include <stdio.h>

//C++语言支持函数重载
//实现原理：名字改编(name mangling)
//具体步骤: 当函数名称相同时，会按照函数参数的类型、个数、顺序进行改编

int add(int x, int y)
{
	return x + y;
}

int add(int x, int y, double z)
{
	return x + y + z;
}
 
int main(void)
{
	int a = 3, b = 4, c = 5;
	printf("a + b = %d\n", add(a, b));
	printf("a + b + c = %d\n", add(a, b, c));
	return 0;
}
