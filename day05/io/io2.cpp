/*************************************************************************
	> File Name: io2.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Wed 12 Jan 2022 09:09:20 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::vector;

void test0(void)
{
	//ifstream ifs("test.txt");// 文件输入流要求文件必须存在
	ifstream ifs("io1.cc");
	if(!ifs)
	{
		cout << "ifstream open error!" << endl;
		return;
	}
	vector<string> file;

	string line;
	while(getline(ifs, line))
	{
		file.push_back(line);
	}

	//文件输出流不要求文件必须存在; 如果文件不存在，就创建一个；
	//如果文件存在，每次都会清空文件流，重新写入数据
	ofstream ofs("test.txt");
	if(!ofs){
		cout << "ofstream open error!" << endl;
	}

	for(auto & line : file)
	{
		cout << line << endl;//输出到终端
		ofs << line << endl;//输出到文件
	}

	ifs.close();
	ofs.close();
}

void test1(void)
{
	ofstream ofs("test.txt", std::ios::app);//append
	if(!ofs) {
		cout << "ofstream open error!" << endl;
	}

	//获取当前文件游标的位置
	cout << "indicator's pos = " << ofs.tellp() << endl;

	ofs << "that's new \n";

	ofs.close();
}

void test2(void)
{
	string filename = "test2.txt";
	fstream fs(filename);//要求文件必须存在
	if(!fs) {
		cout << "fstream open error!" << endl;
		return ;
	}

	int number;

	for(int idx = 0; idx != 10; ++idx)
	{
		std::cin >> number; 
		fs << number << " ";//把数据输出到文件
	}
	cout << "fs's indicator 's pos = " << fs.tellp() << endl;
	fs.seekg(std::ios::beg);

	for(int idx = 0; idx != 10; ++idx)
	{
		fs >> number;//把数据从文件输入到number中去
		cout << number << " ";
	}
	cout << endl;
}
 
int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}

