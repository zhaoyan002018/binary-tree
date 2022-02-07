#include<iostream>
using namespace std;

class Complex {
public:
	double Real, Image;
	Complex(double real = 0, double image = 0) :Real(real), Image(image) {}
	friend ostream& operator<<(ostream&, Complex&);

	friend istream& operator>>(istream&, Complex&);
};

ostream& operator<<(ostream& ost, Complex& cop)
{
	ost << "(" << cop.Real << "," << cop.Image << ")" << endl;
	return ost;
}

istream& operator>>(istream& ist, Complex& cop)//可输入给cop的可以是只有实部、或者虚实都有，d,(d,d),而且(d)也是允许的
{
	//逐字符处理。
	char c;
	double re = 0, im = 0;
	//ist >> c;//取出一个字符给c,如果全部取完，则需要从键盘输入给ist新的数据。再从ist提出数据给c。
	if (ist >> c, !ist.rdstate())
	{
		//成功处理
		if (c == '(') {
			//实部,再从缓冲区取
			ist >> re;
			ist >> c;
			if (c == ',')
			{
				ist >> im;
				ist >> c;
			}
			if (c != ')')
			{
				cout << "输入格式错误" << endl;
				ist.clear(ios::failbit);//注意此时ist缓冲区并没有清空，只是状态字造成以后无法再从ist中提取了。
				cout << "格式错误，当前状态字置为：" << ist.rdstate();
			}

		}

		else {
			//说明是单d，没有()
			ist.putback(c);
			ist >> re;
			cop.Real = re;
		}

		cop.Real = re;
		cop.Image = im;

	}
	else {
		cout << "当前状态字出错,退出" << endl;
		exit(-1);
	}
	return ist;
}

int main3()
{

	Complex c1;
	while (1)
	{
		cout << "请输入实数：" << endl;
		cin >> c1;
		cout << c1 << endl;
	}
	return 0;
}
