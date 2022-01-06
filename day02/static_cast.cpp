/*************************************************************************
	> File Name: static_cast.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Thu 06 Jan 2022 08:51:02 PM CST
 ************************************************************************/

#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;


void test0()
{
	int val1 = 10;
	double val2 = (double)val1;
	double val3 = double(val1);

	cout << "val2 = " << val2 << endl
		 << "val3 = " << val3 << endl;
}

void test1()
{
	//C++强制转换
	int val1 = 10;
	double val2 = static_cast<double>(val1);
	cout << "val2 = " << val2 << endl;

	int * pint = static_cast<int *>(malloc(sizeof(int)));
	*pint = 1;
	//const_cast/dynamic_cast/reinterpret_cast
}
 
int main(void)
{
	//test0();
	test1();

	return 0;
}
