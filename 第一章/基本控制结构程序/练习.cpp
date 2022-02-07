#include<iostream>
#include<iomanip>
using namespace std;

void func2_2()
{
	enum { LESS, MID, BIG }opLevel;
	cout << "请输入X的值:" << endl;
	int x, y;
	cin >> x;
	if (x < 1)
		opLevel = LESS;
	else if (1 < x <= 10)
		opLevel = MID;
	else
		opLevel = BIG;

	switch (opLevel)
	{
	case LESS:
		y = x;
		break;
	case MID:
		y = 2 * x - 1;
		break;
	case BIG:
		y = 3 * x - 11;
		break;

	default:
		cout << "出现错误运算等级" << endl;
		break;
	}
	cout << "y=" << y << endl;

}
void func2_3()
{
	cout << "请输入百分制的成绩：";
	int grade;
	cin >> grade;
	enum { First = 1, Secpnd, Third, Fourthly, Fifth }grade_5;
	if (grade > 90)
		grade_5 = Fifth;
	else if (grade >= 80)
		grade_5 = Fourthly;
	else if (grade >= 70)
		grade_5 = Third;
	else if (grade >= 60)
		grade_5 = Secpnd;
	else
		grade_5 = First;


	cout << "按5分制等级为: " << grade_5 << endl;
}

int baseNumber = 500;
void func2_4()
{
	cout << "请输入月收入：";
	int income;
	cin >> income;
	float taxes = 0;


	int k = income / baseNumber;
	switch (k)
	{
	default:
		taxes += (income - 200 * baseNumber) * 0.45;
	case 200:
		if (k > 200)
			taxes += 3 * baseNumber / 10;
		else
			taxes += (income - 4 * baseNumber) / 10;
	case 160:
		if (k > 160)
			taxes += 6 * baseNumber * 0.15;
		else
			taxes += (income - k * baseNumber) * 0.15;
	case 120:
		if (k > 10)
			taxes += 6 * baseNumber * 0.15;
		else
			taxes += (income - k * baseNumber) * 0.15;
	case 80:
		if (k > 10)
			taxes += 6 * baseNumber * 0.15;
		else
			taxes += (income - k * baseNumber) * 0.15;
	case 40:
		if (k > 10)
			taxes += 6 * baseNumber * 0.15;
		else
			taxes += (income - k * baseNumber) * 0.15;
	case 10:case 9:case 8:case 7:case 6:case 5:
		if (k > 10)
			taxes += 6 * baseNumber * 0.15;
		else
			taxes += (income - k * baseNumber) * 0.15;
	case 4:case 3:
		if (k > 4)
			taxes += 3 * baseNumber / 10;
		else
			taxes += (income - k * baseNumber) / 10;
	case 2:
		if (k > 2)
			taxes += baseNumber / 20;
		else
			taxes += (income - k * baseNumber) / 20;
	case 0:
		break;
	}


}

void func2_5()
{
	//*数量递增 1 3 5
	//行起始位置，即空格数量减少

	int i = 1, j = 0, l = 16;//i指数量，j指行起始要减去去的长度,l表示起始位置
	int n = 4;//循环的层数
	const int interval = 3;//*之间相距的长度

	while (n)
	{
		int first = l - j;
		while (first)
		{
			cout << " ";
			first--;
		}//偏移到起始位置

		int tmp = i;
		for (; tmp; tmp--)
		{
			cout << "*";
			int tmp2 = interval;
			while (tmp2)
			{
				cout << " ";
				tmp2--;
			}
			//偏移间隔
		}
		cout << endl;

		i += 2;
		j += interval + 1;//这里+1是因为*本身也占用一个大小
		n--;
	}

	//下面输出固定起始，以及固定数量的*
	const int first = l - (interval + 1);
	i = 3;
	n = 3;
	while (n)
	{

		for (int t = 0; t < first; t++)
		{
			cout << " ";
		}//偏移到起始位置
		int tmp = i;
		for (; tmp; tmp--)
		{
			cout << "*";
			int tmp2 = interval;
			while (tmp2)
			{
				cout << " ";
				tmp2--;
			}
			//偏移间隔
		}
		cout << endl;
		n--;
	}

}

void func2_6()
{
	//分为递增和递减俩个循环，那么能不能一个循环解决呢？1、直接用列举法举例出所有可能性
	int list[] = { 1,3,5,7,5,3,1 };
	int i = 0;
	const int l = 30;//起始位置
	const int interval = 2;//间隔长度
	//while (list[i])
	while (i < 7)
	{
		char chr = 'B';
		cin.get(chr);
		//获得单个字符
		int n = list[i];
		int first = l - (n - 1) / 2 * (interval + 1);
		while (first)
		{
			cout << " ";
			first--;
		}
		for (; n; n--)
		{
			cout << chr;

			int tmp = interval;
			while (tmp)
			{
				cout << " ";
				tmp--;
			}
		}
		cout << endl;

		i++;
	}

}

int main12()
{
	func2_6();
	return 0;
}
