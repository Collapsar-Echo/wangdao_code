/*************************************************************************
	> File Name: NullPointerCall.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Wed 12 Jan 2022 08:28:02 PM CST
 ************************************************************************/

#include <iostream>
using std::cout;
using std::endl;


class NullPointerCall
{
public:
	void test1()
	{	cout << "NullPointerCall::test1()" << endl;}

	void test2(int x)
	{
		cout << "NullPointerCall::test2 x = " << x << endl;
	}

	static void test3()
	{
		cout << "NullPointerCall::test3 _iy = " << _iy << endl;
	}

	void test4()
	{
		cout << "NullPointerCall::test4 _ix = " << this->_ix << endl;
	}

private:
	int _ix;
	static int _iy;
};

int NullPointerCall::_iy = 0;
 
int main(void)
{
	NullPointerCall * pNULL = NULL;

	pNULL->test1();
	pNULL->test2(10);
	pNULL->test3();
	pNULL->test4();

	return 0;
}
