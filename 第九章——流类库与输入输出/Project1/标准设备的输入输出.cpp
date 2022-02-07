#include<iostream>
using namespace std;

//标准输入设备指的是键盘，输出指的是显示屏


//标准输入输出成员函数
void func()
{
	char str[255];
	int i, n;
	cout << "输入字符" << endl;
	i = cin.get();
	cout << endl;
	n = cin.rdstate();
	cout << "当前的状态字为" << n << endl;
	cout << "当输入字符时，取得的是" << i << endl;

	if (n == 0) cin.ignore(255, '\n');
	cin.clear(0);
	cout << "请输入字符串1：" << endl;
	cin.getline(str, 255);
	cout << endl;
	cout << "状态字为：" << cin.rdstate() << endl;
	i = cin.gcount();
	cout << "字符串为：" << str << '\t' << "读入字符数为：" << i << '\t';
	cout << "串长为：" << strlen(str) << endl;

	//cin.clear(0);
	cout << "输入字符串2：" << endl;
	cin.getline(str, 255);
	cout << endl;
	cout << "状态字为：" << cin.rdstate() << endl;
	i = cin.gcount();
	cout << "字符串为：" << str << '\t' << "读入字符数为:" << i << '\t';
	cout << "串长为：" << strlen(str) << endl;

}

void func2()
{
	int i, j;
	int n;
	char c;
	cin >> i;
	n = cin.rdstate();
	if (cin)//对比较运算进行了重载，跟ios::fail()等效
		cout << "cin为1，表明正常输入" << endl;
	else
		cout << "cin为0，表明输入流有误" << endl;
	cout << "第一次输入后的状态字为：" << n << endl;
	cin >> c;//猜测第二次cin>>时，会将之前的缓冲区都清空,并不是，只是对\n有处理。

	//由于每次cin后并不会处理缓冲区，所以需要手动清除一次,并判断state标志位状态。
	cout << "i=" << i << ",c=" << c << endl;
}

int main2()
{
	func2();
	return 0;

	char str[256];
	int i;
	cout << "请输入整数:" << endl;
	cin >> i;//此时缓冲区内剩下\n

	while (cin.fail())
	{
		cout << "状态字为：" << cin.rdstate() << endl;
		cin.clear(0);
		cin.getline(str, 255);
		cout << "输入错误，请重新输入整数" << endl;
		cin >> i;
	}
	cin.getline(str, 1);//cin>>i,此时缓冲区还保留\n所以需要清空
	cout << "请输入字符串：" << endl;
	cin.getline(str, 255);//cin缓冲区为空时才可以再次输入。
	cout << "请确认字符串：" << str << endl;
	cout << "如果有误，输出r后重新输入，否则继续" << endl;
	char c;
	cin >> c;//注意回车会留在cin缓冲区中。
	while (c == 'r')
	{
		cin.getline(str, 1);
		cout << "请输入字符串：" << endl;
		cin.getline(str, 255);
		cout << "请确认字符串：" << str << endl;
		cout << "如果有误，输出r后重新输入，否则继续" << endl;
		cin >> c;
	}

	cout << "输入整数为：" << i << endl;
	cout << "输入字符串为：" << str << endl;

}
