/*************************************************************************
	> File Name: wildpointer.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Fri 07 Jan 2022 11:53:52 AM CST
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

void test()
{
	int * p;
	printf("p = %p\n", p);
}
 
int main(void)
{
	test();
	int * p;
	printf("p = %p\n", p);
	*p = 10;

	return 0;
}
