#include<iostream>

using namespace std;

int main3()
{
	//字符数组 和 数组
	int arr1[5] = { 1,2,3,4,5 };
	char arr2[] = "Hello";
	const char* str = "Hello";

	arr1[0] = 6;
	arr2[0] = 'h';

	cout << arr1 << endl;
	cout << arr2 << endl;

	cout << arr1[0] << endl;

	return 0;
}
