/*************************************************************************
	> File Name: Ponit2.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Sat 08 Jan 2022 10:07:54 PM CST
 ************************************************************************/

#include <iostream>
using std::cout;
using std::endl;


class Point
{
public:

	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	, _ref(_ix) //引用成员必须要放在初始化列表之中进行
	{
		cout << "Point(int,int)" << endl;
	}

	void print() {
		cout << "(" << this->_ix 
			 << "," << this->_iy
			 << ")" << endl;
	}

private:
	int _ix;
	int _iy;
	int & _ref;
};
 
int main(void)
{
	//内置类型
	int a = 3;
	int b = 4;
	a = b;

	Point p;
	p.print();

	Point point1(1, 2);
	cout << "point1 = ";
	point1.print();//自动把point1的地址传递给this指针，这是编译器帮我们完成的
	cout << endl;

	Point point2 = point1;//调用复制构造函数
	cout << "point2 = ";
	point2.print();
	cout << endl;
	
	Point point3(3, 4);
	cout << "point3 = ";
	point3.print();
	cout << endl;

	return 0;
}
