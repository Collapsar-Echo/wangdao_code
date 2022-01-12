/*************************************************************************
	> File Name: vector.cpp
	> Author: amoscykl
	> Mail: amoscykl@163.com 
	> Created Time: Wed 12 Jan 2022 09:12:24 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;

using std::vector;


//标准  --> 实现 (GNU GCC, VC++, LLVM clang++, intel C++)

//动态数组vector可以自动进行扩容，但是是有开销的，是有成本的
//实现的具体步骤:
//   当size == capacity,并且需要添加新元素 时，进行扩容操作:
//	1. 先申请2 * capacity 的空间
//	2. 然后把原来空间的元素copy到新申请的空间
//	3. 再添加新的元素
//	4. 最后释放原来开辟的空间

int arr[10];//空间不能扩展

void displayCapacity(vector<int> & vec)
{
	cout << "vector's size = " << vec.size() << endl;
	cout << "vector's capacity = " << vec.capacity() << endl;
}
 
void test0(void)
{
	vector<int> numbers;
	numbers.reserve(100);//预先申请空间

	displayCapacity(numbers);
	numbers.push_back(1);
	displayCapacity(numbers);
	numbers.push_back(2);
	displayCapacity(numbers);
	numbers.push_back(3);
	displayCapacity(numbers);
	numbers.push_back(4);
	displayCapacity(numbers);
	numbers.push_back(5);
	displayCapacity(numbers);
	numbers.push_back(6);
	displayCapacity(numbers);
	numbers.push_back(7);
	displayCapacity(numbers);
	numbers.push_back(8);
	displayCapacity(numbers);
	numbers.push_back(9);
	displayCapacity(numbers);

	for(size_t idx = 0; idx != numbers.size(); ++idx)
	{
		cout << numbers[idx] << " ";
	}
	cout << endl;

	for(auto & number : numbers) {
		cout << number << " ";
	}
	cout << endl;
}

int main(void)
{
	test0();
}
