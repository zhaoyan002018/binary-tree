#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

//容器适配器有三种、栈、队列、优先级队列。
using namespace std;

void stackFunc()
{
	//stack<vector<char>> s1;
	stack<char, vector<char>> s1;//俩个参数的用处？2参数是分配子，实际上的构造并非stack本身，而是调用vector<char>来进行构造。
	//stack<char> 则默认的分配子是deque，因而第一行的写法是错误的。
	char arr[] = "hello world";
	//vector<char> v1(arr, arr + strlen(arr));
	int i = 0;
	for (; arr[i]; i++)
		//s1.push(v1[i]);
		s1.push(arr[i]);//效果是一样的


	while (!s1.empty()) {
		cout << s1.top() << '\t';
		s1.pop();
	}

}

//队列类
void queueFunc()
{
	queue<int, deque<int>> q1;
	int arr[5] = { 4,2,1,6,7 };
	for (int i = 0; i < 5; i++)
		q1.push(arr[i]);

	while (!q1.empty())
	{
		cout << q1.front() << '\t';
		q1.pop();
	}
}

//优先级队列

void priqueFunc()
{
	priority_queue<int> pq1;
	pq1.push(2);
	pq1.push(6);
	pq1.push(5);
	pq1.push(12);
	pq1.push(7);

	while (!pq1.empty())
	{
		cout << pq1.top();
		pq1.pop();
	}
}


int main6()
{
	priqueFunc();
	return 0;
}
