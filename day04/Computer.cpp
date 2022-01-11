/*************************************************************************
	> File Name: Computer.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Sat 08 Jan 2022 09:52:18 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class Computer
{
public:
	Computer(const char * brand, double price)
	: _brand(new char[strlen(brand) + 1]())
	, _price(price)
	{
		cout << "Computer(const char *, float)" << endl;
		strcpy(_brand, brand);
		_totalPrice += _price;
	}

	Computer(const Computer & rhs)  //Computer & rhs = func1()
	: _brand(new char[strlen(rhs._brand) + 1]())
	, _price(rhs._price)
	{
		strcpy(_brand, rhs._brand);
		cout << "Computer(const Computer&)" << endl;
	}
	
	//系统提供的不能满足需求
#if 0
	Computer & operator=(const Computer & rhs)
	{
		cout << "Computer & operator=(const Computer &)" << endl;
		_brand = rhs._brand;//浅拷贝
		_price = rhs._price;
		return *this;
	}
#endif
	//赋值运算符函数 --> 三部曲
	Computer & operator=(const Computer & rhs)
	{
		if(this != &rhs)//自复制问题
		{
			delete [] _brand;//回收左操作数的申请的空间
			_brand = new char[strlen(rhs._brand) + 1]();//再进行深拷贝
			strcpy(_brand, rhs._brand);

			_price  = rhs._price;
		}
		return *this;
	}

	void print() {
		printf("_brand = %p\n", _brand);	
		cout << "brand:" << _brand << endl;
		cout << "price:" << _price << endl;
	}

	void printTotalPrice()
	{
		cout << "总价:" << _totalPrice << endl;
	}

	~Computer()
	{
		delete [] _brand;
		_brand = NULL;
		cout << "~Computer()" << endl;
	}

private:
	char * _brand;
	double _price;

	static double _totalPrice;//全局/静态区，不会成为对象的一部分
};

//静态数据成员的初始化是在类之外进行的
double Computer::_totalPrice = 0;


void test1(void)
{
	Computer com1("Dell", 6666);//栈对象
	cout << ">> com1:";
	com1.print();

	Computer com2 = com1;//调用Computer的复制构造函数
	cout << " >> com2:";
	com2.print();
	cout << endl;


	Computer com3("ASUS", 7777);
	cout << " >> com3:";
	com3.print();

	com3 = com1;//赋值运算符函数
	cout << " >> com3:";
	com3.print();

	com3 = com3;//自复制
}

void test2(void)
{
	cout << "sizeof(Computer) = " << sizeof(Computer) << endl;
	Computer com1("Dell", 6666);//栈对象
	cout << ">> com1:";
	com1.print();
	com1.printTotalPrice();
	cout <<endl;
	
	Computer com2("ASUS", 7777);
	cout << " >> com2:";
	com2.print();
	com2.printTotalPrice();

	Computer com3("Mac", 8888);
	cout << " >> com3:";
	com3.print();
	com3.printTotalPrice();
}

int main(void)
{
	//test1();
	test2();

	return 0;
}

