/*************************************************************************
	> File Name: Point.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Wed 12 Jan 2022 08:31:11 PM CST
 ************************************************************************/

#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point()
	: _ix(0), _iy(0)
	{
		cout << "Point()" << endl;
	}

	explicit// 禁止隐式转换
	Point(int ix)
	: _ix(ix)
	, _iy(0)
	{
		cout << "Point(int)" << endl;
	}

	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int, int)" << endl;
	}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}
private:

	int _ix;
	int _iy;
};
 
int test0(void)
{
	int arr[5] = {1, 2};

	Point points[5] = {
		Point(1, 2),
		Point(3, 4)
	};
	return 0;
}

void test1(void)
{
	Point pt = 1;//发生了隐式转换
	pt.print();
}

int main(void)
{
	test1();
	return 0;
}
