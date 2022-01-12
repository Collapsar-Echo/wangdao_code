/*************************************************************************
	> File Name: io3.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Wed 12 Jan 2022 09:10:11 PM CST
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;

void test0(void)
{
	int number1 = 10;
	int number2 = 20;
	
	//把非字符串数据转换成字符串
	//ssprintf
	stringstream ss;
	ss << "number1= " << number1 << " number2= " << number2;
	cout << ss.str() << endl;

	string word;
	int value;

	//当确定格式的时候，就可以使用输入流方式完成数据的输入
	while(ss >> word >> value)
	{
		cout << word << " " << value << endl;
	}
}

string int2str(int number)
{
	ostringstream oss;
	oss << number;
	return oss.str();
}

void readConfiguration()
{
	ifstream ifs;
	ifs.open("server.conf");
	if(!ifs) {
		cout << "ifstream open error!" << endl;
		return ;
	}

	string line;
	string key;
	string value;
	while(getline(ifs, line))
	{
		istringstream iss(line);
		iss >> key >> value;
		cout << key << " --> " << value << endl;
	}
	ifs.close();
}


 
int main(void)
{
	test0();
	int number = 123;
	cout << int2str(number) << endl;

	readConfiguration();
	return 0;
}

