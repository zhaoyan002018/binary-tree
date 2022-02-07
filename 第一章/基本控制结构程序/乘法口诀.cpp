#include<iostream>
#include<iomanip>
using namespace std;


int main3()
{
	//这里有俩个循环，其中一个循环嵌套在另一个循环中，外层循环即列数，内层循环即行数。
	//可以看做实际上就是按行输出的，但是每行输出的长度，由列数决定。

	int row = 1;//行 
	int col;//列

	int n = 1;
	cout << '*' << '\t';
	while (n <= 9) {
		cout << n << '\t';
		n++;
	}
	cout << endl;

	for (; row <= 9; row++)
	{
		cout << row << '\t';
		for (col = 1; col <= row; col++)
		{
			int num = col * row;//行*列
			cout << num << '\t';
		}
		cout << endl;
	}
	return 0;

	//这里\t 如果用setw(n)替代的话，就会发现如果第一行结尾输出setw 那么就算输出endl换行了，还是会在第二行起始处进行偏移
	//也就是说setw 和 endl 配合使用时， setw的效果就会保留再endl后一行的输出位置执行，这和setw以及endl的原理有关，需要之后关注
	//TODO 上述研究
}
