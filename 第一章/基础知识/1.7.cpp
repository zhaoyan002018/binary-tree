#include<iostream>

using namespace std;

int main7()
{
	int a, b, c, d;

	cin >> oct >> a >> b >> hex >> c >> dec >> d;

	cout << a << '\t' << b << '\t' << c << '\t' << d << dec << endl;

	cout << a << '\t' << hex << b << '\t' << oct << c << endl;

	return 0;
}
