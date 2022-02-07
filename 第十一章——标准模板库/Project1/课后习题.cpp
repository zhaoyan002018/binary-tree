#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>
#include<map>
using namespace std;

//测试使用vector的主要功能和方法
void  func11_3()
{
	int arr[] = { 2,4,6,1,3,5 };
	vector<int> vi;
	int n = vi.capacity();
	cout << "n=" << n << endl;
	for (int i = 0; i < 6; i++)
		vi.insert(vi.begin(), arr[i]);
	n = vi.capacity();

	cout << "n=" << n << endl;
	vi.erase(vi.begin());

	cout << "size=" << vi.size() << "n=" << n << endl;
	vi.get_allocator();
}
//测试使用list的主要功能和方法
template<typename T>
class funcObj
{
	T i;
public:
	funcObj(T j = 0) { i = j; }
	bool operator()(T val) {
		return val < i;
	}

};

void  func11_4()
{
	int arr[] = { 2,4,6,1,3,5 };
	list<int> l1(arr, arr + 6);
	list<int>::iterator it = l1.begin();
	for (it; it != l1.end(); it++)
		cout << *it << '\t';
	cout << endl;


	funcObj<int> fc(4);
	l1.remove_if(fc);

	list<int> l2(6);
	it = l2.begin();
	it++;
	l2.splice(it, l1);//把l1的全部内容splice到it位置

	swap(l1, l2);//splice和swap有什么区别呢？感觉swap更强大，splice是单向操作。

	cout << "l2:" << endl;
	while (!l2.empty())
	{
		cout << l2.front() << '\t';
		l2.pop_front();
	}
	cout << endl;

	cout << "l1:" << endl;
	while (!l1.empty())
	{
		cout << l1.front() << '\t';
		l1.pop_front();
	}
}


//用映射建立0-9对英文zero到nine的映射关系，并且输入阿拉伯数字，输出英文
void func11_6()
{
	int alb[10] = { 0,1,2,3,4,5,6,7,8,9 };
	string els[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	map<int, string> m1;
	for (int i = 0; i < 10; i++)
		m1[alb[i]] = els[i];

	map<int, string>::iterator it;
	for (it = m1.begin(); it != m1.end(); it++)
		cout << it->first << "->" << it->second << '\t';
}


int main()
{
	func11_6();
}
