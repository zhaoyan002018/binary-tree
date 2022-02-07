#include"common.h"
//类模板和线性表

template<typename T, int n>class Seqlist {
	T size[n];//元素容器
	int i;//指向最后一个元素下标，初始为-1
	int maxsize;//最大容量
public:
	Seqlist();
	bool isFull();//判断当前容器是否已满。
	int getLen();//计算表长度
	int getLastI();//已存表项最后位置
	void initList();//初始化为空表
	bool isExist(T ele);//判断x是否在表中

	T find(int i);//找到下标为i元素的值
	bool insert(T ele, int i);//将元素ele插入下标为i位置
	bool delete_e(T ele);//删除元素值为ele的元素
	bool delete_i(int i);//删除下标为i的元素
	bool push(T ele);//从队尾压入元素
	bool pop();//从队尾删除元素

	void traverse();

	T& findPre(T ele);//寻找前驱
	T& findNext(T ele);//寻找后继
	T& operator[] (int i);
	//返回值为引用类型，减少了副本作为中间值传递给外界，是直接将被引用位置的变量赋值给外部变量，但并非共用一块内存。前提被引用位置的变量的值不会随着函数声明周期结束而结束。
};

template<typename T, int n>T& Seqlist<T, n>::operator[](int i) {
	//[]只能访问数组内元素？还是能至多扩展到最大容量？

	return size[i];
}

template<typename T, int n>Seqlist<T, n>::Seqlist()
{
	initList();
}

template<typename T, int n>void Seqlist<T, n>::initList()
{
	i = -1;
	maxsize = n;
	int j = 0;
	while (j < n) {
		size[j] = 0;
		j++;
	}
}

template<typename T, int n>bool Seqlist<T, n>::isFull() {
	if (i + 1 >= maxsize)
		return true;
	return false;
}

template<typename T, int n>int Seqlist<T, n>::getLen()
{
	return i + 1;
}

template<typename T, int n>int Seqlist<T, n>::getLastI()
{
	return i;
}

template<typename T, int n>bool Seqlist<T, n>::isExist(T ele)
{
	bool result = false;
	int j = 0;
	while (j <= i) {
		if (ele == size[j]) {
			result = true;
			break;
		}
		j++;
	}
	return result;
}

template<typename T, int n>T Seqlist<T, n>::find(int i)
{
	if (i > getLastI())//为什么不是.?
		exit(-1);
	return size[i];

}

template<typename T, int n>bool Seqlist<T, n>::insert(T ele, int i)
{
	if (isFull())
		return false;

	int last = getLastI() + 1;

	if (i > last)//能够插入在队尾
		return false;

	while (last > i) {
		size[last] = size[last - 1];
		last--;
	}

	size[i] = ele;

	this->i++;
	return true;
}

template<typename T, int n>bool Seqlist<T, n>::delete_e(T ele)//删除不定数量元素
{
	int delArr[n] = { 0 };//以后可以申请一个动态变化的栈，保存要删除元素的下标
	int k = 0;//k指向数组末尾。

	int i = getLastI();
	int j = 0;
	while (j <= i) {
		if (ele == size[j]) {
			delArr[k++] = j;
			//++的优先级在 赋值运算符= 之后
		}
		j++;
	}

	if (k == 0)
		return false;

	while (k) {
		k--;
		int last = getLastI();
		int first = delArr[k];
		while (first == last) {
			size[first] = size[first + 1];
			first++;
		}
		size[last] = 0;
		this->i--;
	}
	return true;
}

template<typename T, int n>bool Seqlist<T, n>::delete_i(int i)
{
	int last = getLastI();

	if (i > last || last == -1)
		return false;

	int first = i;
	while (first <= last) {
		size[first] = size[first + 1];
		first++;
	}
	size[last] = 0;
	this->i--;
	return true;
}

template<typename T, int n>bool Seqlist<T, n>::push(T ele)
{
	int last = this->i + 1;
	return insert(ele, last);
}

template<typename T, int n>bool Seqlist<T, n>::pop()
{
	int last = this->i;
	return delete_i(last);
}

template<typename T, int n>T& Seqlist<T, n>::findPre(T ele)//难道默认元素不能重复吗？
{
	int first = 1;//因为首元素没有前驱
	int last = this->i;
	while (first <= last) {
		if (ele == size[first]) {
			return size[first - 1];//可以发现数组作为顺序表的底层容器，可以很快的进行查找。
		}
		first++;
	}
	cout << "发生异常" << endl;
	exit(-1);
}

template<typename T, int n>T& Seqlist<T, n>::findNext(T ele)
{
	int first = 0;
	int last = this->i - 1;//因为尾元素没有后继
	while (first <= last) {
		if (ele == size[first]) {
			return size[first + 1];//可以发现数组作为顺序表的底层容器，可以很快的进行查找。
		}
		first++;
	}
	cout << "发生异常" << endl;
	exit(-1);
}


template<typename T, int n>void Seqlist<T, n>::traverse() {
	int last = getLastI();
	int j = 0;
	while (j <= last) {
		cout << "第" << j + 1 << "个元素是：" << size[j] << endl;//对于模板类，保存模板参数类型T的数组size，需要重载[]，表明如何访问数组。
		//cout<<"第"<<
		//cout << find(j);
		j++;
	}
}


int main3()
{
	class Seqlist<int, 10> slist;
	slist.push(1);
	slist.push(3);
	slist.push(2);
	slist.insert(4, 1);
	slist.traverse();
	/*slist.pop();
	slist.pop();
	slist.traverse();
	slist.pop();
	slist.pop();*/

	//slist.delete_e(2);
	slist.delete_i(2);
	slist.traverse();
	if (slist.isExist(2)) {
		cout << "slist中存在2" << endl;
	}
	else {
		cout << "slist中不存在2" << endl;
	}
	if (slist.isExist(4)) {
		cout << "slist中存在4" << endl;
	}
	else {
		cout << "slist中不存在4" << endl;
	}

	slist.push(5);
	slist.push(6);
	slist.push(7);


	cout << "5的前驱是" << slist.findPre(5) << endl;

	cout << "6的后继是" << slist.findNext(6) << endl;
	return 0;
}
