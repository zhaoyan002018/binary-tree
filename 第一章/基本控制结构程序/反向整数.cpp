#include<iostream>
#include<iomanip>
using namespace std;


//反向不超过9位的整数


void printfInt(int number)
{
	int arr1[10];
	int tmp = number;
	//123 可以通过 123%10 =3 然后123向右移动得到12(移动方式通过/10) 继续12%10=2  1%10=1，每个余数用数组保存，再正向输出就是123的反向。
	int i = 0;
	for (; tmp; i++) //注意这里，i指向的是arr1下一个位置，而非最后一个有效数据。
	{
		arr1[i] = tmp % 10;
		tmp = tmp / 10;
	}

	for (int j = 0; i > j; j++)
	{
		cout << arr1[j];
	}
	cout << endl;
	//这里除了循环j次cout外，还可以通过计算总数后，只cout一次
	int result = arr1[0];
	for (int j = 1; i > j; j++)
	{
		result *= 10;
		result += arr1[j];

	}
	cout << result;
	cout << endl;

}

//反向无限大的数？ 输入的时候保存也要注意大小，int是4个字节，也就是整数最大为2的31次方-1=2147483647 长度为10，因为负数站了1位  1个字节是8位 ，那么就得用别的数据结构接受了，因为要是无限大，就得动态申请空间了。

//反向字符串？ 除了用数组保存外，还有什么好方法？因为字符串可以很长。

int main2()
{
	int number;
	cout << "请输入一个整数:" << endl;
	cin >> number;
	//printfInt(number);
	return 0;
}
