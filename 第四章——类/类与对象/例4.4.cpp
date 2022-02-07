#include<iostream>
using namespace std;

double temp;

double fsqr1(double a)
{
	temp = a * a;
	return temp;
}

double& fsqr2(double a)
{
	temp = a * a;
	return temp;//由于返回的是全局变量的引用，所以不需要再内存申请临时空间做一次拷贝。
}


double fsqr3(double a)
{
	double temp2 = a * a;//如果返回的是局部变量呢？
	return temp2;
}

double& fsqr4(double a)
{
	double temp2 = a * a;//如果返回的是局部变量呢？发现此时能够编译通过，但是会存在告警，不应该忽略这个告警。
	return temp2;
}

//对于数组，只能引用数组元素，不能引用数组，因为数组名本身就是地址。 测试如下：
//另外记得，返回值类型也不能为数组。
//关于引用说明符&，在解析声明的过程中他应该如同*的优先级一样

//int* arrFunc(int& a[]) 如果是引用数组，则直接编译不通过


int main4()
{
	double x = fsqr1(5.5);
	double y = fsqr2(5.5);
	double z = fsqr3(5.5);
	double t = fsqr4(5.5);


	cout << "x=" << x << '\t' << "y=" << y << "\t" << "z=" << z << "\t" << "t=" << t << endl;
	return 0;

}
