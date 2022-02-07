#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

//每行输出5个数据
const int num = 20;
int main1()
{
	ofstream ofile;
	ofile.open("E:\\fibonacii.txt");


	int n;//以后养成一个好习惯，用常量表示固定数量，用变量做迭代。
	int fib1 = 0, fib2 = 1, fib3;
	//cout << fib1 << '\t' << fib2 << '\t';
	ofile << fib1 << '\t' << fib2 << '\t';
	for (n = num - 2; n; n--)
	{
		if (n % 5 == 0)
		{
			//cout << endl;
			ofile << endl;
		}
		fib3 = fib1 + fib2;

		//cout << fib3 << '\t';
		ofile << fib3 << '\t';

		fib1 = fib2;
		fib2 = fib3;

	}
	ofile.close();

	return 0;
}
