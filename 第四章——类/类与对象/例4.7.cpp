#include<iostream>
using namespace std;

class complex
{
public:
	complex();
	complex(double, double);
	~complex();
	complex(complex&);
	void assign(complex& com);
	void printf();

private:
	double real, image;
};

complex::complex()
{
	real = 0.0;
	image = 0.0;
	cout << "初始化 0 0" << endl;
}
complex::complex(double r, double i = 0.0)
{
	real = r;
	image = i;
	cout << "初始化 " << r << "\t" << i << endl;
}



complex::~complex()
{
	cout << "析构释放" << endl;
}

void complex::assign(complex& com)
{
	real = com.real;
	image = com.image;
}

void complex::printf() {
	cout << real << '+' << image << 'i' << endl;
}

inline complex::complex(complex& com) {
	cout << "Copy" << com.real << "\t" << com.image << endl;
	real = com.real;
	image = com.image;
}

complex fun(complex);
complex& fun2(complex);
complex& fun3(complex& com);
complex funLocal(complex com);
complex global; //注意可能在其他文件的测试中，影响到输出信息。

int main7()
{
	cout << "进入主函数main" << endl;
	complex com1, com2(5.6, 7.5);
	complex com3 = com1;//调用复制构造函数，但调用的是com1的还是com3的复制构造函数呢？答案是Com3的，com1是复制构造函数的参数
	com3.printf();
	global.printf();

	//com1 = fun(com2);
	//com1 = fun2(com2);
	//func2由于返回值是引用，则不会为因为要创建临时空间存在返回值而进行一次复制copy。
	//需要注意的是：经过后续验证，发现尽管fun需要拷贝，但也不是要给com1进行复制构造，com1已经构造过了，而复制拷贝的是为临时对象进行的。而临时对象和com1进行了"="的操作，猜测进行的是重构后的赋值。

	//com1 = global;//并未调用复制构造函数。why？是因为com1已经初始化了吗？
	//complex com4 = global;//确实如此，已经初始化了的对象，不会再调用复制构造函数，那么com1 = global是进行了什么操作呢？

	//complex com4 = fun(com2);//会失败，因为返回值并非引用，无法调用复制构造函数，构造函数的形参必须为引用。进一步验证了上述结论：初始化的对象，不会再调用复制构造函数，而自然未初始化的对象，需要调用复制构造函数。
	//complex com4 = fun2(com2);//通过，并调用com4的复制构造函数，func2函数返回值作为实参。

	//complex com4 = fun3(com2);//由于fun3的形参是引用，那么便不需要进行一次copy
	//com1 = fun3(com2);
	//com4 = fun3(com2);
	//第一次的com4和com1的区别在于，com4进行了一次拷贝，但com1没有。
	//原因就在于已经初始化了的对象，不会再调用复制构造函数

	//complex com4 = funLocal(com2); 会失败，因为返回值并非引用，无法调用复制构造函数。
	com3 = funLocal(com2);//这里应该调用的是默认重构的=运算符对应的成员函数

	com1.printf();//
	cout << "退出主函数" << endl;
	return 0;
}
complex funLocal(complex com)
{
	cout << "进入函数funLocal" << endl;
	cout << "退出函数funLocal" << endl;
	return com;
	//进入函数前要进行copy，返回前也要进行copy
}

complex fun(complex com)//进入函数前，要把实参通过复制构造函数传递给形参。并在函数退出前，把形参对象通过析构函数释放掉。
{
	cout << "进入函数fun" << endl;
	global.assign(com);//传递com 同样也得进行复制，但形参为引用类型时则不用。
	cout << "退出函数fun" << endl;
	return global;//因为返回类型不是引用，所以要进行一次拷贝
}
complex& fun2(complex com)//进入函数前，要把实参通过复制构造函数传递给形参。并在函数退出前，把形参对象通过析构函数释放掉。
{
	cout << "进入函数fun2" << endl;
	global.assign(com);//传递com 同样也得进行复制，但形参为引用类型时则不用。
	cout << "退出函数fun2" << endl;
	return global;//此时外部com1 =fun2(com2)则不必进行复制构造函数了。
}

complex& fun3(complex& com)//
{
	cout << "进入函数fun3" << endl;
	global.assign(com);//传递com 同样也得进行复制，但形参为引用类型时则不用。
	cout << "退出函数fun3" << endl;
	return global;//此时外部com1 =fun2(com2)则不必进行复制构造函数了。
}
