#include<iostream>
#include<math.h>

using namespace std;

bool IsHuiwen(int n)
{
	//判断是否为回文，要利用%得到各个位置的值，而且始终是得到的最右边的值，所以能不能不用保存全部，只用保存一半即可，知道事先得知总长度。
	//上述算法不够简便，还得重新比较得到的新值的左右，更好的算法是将得到的新值不跟自身作比较，而是形成一个新的整数跟原本的旧整数做逻辑比较即可。
	int newN = 0;
	int i = n;
	while (i)
	{
		if (newN) {
			newN *= 10;
		}
		int tmp = i % 10;
		i = i / 10;
		newN += tmp;
	}
	if (newN == n)
		return true;
	else
		return false;
}
//10<m<1000 且m、m的2次方、m的3次方均为回文数
//考察结构化编程，由粗到精，逐步细化
void function3_4()
{
	int i = 11;
	while (i < 1000)
	{
		if (IsHuiwen(i) && IsHuiwen(i * i) && IsHuiwen(i * i * i))
			cout << "m=" << i << "时,i的2次方，3次方分别为：" << i * i << "," << i * i * i << endl;
		i++;
	}
}

int x = 3;
int main2()
{
	int x = 2, y = 3;
	//cout << pow(x, y);
	cout << ::x;
	//function3_4();
	return 0;
}
