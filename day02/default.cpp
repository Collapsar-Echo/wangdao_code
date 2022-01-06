/*************************************************************************
	> File Name: default.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Thu 06 Jan 2022 08:53:13 PM CST
 ************************************************************************/

#include <iostream>
using std::cout;
using std::endl;


//在声明时设置了默认参数的，在定义时就不需要再设了
int add(int x, int y = 10);

//对于默认(缺省)参数而言，必须要按照从右到左的顺序进行设置
int add(int x, int y, int z)
{
	return x + y + z;
}
 
int main(void)
{
	int a = 3, b = 4, c = 5;
	cout << add(a) << endl;
	//cout << add(a, b) << endl;
	cout << add(a, b, c) << endl;
	     
	return 0;
}

int add(int x, int y)
{
	return x + y;
}

