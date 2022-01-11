/*************************************************************************
	> File Name: Point2.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Sat 08 Jan 2022 09:06:29 PM CST
 ************************************************************************/

#include <iostream>
using std::cout;
using std::endl;


class Point
{
public:
	//构造函数是特殊的成员函数
	//
	//构造函数可以重载
	//
	//当没有显式定义构造函数时，系统会自动提供一个默认构造函数
	Point(){
		cout << "Point()" << endl;
		_ix = 0;// 赋值语句
		_iy = 0;
	}

	//一旦提供了一个有参构造函数时，系统就不会再自动提供默认构造函数;
	//如果还需要调用默认构造函数创建对象，则需要显式提供默认构造函数
	Point(int ix, int iy){
		cout << "Point(int,int)" << endl;
		_ix = ix;
		_iy = iy;
	}

	void print(){
		cout << "(" << _ix 
			 << "," << _iy
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
};
 
int main(void)
{
	//int a;
	Point p;//调用无参(默认)构造函数Point()
	p.print();

	Point point(1, 2);
	point.print();

	return 0;
}
