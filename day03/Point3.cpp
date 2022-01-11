/*************************************************************************
	> File Name: Point.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Sat 08 Jan 2022 08:39:35 PM CST
 ************************************************************************/

#include <iostream>
using std::cout;
using std::endl;


class Point
{
public:
	Point(int ix, int iy)
	:_ix(ix)
	,_iy(iy){
		cout << "Point(int,int)" << endl;
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
