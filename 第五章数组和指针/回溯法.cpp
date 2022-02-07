#include<iostream>
using namespace std;

//回溯法：从局部解找出解决问题的全部解，若试探成功得到问题的解，试探失败则逐步向后退，改变局部解后再向前试探。

//八皇后问题：8X8国际象棋盘上摆上8个皇后，要求没有任何俩个皇后在一行，一列及同一对角线上。

const int NUM = 8;

bool check(int method[], int i, int j)
{
	//拿出当前的旗子，和之前全部的旗子进行比较：查看当前的旗子的位置是否满足条件。
	bool out = true;

	if (i == 0)
		return out;

	int k = i - 1;
	while (k >= 0)
	{
		if (j == method[k] || (abs(i - k) == abs(j - method[k])))//在同一列//(i + j == k + method[k])//在同一对角线上,+的判断只能判断右对角线，但左对角线没有考虑
		{
			out = false;
			break;
		}

		k--;
		continue;

	}

	return out;
}

bool checkBack(int i, int j);

static void func()
{
	int i = 0;//行
	int method[NUM] = {};//存放每一行旗子的位置。
	bool back = false;
	int tmp = 0;


	while (1) {
		int j;
		if (i >= NUM)
		{
			tmp = 0;
			cout << "method[]=";
			while (tmp < 8) {
				cout << method[tmp];
				tmp++;
			}
			cout << endl;
			i--;
			method[i]++;
		}

		j = method[i];//这里是为了考虑回溯后从上一个棋子所在列开始寻找，但如果回溯前位置的旗子没有归位为0，那么找到后，下一列时并没有从0开始重新寻找。
		method[i] = 0;

		if (back)
		{
			j++;
			back = false;
			if (j >= NUM) {
				method[i] = 0;
				if (i == 0)
					break;//回溯到第一行且最后一列退出循环

				i--;
				back = true;


				/*	cout << "进行一次回溯2,回溯到第" << i << "行,回溯时数组为：";
					tmp = 0;
					cout << "method[]=";
					while (tmp < 8) {
						cout << method[tmp];
						tmp++;
					}
					cout << endl;*/
				continue;
			}
		}

		while (!check(method, i, j))
		{
			j++;
			if (j >= NUM)
			{
				method[i] = 0;
				//当前行清零,很重要，没有会出错
				i--;
				back = true;
				/*cout << "进行一次回溯,回溯到第" << i << "行,回溯时数组为:";
				tmp = 0;
				cout << "method[]=";
				while (tmp < 8) {
					cout << method[tmp];
					tmp++;
				}
				cout << endl;*/
				//说明整行没有符合的位置，需要进行回溯。
				//回溯时，要从存储的列之后开始寻找。
				//如果回溯到第一行的最后一列，还是没有的话，退出循环。
			}
		}
		if (back)
			continue;

		method[i] = j;
		i++;
	}

}

int main1()
{
	func();
	return 0;
}
