/*************************************************************************
	> File Name: /home/xml/wangdao_code/day03/Computer2.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Fri 07 Jan 2022 03:20:07 PM CST
 ************************************************************************/
#include "Computer.h"
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//inline
void Computer::setBrand(const char * brand)
{	//类内部
	strcpy(_brand, brand);
}


//inline
void Computer::setPrice(float price)
{
	_price = price;
}
 
//inline
void Computer::print()
{
	cout << "brand:" << _brand << endl;
	cout << "price:" << _price << endl;
}
