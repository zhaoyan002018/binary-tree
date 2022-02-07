#include"stack.h"
//异常捕获机制的步骤大致为1、编写异常类，2、try块中throw出异常对象，3、try下方用catch捕获处理异常。此时try中的原本流程被中断。

//俩种抛出异常的方式：
void throwFunc_separ()
{
	int a[5] = { 1,2,3,4,5 }, b[5] = {}, i;
	Stack<int>istack(4);

	try {
		for (i = 0; i < 5; i++)
			istack.Push(a[i]);
		istack.PrintStack();
	}
	catch (pushOnFull<int>) { cerr << "栈满" << endl; }//异常类型声明可以是类型，也可以是对象，实质上是异常对象的传递。
	//如果类型不是引用，则会创建一个局部副本
	try {
		for (i = 0; i < 5; i++)b[i] = istack.Pop();
	}
	catch (popOnEmpty<int>) { cerr << "栈空" << endl; }

	for (i = 0; i < 5; i++)
	{
		cout << b[i] << '\t';
	}
	cout << endl;

}

//把整个函数包在try块中。

void throwFunc_entir()try
{
	int a[5] = { 1,2,3,4,5 }, b[5] = {}, i;
	Stack<int>istack(4);


	try {
		for (i = 0; i < 5; i++)
			istack.Push(a[i]);
	}
	catch (...) { cout << "抛出的异常被catch_all字句捕获" << endl; throw; }

	istack.PrintStack();

	for (i = 0; i < 5; i++)b[i] = istack.Pop();


	for (i = 0; i < 5; i++)
	{
		cout << b[i] << '\t';
	}
	cout << endl;
}

catch (pushOnFull<int>& eObj) { eObj.print();  return; }//return 退出当前函数，注意加上return，下方的代码将不再执行，但可以用throw重新抛出异常
catch (popOnEmpty<int>& eObj) { eObj.print(); return; }


int main1()
{
	throwFunc_entir();
	cout << 3 << endl;
	return 0;
}
