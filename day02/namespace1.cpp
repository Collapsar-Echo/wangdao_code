/*************************************************************************
	> File Name: namespace1.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Thu 06 Jan 2022 07:46:06 PM CST
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;//using编译指令
					//初学C++时，不建议使用

//命名空间中的实体: 变量  函数  struct/class

namespace A {

void display()
{
	cout << "A::display()" << endl;
}

}//end of namespace A


//自定义的cout
/*void cout(){
	printf("hello,world\n");	
}*/

namespace B {
void display()
{
	cout << "B::display()" << endl;
}

}//end of namespace B


int main(void)
{
	A::display();//作用域限定符
	B::display();
	//cout();
	return 0;
}
