#include<iostream>
using namespace std;

static void function3_3()//小写改为大写
{
	const int num = 10;
	const int del = 'a' - 'A';//小写字符和大写字符之间的差值
	cout << "del =" << del << endl;
	char a[num] = {};
	cout << "请输入字符串：";
	//cin >> a;  可能会越界

	int i = 0;
	while (i < num)
	{
		cin.get(a[i]);
		if (a[i] >= 'a')
		{
			a[i] -= del;
		}
		i++;
	}
	cout << endl;

	//cout << a << endl; 结束符\0不一定在数组中存在。
	i = 0;
	while (i < num)
	{
		cout << a[i];
		i++;
	}
	cout << endl;


}

int getMaxFactor(int a, int b)
{
	//递推法
	int rem;
	while (a % b != 0)
	{
		rem = a % b;
		a = b;
		b = rem;
	}
	return b;
}

int getMinMulriple(int a, int b)
{
	return a * b / getMaxFactor(a, b);
}

static void function3_4()
{
	cout << "请输出俩个整数：" << endl;
	int a, b;
	cin >> a >> b;
	int fac = getMaxFactor(a, b);
	int mul = getMinMulriple(a, b);
	cout << a << "和" << b << "的最大公约数为:" << fac << ",最小公倍数为:" << mul << endl;

}

int digit(int num, int k)//求得num从右数第k位数字的值
{
	int i = k;
	int result;
	while (i)
	{
		result = num % 10;
		num = num / 10;
		i--;
	}
	return result;
}
int digit_recursion(int num, int k)
{
	if (k == 1)
		return num % 10;
	else
		return digit_recursion(num / 10, k - 1);
}


static void function3_5()
{
	int num, k;
	cout << "请输入num的值：";
	cin >> num;
	cout << "请输入k的值:";
	cin >> k;
	//cout << "结果为：" << digit(num, k) << endl;
	cout << "结果为：" << digit_recursion(num, k) << endl;
}

bool Isprime(int num)
{
	if (num == 1)
		return false;//1不是素数
	if (num == 2 || num == 3)
		return true;
	int i = 2, k = sqrt(num);
	while (i <= k)
	{
		if (num % i == 0)
			return false;//存在非1和自身的因数
		i++;
	}
	return true;
}

static void function3_7()
{
	const int begin = 4;
	const int end = 50;

	int i = begin, j = 2;
	while (i <= end)
	{
		if (i % 2)
		{
			//cout << "i不是偶数=" << i << endl;
			i++;
			continue;
		}

		int tmp_1 = j, tmp_2 = i - j;
		while (1)
		{

			if (Isprime(tmp_1) && Isprime(tmp_2))
				break;
			tmp_1++;
			tmp_2--;

		}
		cout << i << "=" << tmp_1 << "+" << tmp_2 << endl;
		i++;
	}

}

int Ackman(int m, int n)
{
	if (m == 0)
		return n + 1;
	else if (n == 0)
		return Ackman(m - 1, 1);
	else
		return Ackman(m - 1, Ackman(m, n - 1));
}

static void function3_9()
{
	cout << "Ackman(2,1)=" << Ackman(2, 1) << ",Ackman(3,2)=" << Ackman(3, 2) << endl;
}

int main6()
{
	function3_9();
	return 0;
}
