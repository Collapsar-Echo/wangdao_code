/*************************************************************************
	> File Name: extern.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Thu 06 Jan 2022 08:49:18 PM CST
 ************************************************************************/

#include <stdio.h>

//为了实现C和C++的混合编程
#ifdef __cplusplus
extern "C" {
#endif
//该函数要按照C的方式进行调用
int add(int x, int y)
{
	return x + y;
}

#ifdef __cplusplus
}// end of extern "C"
#endif

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
