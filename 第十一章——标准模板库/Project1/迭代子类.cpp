#include<algorithm>
#include<iostream>
using namespace std;

//迭代子和算法的关系
template<typename InputIterator, typename T>
InputIterator Find(InputIterator first, InputIterator last, const T value)
{
	for (; first != last; ++first)
		if (value == *first)
			return first;
	return last;
}


int main1()
{
	int search_value, ia[9] = { 47,29,37,23,11,7,5,31,41 };
	cout << "请输入要搜索的数：" << endl;
	cin >> search_value;
	int* presult = Find(&ia[0], &ia[9], search_value);
	cout << "数值" << search_value << (presult == &ia[9] ? "不存在" : "存在") << endl;
	return 0;

}
