/*************************************************************************
	> File Name: bool.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Thu 06 Jan 2022 08:58:06 PM CST
 ************************************************************************/

#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	bool b1 = 100;
	bool b2 = 1;
	bool b3 = -1;
	bool b4 = 0;
	bool b5 = true;
	bool b6 = false;

	cout << "b1 = " << b1 << endl
		 << "b2 = " << b2 << endl
		 << "b3 = " << b3 << endl
		 << "b4 = " << b4 << endl
		 << "b5 = " << b5 << endl
		 << "b6 = " << b6 << endl;

	cout << "sizeof(bool) = " << sizeof(bool) << endl;

	return 0;
}
