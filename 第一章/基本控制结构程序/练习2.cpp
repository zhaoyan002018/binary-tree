#include<iostream>
#include<iomanip>

using namespace std;

//求阶乘的和 可知是递推法，由第n-1项，可知第n项
//3!= 2! * 3 ; n! =(n-1)!*n
void func2_7()
{
	cout << "请输入n=";
	int n;
	cin >> n;
	int i = 1;

	int result = i;
	int sum = 0;
	while (i <= n)
	{
		result *= i;
		sum += result;
		i++;
	}

	cout << " 求得1！+2！+……n != ：" << sum;
}
//猴子吃桃的问题，也是一个递推的问题
void func2_8()
{
	//今天剩余的是昨天总数的一半-1；
	//注意吃的是一半多，那么如果剩3个，要吃2个，所以第9天，是4个
	int n = 9; //循环次数
	int total = 1;//桃子数量

	while (n)
	{
		total += 1;
		total *= 2;
		n--;
	}
	cout << "桃子的总数为：" << total << endl;

}

void func2_9()
{
	int number[100];
	int i = 0;
	double avg = 0;
	do {
		cin >> number[i];
		avg += number[i];
		i++;
	} while (number[i - 1]);
	if (i != 1)
		avg /= (i - 1);
	int j = 0;

	int positiveN = 0;
	int negativeN = 0;
	while (j < i - 1)
	{
		if (number[j] > 0)
			positiveN++;
		else
			negativeN++;
		j++;
	}
	cout << "avg = " << avg << "，正数个数为：" << positiveN << "，负数个数为：" << negativeN << endl;

}
void func2_10()
{
	int i = 0, number;
	do {
		number = 7 * i + 2;
		if (number % 5 == 3)
			if (number % 3 == 2)
				cout << number << '\t';
		i++;
	} while (number <= 500);
	cout << endl;

	//或者使用穷举法
	for (i = 1; i <= 500; i++)
		if ((i % 3 == 2) && (i % 5 == 3) && (i % 7 == 2))
			cout << i << '\t';
	cout << endl;
}

void func2_11()
{
	cout << "1000之内的完全数有：";
	int n = 6;
	while (n < 1000)
	{
		int i = 1, tmp = 0;
		while (i <= n / 2)
		{
			if (n % i == 0) {
				tmp += i;
			}
			i++;
		}
		if (tmp == n)
			cout << tmp << '\t';

		n++;
	}
}

void func2_12()
{
	int x = 0, z, num = 0;

	while (x <= 10) {
		int y = 0;
		while (y <= 20) {
			z = 100 - 10 * x - y * 5;
			if (z > 0) {
				cout << "x=" << x << ",y=" << y << ",z=" << z << endl;
				num++;
			}
			y++;
		}
		x++;
	}
	cout << "共有:" << num << "种" << endl;

}

void func2_13()
{
	cout << "请输入x的值：";
	double x;
	cin >> x;

	int i = 2;
	double item = x, num = x;
	int symbol;

	while (1)
	{
		item *= x * x;
		if (item / (2 * i - 1) < 1e-5)
		{
			break;
		}
		if (i % 2 == 0)
			symbol = -1;
		else
			symbol = 1;
		num += symbol * item / (2 * i - 1);
		i++;
	}
	cout << "近似值结果为" << num << endl;
}

void func2_15()
{
	char jia[] = { 'A','B','C','D','E' };
	char yi[] = { 'J','K','L','M','N' };
	//jia[0]不能遇到yi[0]，jia[3],jia[4]不能遇到yi[3];
	//将可能出现的比赛名单存放在哪里？ 目前不知道共有多少结果出现
	//char result[5][2];
	//可以看做jia数组不变，yi数组如何排序？
	char sortYi[5];


	//a[5] a[0] 记录第一个位置可能出现的所有结果 a[1] 则第二个位置可能出现的所有结果 并if如果这个结果是前面出现过的则pass

//本来寻找的次数是5!，但同样可以通过5的5次方循环来实现，表示每个位置都进行一次寻找组合

	int i, j, k, l, n;

	int num = 0;

	//每层循环决定对应jia名单的对手
	for (i = 0; i < 5; i++)
	{
		if (i == 0)
			continue;
		sortYi[0] = yi[i];

		for (j = 0; j < 5; j++)
		{
			if (j != i)
			{
				sortYi[1] = yi[j];
				for (k = 0; k < 5; k++)
				{
					if (k != i && k != j)
					{
						sortYi[2] = yi[k];
						for (l = 0; l < 5; l++)
						{
							if (l == 3)
								continue;
							if (l != i && l != j && l != k)
							{
								sortYi[3] = yi[l];
								for (n = 0; n < 5; n++)
								{
									if (k == n)
										continue;
									if (n != l && n != i && n != j && n != k)
									{
										num++;
										sortYi[4] = yi[l];
										//输出sortYi
										cout << "甲队名单：";
										int tmp = 0;
										while (tmp < 5)
										{
											cout << jia[tmp] << " ";
											tmp++;
										}
										cout << '\t' << "乙队名单：";
										tmp = 0;
										while (tmp < 5)
										{
											cout << sortYi[tmp] << " ";
											tmp++;
										}
										cout << endl;
									}
								}
							}
						}
					}

				}
			}

		}
	}
	cout << "总共有：" << num << "种可能" << endl;

}


int main()
{
	func2_10();
	return 0;
}
