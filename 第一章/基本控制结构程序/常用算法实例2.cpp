#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
bool IsPrime(int number);
//输出100以内所有的素数
void func1()
{
	int i = 1;
	for (; i <= 100; i++) {
		if (IsPrime(i))
			cout << setw(7) << i;
		if (i % 10 == 0)
			cout << endl;
	}
}

//白鸡问题,可能的答案是有限个且答案是可知的，但又难以用解析法描述
void func2()
{
	//公鸡最多买20，母鸡最多买33，小鸡最多买300，同时要满足公鸡+母鸡+小鸡的数量为100

	ofstream ofile;
	ofile.open("C:\\Users\\ZY\\source\\repos\\c++程序设计学习\\baiji.txt");
	int x, y;//分别表示公鸡和母鸡的数量。
	for (x = 0; x <= 20; x++)
		for (y = 0; y <= 33; y++)
		{
			if (5 * x + 3 * y + (100 - x - y) / 3 == 100 && (100 - x - y) % 3 == 0)  //注意小鸡数一定要能被3整除才行，因为不存在几分之1的鸡。肯定是3个3个买才能有1钱的收入
			{
				cout << "公鸡数=" << x << " 母鸡数=" << y << " 小鸡数=" << 100 - x - y << endl;
				ofile << "公鸡数=" << x << " 母鸡数=" << y << " 小鸡数=" << 100 - x - y << endl;
			}
		}
	ofile.close();

}

//求最大公约数，递推法，通过问题的一个或多个已知解，用同样的方法逐个推算出其他解，如数列问题，近似值计算问题。
void func3()
{
	int x, y;
	cout << "请输入俩个整数" << endl;
	cin >> x >> y;

	//有趣的是，不需要知道这俩个整数的大小关系

	while (1)
	{
		int res = x % y;
		if (res == 0)break;
		x = y;
		y = res;
	}

	cout << "最大公约数是：" << y << endl;

}

//求sinx的近似值，要求误差小于0.0001
void func4()
{
	cout << "请输入一个小于1的数:" << endl;
	float x;
	cin >> x;
	//sinx = x - x的3次方/3的阶乘 + x的5次方/5的阶乘 -……
	//要求误差小于0.0001，也就是递推到第n项时，它的值要小于0.0001即可。
	//没有直接得到第n项大小的公式，但是可以知道前一项和下一项的关系公式：item = item *x*x/(2*n)*(2*n+1)

	int n = 2;
	float item = x * x * x / 2 * 3;  //先给出第一项公式 
	float sinx = x - item;
	int symbol = -1;

	while (item > 0.0001)
	{
		item = item * x * x / (2 * n) * (2 * n + 1);

		if (n % 2 == 0)//整除时为正
			sinx += symbol * item;
		else
			sinx += item;

		n++;
	}
	cout << "sinx的近似值为：" << sinx << endl;

}

//2进制转化为10进制，每位二进制数乘以该位的权然后相加，多项式求和
void func5()
{
	cout << "请输入8位二进制序列：" << endl;;
	/*char bin[100];
	cin >> bin;*/

	//输入数组，得按位一个一个输入,cin无法判断数组的长度而自动停止输入。
	char bin[8];
	int j = 0;
	for (; j < 8; j++) cin >> bin[j];//从输入缓冲区中，逐个拿出数据。所以不会越界


	int i = 0, dec = 0;
	for (; i < 8; i++)
	{
		dec *= 2;
		dec += bin[i] - '0';
	}
	cout << "转化为10进制为：" << dec << endl;
}

//百鸡问题从文件中读取。
void func6()
{
	ifstream ifile;
	ifile.open("C:\\Users\\ZY\\source\\repos\\c++程序设计学习\\baiji.txt");

	while (!ifile.eof())
	{
		char tmp;
		ifile.get(tmp);//整体作为文本文件输出，而非看作数据
		cout << tmp;
	}
	ifile.close();
}
int main6()
{
	enum Typename{Apple,Banana, tomato,Strawberry=2, Mulberry}fruits3;//只有赋值和比较运算
	Typename fruits, fruits2;
	//fruits = 1; 错误赋值，不能将整形常量赋值给枚举变量
	fruits = Apple;
	fruits2 = fruits;
	fruits3 = Mulberry;
	cout << fruits << '\t' << fruits3 << endl;
	//func5();
	func6();
	return 0;
}
