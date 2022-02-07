#include<iostream>

using namespace std;

int main()
{
	int a = 3, b = 5, c = 0;
	float x = 2.5, y = 8.2, z = 1.4;
	char ch1 = 'a', ch2 = '5', ch3 = '0', ch4;


	//cout << x + (int)y % a << " x=" << x << " y=" << y << " a=" << a << endl;
	//cout << (x = z * b++, b = b * x, b++) << " x=" << x << " b=" << b << " z=" << z << endl;
	//cout << int(ch4 = ch3 - ch2 + ch1) << endl;
	cout << y / z << '\t' << int(y / z) << '\t' << (int)y / (int)z << " y=" << y << " z=" << z << endl;
	//cout << (!(a > b) && c && (x *= y) && b++) << " a=" << a << " b=" << b << " c=" << c << " x=" << x << " y=" << y << endl;
	//cout << (ch3 || (b += a * c) || c++) << " a=" << a << " b=" << b << " c=" << c << endl;
	//cout << (z = (a << 2) / (b >> 1)) << " a=" << a << " b=" << b << " z=" << z << endl;

	return 0;
}
