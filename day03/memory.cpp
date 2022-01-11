/*************************************************************************
	> File Name: memory.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Fri 07 Jan 2022 11:57:33 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
 
int a = 0;//全局/静态区
char * p1;
static int d = 1;
const int e = 10;//文字常量区
int test(void)
{
	int b;
	const int f = 100;//栈区, 跟生命周期有关
	char s[] = "123456";
	char * p2;
	const char * p3 = "123456";
	static int c = 0;//全局静态
	c++;
	cout << "c = " << c << endl;

	p1 = new char[10];
	p2 = new char[5];
	strcpy(p1, "123456");

	printf("&e = %p\n", &e);
	printf("&f = %p\n", &f);


	printf("123456's address = %p\n", "123456");

	printf("&a = %p\n", &a);
	printf("&b = %p\n", &b);
	printf("&c = %p\n", &c);
	printf("s = %p\n", s);
	printf("p1 = %p\n", p1);
	printf("&p1 = %p\n", &p1);
	printf("p2 = %p\n", p2);
	printf("&p2 = %p\n", &p2);
	printf("&p3 = %p\n", &p3);
	printf("p3 = %p\n", p3);
	printf("test = %p\n", test);
 
	return 0;
}

int main(void)
{
	test();
	printf("main = %p\n", main);
	return 0;
}
