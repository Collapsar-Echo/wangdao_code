/*************************************************************************
	> File Name: heapStudent.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Wed 12 Jan 2022 08:57:39 PM CST
 ************************************************************************/

#include <string.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;


class Student
{
public:
	Student(int id, const char * name)
	: _id(id)
	, _name(new char[strlen(name) + 1]())
	{
		cout << "Student(int, const char*)" << endl;
		strcpy(_name, name);
	}

	void print() const
	{
		cout << "id: " << _id  << endl
			 << "name: " << _name << endl;
	}

	void destroy()
	{
		//this->~Student();
		delete this;
	}

//只能生成堆对象: 将析构函数私有化,但是
//堆对象的回收需要在类内部定义一个销毁函数
private:
	~Student()
	{
		delete [] _name;
		cout << "~Student()" << endl;
	}
public: 
	//重载
	void * operator new(size_t sz)
	{
		cout << "void * operator new(size_t) " << endl;
		void * ret = malloc(sz);
		return ret;
	}

	void operator delete(void * ret)
	{
		free(ret);
		cout << "void operator delete(void *)" << endl;
	}

private:
	int _id;
	char * _name;
};
 
int main(void)
{
	Student * pstu = new Student(100, "Jackie");
	pstu->print();
	//delete pstu;
	pstu->destroy();

	//Student s1(101, "Alice");//编译不能通过 ,栈对象的生成同时需要构造函数和析构函数都是public的
	//s1.print();

	return 0;
}

