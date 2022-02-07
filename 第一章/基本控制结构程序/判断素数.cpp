#include<iostream>
#include<iomanip>
using namespace std;

//素数是除了1和自身外，不能再被其余数所整除的数。 0不是素数。
//可以使用穷举法：


bool IsPrime(int number)
{
	bool result = true;

	if (number == 0)
	{
		result = true;
		return result;
	}
	if (number == 1)
		return result;

	int i = 2;
	/*while (number > i)
	{
		if (number % i == 0) {
			result = false;
			break;
		}
		i++;
	}*/

	//这里可以不用从1到number,从1到根号number取整即可。
	int k = sqrt(number);
	//cout << k << endl;
	while (k >= i) //注意用k时，也包含第9个数，因为不是他本身的数。
	{
		if (number % i == 0) {
			result = false;
			break;
		}
		i++;
	}

	return result;
}
int main4()
{
	int number;
	cout << "请随意输入一个整数" << endl;
	cin >> number;
	if (IsPrime(number)) {
		cout << number << "是素数" << endl;
	}
	else
		cout << number << "不是素数" << endl;

	return 0;
}
