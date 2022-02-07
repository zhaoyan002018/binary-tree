#include<iostream>
using namespace std;

//定义内联函数，实现求3个实数中的最大数。

inline double Max(double a, double b, double c)
{
	double max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	return max;

	/*
	if(a>b&&a>c)return a;
	if(b>a&&b>c)return b;
	return c;
	*/
}

static void function3_11()
{
	double a, b, c;
	cout << "请输入a,b,c的值：";
	cin >> a >> b >> c;
	cout << "其中最大值为：" << Max(a, b, c) << endl;
}

inline bool isNumberChar(char n)
{
	//if ('0' <= n <= '9') 瞎写。。这是数学写法，但是却能通过的原因在哪？
	if ('0' <= n && n <= '9')
		return true;
	return false;
}

static void function3_12()
{
	char a;
	cout << "请输入一个字符:";
	cin >> a;
	if (isNumberChar(a))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "判断是否为数字字符的结果为：" << isNumberChar(a) << endl;
}

int quYu(int a, int b)
{
	return a % b;
}
int quYu(double a, double b)
{
	//return int(a) % int(b); 这样小数点后直接舍弃，并非四舍五入。

	//以下俩种算法：
	//return (int(a * 10) % int(b * 10)) / 10;
	//这里需要增加对负数的判断，如果是负数，四舍五入的方式就成了-0.5
	return int(a + 0.5) % int(b + 0.5);//因为float型给int型赋值，会直接取整，+0.5后，就实现了四舍五入 
}

static void function3_13()
{
	int a, b;
	double c, d;
	cout << "请输入俩个整数：";
	cin >> a >> b;
	cout << "求得余数为：" << quYu(a, b) << endl;

	cout << "请输入俩个实数：";
	cin >> c >> d;
	cout << "求得余数为：" << quYu(c, d);
}

void p3(int w)
{
	if (w > 0)
	{
		int i;

		p3(w - 1);

		p3(w - 2);
		for (i = 0; i < w; i++) cout << '\t' << w;
		cout << endl;
	}
}
int main()
{
	p3(4);
	//function3_13();
}
