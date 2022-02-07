#include<iostream>
using namespace std;

int& level(int grade, int&, int&, int&);
int test();

int main3()
{
	int TypeA = 0, TypeB = 0, TypeC = 0;
	int grades[6] = { 69,55,80,92,99,85 };

	int i = 0;
	while (i < 6)
	{
		level(grades[i], TypeA, TypeB, TypeC)++;//这里为什么新颖呢？因为使用到了一个新知识：若函数返回值为引用，则这个函数可以作为左值。
		i++;
	}
	cout << "三类学生的数量如下：" << endl;
	cout << "80以下的：" << TypeA << endl;
	cout << "80-90的：" << TypeB << endl;
	cout << "90以上的：" << TypeC << endl;

	//test()++; 编译不通过的原因在于，普通函数若不是引用作为返回值，则不可以成为左值的。

	return 0;

}
int& level(int grade, int& a, int& b, int& c)
{
	if (grade < 80) return a;
	if (grade <= 90) return b;
	return c;
}
int test()
{
	return 5;
}
