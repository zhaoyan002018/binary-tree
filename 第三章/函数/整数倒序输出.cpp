#include<iostream>
using namespace std;

//递归将整数倒序输出。（顺序相关的问题）
//思考首先为什么能够使用递归？即递推，回归？
//其次递归结束条件是什么？ 

//%除余得到的是最右边的位数
void Inorder(int number)
{
	cout << number % 10;
	if (number < 10)
	{
		return;
	}

	else Inorder(number / 10);
}

//fibonacci数列递归实现
//n	指输出到数列第几项
//返回值	第n项的大小
int fib(int n)
{
	int result;
	if (n == 0)
		result = 0;
	else if (n == 1)
		result = 1;
	else
		result = fib(n - 1) + fib(n - 2);
	return result;
}

int main10()
{
	int n = 257;
	Inorder(n);
	cout << fib(10);
	return 0;
}
