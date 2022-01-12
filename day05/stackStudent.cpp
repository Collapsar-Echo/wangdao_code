/*************************************************************************
	> File Name: stackStudent.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Wed 12 Jan 2022 09:04:50 PM CST
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

	~Student()
	{
		delete [] _name;
		cout << "~Student()" << endl;
	}

//只能生成栈对象: 把operator new/delete放在private区域
private:
	void * operator new(size_t sz);
	void operator delete(void * ret);
private:
	int _id;
	char * _name;
};
 
int main(void)
{
	Student s1(101, "Alice");//编译通过
	s1.print();
	cout << endl;

#if 0
	Student * pstu = new Student(100, "Jackie");//编译不同通过
	pstu->print();

	delete pstu;
#endif

	return 0;
}

