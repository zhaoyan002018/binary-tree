#include<iostream>

using namespace std;

int main9()
{
	/*
	//测试引用类型的b变量，到底有没有占用空间，
	char a = 'a';
	//char& b = a;
	//char* b = &a;
	char c = 'b';
	cout << "a变量地址为：" << (void*)& a << "\t" << "c变量的地址为:" << (void*)& c << endl;
	//若有引用：a:00B9FDEF  c:00B9FDD7		差值为:0x18
	//没有引用语句：a:008FFB9F  c::008FFB93  差值为:0xc
	//没有引用语句：a:005DF773  c::005DF767	 差值为：0xc
	//若采用指针:a:008FFDBF  c:008FFDA7		差值为:0x18

	//说明引用本身是占有空间的。
	*/

	/*
	int a = 1;
	//int& b = a;
	//char* b = &a;
	int c = 1;
	cout << "a变量地址为：" << &a << "\t" << "c变量的地址为:" << &c << endl;
	//a变量地址为：00CFFDC4   c变量的地址为:00CFFDAC	差值为:0x18
	//去掉引用 a变量地址为：0079F9F4   c变量的地址为:0079F9E8	差值为:0xc
	*/
	double a = 1;
	//double& b = a;
	//char* b = &a;
	double c = 1;
	cout << "a变量地址为：" << &a << "\t" << "c变量的地址为:" << &c << endl;
	//a变量地址为：004FFEC4   c变量的地址为:004FFEA8	差值为:0x1c	
	//去掉引用：a变量地址为：005BFA48   c变量的地址为:005BFA38	差值为:0x10

	//发现无论怎么改变，引用的长度都是0xC，但为什么长度是C呢？也就是12位？1个半字节？ double类型长度为28位，3个半字节？int和char都是3字节？
	return 0;
}
