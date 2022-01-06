/*************************************************************************
	> File Name: namespace2.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Thu 06 Jan 2022 07:54:56 PM CST
 ************************************************************************/

#include <stdio.h>
#include <iostream>

using std::cout;//using声明机制
using std::endl;


//匿名命名空间
void print()
{
	cout << "print()" << endl;
}


//命名空间类似于黑洞
namespace A
{
void show()
{
	cout << "A::show()" << endl;
}
}//end of namespace A

namespace B {
void display()
{
	cout << "B::display()" << endl;
	A::show();
}

}//end of namespace B

namespace A {


void display()
{
	cout << "A::display()" << endl;
	B::display();
}

namespace C {

void display()
{
	cout << "C::display()" << endl;
}
}

}//end of namespace A


//自定义的cout
#if 0
void cout(){
	printf("hello,world\n");	
}
#endif



int main(void)
{
	A::display();//作用域限定符
	B::display();
	A::C::display();
	//cout();
	::print();
	return 0;
}
