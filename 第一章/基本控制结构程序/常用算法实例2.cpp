#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
bool IsPrime(int number);
//���100�������е�����
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

//�׼�����,���ܵĴ������޸��Ҵ��ǿ�֪�ģ����������ý���������
void func2()
{
	//���������20��ĸ�������33��С�������300��ͬʱҪ���㹫��+ĸ��+С��������Ϊ100

	ofstream ofile;
	ofile.open("C:\\Users\\ZY\\source\\repos\\c++�������ѧϰ\\baiji.txt");
	int x, y;//�ֱ��ʾ������ĸ����������
	for (x = 0; x <= 20; x++)
		for (y = 0; y <= 33; y++)
		{
			if (5 * x + 3 * y + (100 - x - y) / 3 == 100 && (100 - x - y) % 3 == 0)  //ע��С����һ��Ҫ�ܱ�3�������У���Ϊ�����ڼ���֮1�ļ����϶���3��3���������1Ǯ������
			{
				cout << "������=" << x << " ĸ����=" << y << " С����=" << 100 - x - y << endl;
				ofile << "������=" << x << " ĸ����=" << y << " С����=" << 100 - x - y << endl;
			}
		}
	ofile.close();

}

//�����Լ�������Ʒ���ͨ�������һ��������֪�⣬��ͬ���ķ����������������⣬���������⣬����ֵ�������⡣
void func3()
{
	int x, y;
	cout << "��������������" << endl;
	cin >> x >> y;

	//��Ȥ���ǣ�����Ҫ֪�������������Ĵ�С��ϵ

	while (1)
	{
		int res = x % y;
		if (res == 0)break;
		x = y;
		y = res;
	}

	cout << "���Լ���ǣ�" << y << endl;

}

//��sinx�Ľ���ֵ��Ҫ�����С��0.0001
void func4()
{
	cout << "������һ��С��1����:" << endl;
	float x;
	cin >> x;
	//sinx = x - x��3�η�/3�Ľ׳� + x��5�η�/5�Ľ׳� -����
	//Ҫ�����С��0.0001��Ҳ���ǵ��Ƶ���n��ʱ������ֵҪС��0.0001���ɡ�
	//û��ֱ�ӵõ���n���С�Ĺ�ʽ�����ǿ���֪��ǰһ�����һ��Ĺ�ϵ��ʽ��item = item *x*x/(2*n)*(2*n+1)

	int n = 2;
	float item = x * x * x / 2 * 3;  //�ȸ�����һ�ʽ 
	float sinx = x - item;
	int symbol = -1;

	while (item > 0.0001)
	{
		item = item * x * x / (2 * n) * (2 * n + 1);

		if (n % 2 == 0)//����ʱΪ��
			sinx += symbol * item;
		else
			sinx += item;

		n++;
	}
	cout << "sinx�Ľ���ֵΪ��" << sinx << endl;

}

//2����ת��Ϊ10���ƣ�ÿλ�����������Ը�λ��ȨȻ����ӣ�����ʽ���
void func5()
{
	cout << "������8λ���������У�" << endl;;
	/*char bin[100];
	cin >> bin;*/

	//�������飬�ð�λһ��һ������,cin�޷��ж�����ĳ��ȶ��Զ�ֹͣ���롣
	char bin[8];
	int j = 0;
	for (; j < 8; j++) cin >> bin[j];//�����뻺�����У�����ó����ݡ����Բ���Խ��


	int i = 0, dec = 0;
	for (; i < 8; i++)
	{
		dec *= 2;
		dec += bin[i] - '0';
	}
	cout << "ת��Ϊ10����Ϊ��" << dec << endl;
}

//�ټ�������ļ��ж�ȡ��
void func6()
{
	ifstream ifile;
	ifile.open("C:\\Users\\ZY\\source\\repos\\c++�������ѧϰ\\baiji.txt");

	while (!ifile.eof())
	{
		char tmp;
		ifile.get(tmp);//������Ϊ�ı��ļ���������ǿ�������
		cout << tmp;
	}
	ifile.close();
}
int main6()
{
	enum Typename{Apple,Banana, tomato,Strawberry=2, Mulberry}fruits3;//ֻ�и�ֵ�ͱȽ�����
	Typename fruits, fruits2;
	//fruits = 1; ����ֵ�����ܽ����γ�����ֵ��ö�ٱ���
	fruits = Apple;
	fruits2 = fruits;
	fruits3 = Mulberry;
	cout << fruits << '\t' << fruits3 << endl;
	//func5();
	func6();
	return 0;
}
