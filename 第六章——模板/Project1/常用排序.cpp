#include"common.h"
/*
	排序常用的三类：插入排序、选择排序、交换排序
*/



//template<typename T, int n>  extern void orderList<T, n>::print();


//如果类的声明在.h文件中，定义在.cpp中，那么其他文件想要使用该类成员，该怎么引用呢？
//类声明放在头文件，但定义放在多个.cpp中会有什么后果？编译连接过程是怎么样的？为什么extern不能起作用？
int main5()
{
	const int N = 10;
	orderList<int, 100> disorderList;
	int data[N] = { 23,45,12,67,88,19,22,23,88,47 };
	int i = 0;
	while (i < N) {
		disorderList.insert(data[i], i);
		i++;
	}
	//disorderList.print();注意不能用print，因为它的实现是通过.show来输出的，基础类型没有show成员函数。
	disorderList.traverse();
	cout << "经过sort后，print：" << endl;
	//disorderList.insertSort_direct();
	//disorderList.insertSort_half();
	//disorderList.exchangeSort_bubble();
	disorderList.selectSort_direct();
	disorderList.traverse();
	return 0;
}
