/*************************************************************************
	> File Name: Computer.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Fri 07 Jan 2022 03:10:00 PM CST
 ************************************************************************/
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


//代码风格或编程规范
//
//code review --> 代码审查

//什么是类之外?
class Computer
{
//默认访问权限是private
public:// 接口  服务
	//成员函数(方法)
	//inline函数
	void setBrand(const char * brand){
		strcpy(_brand, brand);
	}

	void setPrice(float price) {
		_price = price;
	}

//protected:
	void print() {
		cout << "brand:" << _brand << endl;
		cout << "price:" << _price << endl;
	}

private://封装
	//数据成员
	char _brand[20];// m_brand/brand_/c_brand
	float _price;
};
 
int main(void)
{
	//int a;
	Computer com1;
	//com1._price = 8888;//error, 体现封装的特性
	com1.setBrand("Dell");
	com1.setPrice(6666);
	com1.print();

	return 0;
}
