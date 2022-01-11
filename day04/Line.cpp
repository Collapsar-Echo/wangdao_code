/*************************************************************************
	> File Name: Line.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Sat 08 Jan 2022 10:06:10 PM CST
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
	{
		cout << "Point(int=0, int=0)" << endl;
	}

	void print() {
		cout << "(" << this->_ix 
			 << "," << this->_iy
			 << ")";
	}

private:
	int _ix;
	int _iy;
};

class Line
{
public:
	Line(int x1, int y1, int x2, int y2)
	// 如果是对象成员，在初始化时会自动相应类型的默认构造函数
	: _p1(x1, y1)
	, _p2(x2, y2)
	{
		cout << "Line(int,int,int,int)" << endl;
	}

	void print()
	{
		_p1.print();
		cout << " --> ";
		_p2.print();
		cout << endl;
	}

private:
	Point _p1;
	Point _p2;
};
 
int main(void)
{
	Line line(1, 2, 3, 4);
	line.print();

	return 0;
}
