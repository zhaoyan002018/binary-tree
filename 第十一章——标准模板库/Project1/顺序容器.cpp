#include<algorithm>
#include<vector>
#include<iostream>
#include<iterator>
#include<functional>
#include<list>
#include<deque>
using namespace std;

//寻找vector容器元素
void vectorFunc()
{
	int search_value, ia[9] = { 47,29,37,23,11,7,5,31,41 }, i;
	vector<int>vec(ia, ia + 9);
	vector<int>::iterator iter;
	for (i = 0; i < vec.size(); i++) cout << vec[i] << '\t';
	cout << endl;
	vec.push_back(13);//只能在尾部处理
	for (iter = vec.begin(); iter != vec.end(); iter++)cout << *iter << '\t';


	cout << "请输入要搜索的数：" << endl;
	cin >> search_value;
	iter = find(vec.begin(), vec.end(), search_value);
	cout << "数值" << search_value << (iter == vec.end() ? "不存在" : "存在") << endl;

}

//从标准输入读取一个整数集合到vector中。
void iterFunc()
{
	//通过俩个泛型算法copy、sort，copy将流迭代子从cin获得的数据，复制到容器vector中，其中流迭代子起到连接容器和算法的作用。
	vector<int> vi;
	istream_iterator<int> isi(cin);//建立输入流迭代子
	//istream_iterator<int> is_end();//想要调用无参构造创建一个对象的话注意不能加()，否则，成为了一个函数调用。p117
	istream_iterator<int> is_end;//通过无参构造建立流结束位置

	copy(isi, is_end, inserter(vi, vi.begin()));//1,2参数表明源数据的起始终止位置，3参数表明要输出的目的。

	ostream_iterator<int> output(cout, " ");
	//sort(vi.begin(), vi.end(), greater<int>());//greater是一个函数对象，表明排序方式为>比较，即升序，3参数不填则默认降序
	sort(vi.begin(), vi.end());

	unique_copy(vi.begin(), vi.end(), output);

}

void listFunc()
{
	int arr1[5] = { 2,5,7,9,10 }, arr2[6] = { 1,3,6,8,11,23 };
	list<int> l1, l2;
	int i;
	for (i = 0; i < 5; i++)
		l1.push_back(arr1[i]);
	for (i = 0; i < 6; i++)
		l2.push_front(arr2[i]);

	list<int>::iterator iter;//list<int>::iterator是类型，和istream_iterator直接作为类提供不同，他被封装在了list容器内
	for (iter = l1.begin(); iter != l1.end(); iter++)//注意iter没有<比较，有！=作为结束判定
	{
		cout << *iter << '\t';
	}
	cout << endl;
	for (iter = l2.begin(); iter != l2.end(); iter++)
	{
		cout << *iter << '\t';
	}
	l2.reverse();
	l1.merge(l2);
	cout << endl;
	while (!l1.empty())
	{
		cout << l1.front() << '\t';
		l1.pop_front();
	}



}


//通过copy输出dequeue双端队列
void printDequeue(deque<char>& de)
{
	ostream_iterator<char> osi(cout);

	copy(de.begin(), de.end(), osi);
	cout << endl;
}


void dequeueFunc()
{
	//输出字符串stl功能强使用方便。
	char arr1[7] = { "功能强" }, arr2[9] = { "使用方便" };
	deque<char> de1(arr1, arr1 + 6);
	printDequeue(de1);

	de1.insert(de1.end(), arr2, arr2 + 8);
	printDequeue(de1);

	de1.insert(de1.begin(), 'L');
	de1.insert(de1.begin(), 'T');
	de1.insert(de1.begin(), 'S');
	printDequeue(de1);

}

int main2()
{
	dequeueFunc();
	return 0;
}
