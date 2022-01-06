/*************************************************************************
	> File Name: malloc_new.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Thu 06 Jan 2022 08:43:13 PM CST
 ************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


//malloc/free 与new/delete的差别是什么？
//1. malloc/free是C的标准库函数
//	 new/delete 是表达式
//2. malloc只负责开辟空间,不会初始化空间;
//   new表达式除了开辟空间，还可以舒适化空间


void test0()
{
	int * pint = (int *)malloc(sizeof(int)*10);
	::memset(pint, 0, sizeof(int));
	*pint = 10;

	cout << "*pint = " << *pint << endl;

	free(pint);
}

void test1()
{
	int * pint = new int(1);
	cout << "*pint = " << *pint << endl;

	delete pint;

	int * pint2 = new int[10]();
	for(int idx = 0; idx != 10; ++idx)
	{
		pint2[idx] = 1;
	}

	delete [] pint2;
}

 
int main(void)
{
	//test0();
	test1();
	return 0;
}

