/*************************************************************************
	> File Name: struct_class.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Sat 08 Jan 2022 08:27:41 PM CST
 ************************************************************************/

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


struct Computer
{//struct的默认访问权限是public
	void setBrand(const char * brand){
		strcpy(_brand, brand);
	}

	void setPrice(float price) {
		_price = price;
	}

	void print() {
		cout << "brand:" << _brand << endl;
		cout << "price:" << _price << endl;
	}

	char _brand[20];// m_brand/brand_/c_brand
	float _price;
};

 
int main(void)
{
	Computer com1;
	com1.setBrand("Dell");
	com1.setPrice(6666);
	com1._price = 8888;
	com1.print();
 
	return 0;
}
