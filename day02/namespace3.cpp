/*************************************************************************
	> File Name: namespace3.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Thu 06 Jan 2022 07:59:46 PM CST
 ************************************************************************/

#include <stdio.h>
#include <iostream>

namespace A {

void display()
{
	std::cout << "A::display()" << std::endl;
}

}//end of namespace A


//自定义的cout
void cout(){
	printf("hello,world\n");	
}

namespace B {
void display()
{
	std::cout << "B::display()" << std::endl;
}

}//end of namespace B


int main(void)
{
	A::display();//作用域限定符
	B::display();
	cout();
	return 0;
}

