/*************************************************************************
	> File Name: Singleton.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Wed 12 Jan 2022 08:32:51 PM CST
 ************************************************************************/

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

//单例模式Singleton
//
//要求：只能由该类创建一个对象
//1. 该对象不能是栈对象或全局对象
//2. 只能是堆对象
//3. 该对象只有一个

//功能：
//	替换全局变量

//应用场景:
//1. 词典类
//2. 配置文件


class Singleton
{//类内部可以调用私有成员
public:
	static Singleton * getInstance()
	{
		if(_pInstance == NULL)
		{
			_pInstance = new Singleton();
		}
		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance)
		{
			delete _pInstance;
		}
	}

private://1.将构造函数私有化
	Singleton(){	cout << "Singleton()" << endl;}
	~Singleton(){	cout << "~Singleton()" << endl;	}

private:
	static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = NULL;

//Singleton s3;
//static Singleton s4;
 
int main(void)
{
	//Singleton s1;//调用了无参构造函数, 不能让该语句编译通过
	//Singleton s2;
	
	//Singleton * pSingleton = new Singleton();//堆对象, 类之外
	Singleton * pSingleton1 = Singleton::getInstance();
	Singleton * pSingleton2 = Singleton::getInstance();
	
	printf("pSingleton1 = %p\n", pSingleton1);
	printf("pSingleton2 = %p\n", pSingleton2);

	//delete pSingleton1;//error
	
	Singleton::destroy();

	return 0;
}
