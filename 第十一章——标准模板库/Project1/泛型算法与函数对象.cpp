#include<algorithm>
#include<vector>
#include<iostream>
#include<iterator>
#include<functional>
#include<list>
#include<deque>
using namespace std;

//函数对象，是一个只有一个成员函数对象的模板类，该类实现了对（）的重载

//求和函数对象的定义和测试
template<typename T>class Sum
{
	T res;
	//额外数据
public:
	Sum(T r) { res = r; }
	T operator()(T data) {
		res += data;
		return res;
	}

};

//采用函数对象的，泛型算法（函数模板）
template<typename ObjFunc, typename T> T func1(ObjFunc func, const T& data)
{
	return func(data);
}
template<typename ObjFunc, typename T> T func2(ObjFunc& func, const T& data)
{
	return func(data);
}



int main3()
{
	Sum<int> sum1(5);
	int i = 10, j = 15;

	cout << func1(sum1, i) << endl;
	cout << func1(sum1, j) << endl;

	cout << func2(sum1, i) << endl;
	cout << func2(sum1, j) << endl;

	cout << func1(Sum<int>(5), i) << endl;//使用函数对象，往往采用无名对象
	//cout << func2(Sum<int>(0), j) << endl;//研究copy泛型算法，貌似不能用&作为函数对象的类型。
	return 0;
}
