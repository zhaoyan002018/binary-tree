#pragma once
#include<iostream>
#include<string>

using namespace std;
//c++在写模版函数时（template<class T>之类的），头文件不能与cpp文件分离。
//这就意味者，你头文件定义的含模版的地方必须在头文件中实现，没用模版定义的地方可以放在cpp中实现
template<typename T, int n>class orderList
{
	T list[n];//保存元素的容器
	int last;//指向末尾元素
	int maxsize;//最大容量
public:
	orderList() { last = -1; maxsize = n; }
	bool isFull();
	bool insert(T ele, int i);
	int Binarysearch(T& ele, int first, int last);//递归法
	int Binarysearch(T& ele)const;//迭代法
	void traverse();
	//能对未知类型T的实例进行运算符重载吗？难道不会自动匹配到实例的比较中去？
	void print();


	void insertSort_direct();
	void insertSort_half();
	void insertSort_shellSort();

	void exchangeSort_bubble();
	void exchangeSort_bubble_desc();
	void selectSort_direct();
};

template<typename I>class element {
	I key;
	//忽略其他属性
public:
	element() { key = 0; }
	element(I value) { key = value; }
	void putKey(I value) { key = value; }
	void show() { cout << key << '\t'; }
	//bool operator<(I ele);
	//bool operator==(I ele);
	//重载错误的点在于，参数应该是类本身的type，而不是key的type，比较的是类，然后重载为key的比较。
	bool operator<(element ele);
	bool operator==(element ele);
};

class element2 {
	int key;
	//忽略其他属性
public:
	element2() { key = 0; }
	element2(int value) { key = value; }
	void putKey(int value) { key = value; }
	void show() { cout << key << '\t'; }
	bool operator<(element2 ele) const { return key < ele.key; }
	bool operator==(element2 ele) const { return key == ele.key; }
	//在li6.3是使用<<输出的类型是int，但是现在输出的是element2类，因此要重载<<才可以使用。但如何重载<<呢？
	//cout 是 ostream 类的对象,ostream 类将<<重载为成员函数，而且重载了多次。
	//因此需要重载的并非是element2类中的<<，而是ostream类中的<<才可以。
	//实际上也就是说左操作数为os对象，右操作数为element2对象，但是os类无法修改，只好通过全局重载运算符的方式进行，同时又需要访问element2类型的私有成员，因此声明为element2类型的友元函数。
	//但需注意，友元函数并非element类本身的成员函数，而是全局的，但它拥有访问该类私有成员的权限。
	//int operator<<(element2 ele) { return ele.key; }
	friend ostream& operator<<(ostream&, element2&);
};

template<typename I> bool element<I>::operator<(element ele)
{
	return key < ele.key;
}
template<typename I> bool element<I>::operator==(element ele)
{
	return key == ele.key;
}

//报错:左边必须有类/结构/联合 是因为如果list类型不是类因此不包含show，却使用想类成员造成的
template<typename T, int n>void orderList<T, n>::print() {
	int i = 0;
	while (i < last) {
		list[i].show();
		if (i % 5 == 4)cout << endl;
		i++;
	}
	cout << endl;
}

template<typename T, int n>bool orderList<T, n>::isFull() {
	if (last == maxsize - 1)
		return true;
	return false;
}

template<typename T, int n>bool orderList<T, n>::insert(T ele, int i)
{
	if (isFull()) {
		cout << "顺序表已满无法插入" << endl;
		return false;
	}

	if (i > last + 1 || i > maxsize - 1 || i < 0) {
		cout << "插入位置非法" << endl;
		return false;
	}

	//先将i之后的位置向后偏移
	int lastTmp = this->last + 1;
	while (i < lastTmp) {
		list[lastTmp] = list[lastTmp - 1];
		lastTmp--;
	}

	list[i] = ele;
	this->last++;
	return true;

}

template<typename T, int n>int orderList<T, n>::Binarysearch(T& ele, int first, int last)//比较的是key 的大小。
{//查找，是根据关键字返回其在顺序表中的位置
	if (first > last) {
		return -1;
	}

	int mid = (first + last) / 2;

	if (list[mid] == ele) { //注意T类型的ele，触发==运算符时，是在Binarysearch函数实例化之后进行的。
		return mid;
	}
	if (list[mid] < ele) {
		//说明要找的元素在first 和 mid中间
		first = mid + 1;
	}
	else {
		last = mid - 1;
	}

	Binarysearch(ele, first, last);


}

template<typename T, int n>int orderList<T, n>::Binarysearch(T& ele)const {
	int first = 0, mid = -1, lastTmp = this->last;

	while (first <= lastTmp) {//注意相等的状况也是允许的。
		mid = (first + lastTmp) / 2;

		if (ele == list[mid])
		{
			break;
		}
		if (list[mid] < ele)
			first = mid + 1;
		else
			lastTmp = mid - 1;
	}
	if (first > lastTmp) {
		return -1;
	}

	return mid;
}




template<typename T, int n>void orderList<T, n>::traverse() {

	int j = 0;
	while (j <= last) {
		cout << "第" << j + 1 << "个元素是：" << list[j] << endl;//对于模板类，保存模板参数类型T的数组size，需要重载[]，表明如何访问数组。
		j++;
	}
}

/*………………………………………………………………………………………………………………………………*/


/*
	排序常用的三类：插入排序、选择排序、交换排序
*/
template<typename T, int n>void orderList<T, n>::insertSort_direct()
{
	//1 3 5 6 ,4
	//直接插入排序，将要插入升序数列的元素，从后向前遍历，找到第一个小于它的元素，插入到他后面，其余元素后移，后移过程中就需要一个tmp进行暂存。
	T tmp;
	int i = 1;
	for (; i <= last; i++) {//首个元素不需要考虑是否有序
		tmp = list[i];//存放要比较的元素
		int j = i - 1;//从最后向前遍历比较
		while (1) {
			if (j < 0 || list[j] <= tmp)//注意如果T类型是自定义类型，需要对<运算符进行重载。
			{//另外，排序是稳定的原因，就在于key==时，原来在前的，依旧在前。因此插入的位置是关键，由于我们插入的是找到的位置j后面，而不是前面，所以==时需要进行插入操作。
				//j位置后其余元素后移。
				int first = j + 1;
				int end = i;
				while (first != end) {
					list[end] = list[end - 1];
					end--;
				}
				list[first] = tmp;
				break;//找到后跳出循环
			}
			j--;
		}
		//如果没找到，说明该元素是最小的，放到开头。
	}
}
//可以看到需要俩次遍历，最差情况下每次内部循环都要遍历满

template<typename T, int n>void orderList<T, n>::insertSort_half()
{
	//折半插入排序
	int i = 1;
	for (; i <= last; i++) {
		int tmp = list[i];
		int j = i - 1;
		//下面查找符合第一个小于tmp的元素，使用折半查找法
		int first = 0;
		int end = j;
		int mid;
		while (first <= end) {
			//2 3 4 6,1
			mid = (first + end) / 2;
			if (list[mid] <= tmp) {//但是目前虽然满足小于等于，但不一定是第一个小于等于。满足是第一个小于等于的条件是，下一个元素是大于或为要比较的元素自身（即要比较的元素已经到头）。
				if (list[mid + 1] > tmp) {
					break;
				}
				first = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		//不满足first <= end的情况有俩种，一种tmp最大 最后first>end,mid=end，位置不动；一种tmp最小，最后end<0，mid=0,放在队首
		if (end < 0) {
			mid = mid - 1;
		}
		//找到了，则对mid后面的元素进行偏移。
		first = mid + 1;
		end = i;
		while (first != end) {
			list[end] = list[end - 1];
			end--;
		}
		list[first] = tmp;

	}
}

//参数有，要排序的元素、数组个数。 其中个数确定，但元素不确定
template<typename T> void shellSort_group(T* group[], int n) {
	//对组内n个元素进行排序，注意保存的是元素的地址。
	T tmp;
	int i = 1;
	for (; i <= n; i++) {//首个元素不需要考虑是否有序
		tmp = *group[i];//存放要比较的元素
		int j = i - 1;//从最后向前遍历比较
		while (1) {
			if (j < 0 || *group[j] <= tmp)
			{
				int first = j + 1;
				int end = i;
				while (first != end) {
					*group[end] = *group[end - 1];
					end--;
				}
				*group[first] = tmp;
				break;//找到后跳出循环
			}
			j--;
		}
		//如果没找到，说明该元素是最小的，放到开头。
	}
}

template<typename T, int n>void orderList<T, n>::insertSort_shellSort() {
	//希尔排序，也称缩小增量排序法，通过不断选择增量，并缩小增量进行排序。
	int gap = (last + 1) / 2;//设置增量
	int first = 0;

	int gapNum = 2;//组内元素个数。
	while (gap != 0) {
		int i = 0;//i和gap一组，i+1和gap+1一组
		while (i < gap) {//不断做到局部有序，并慢慢将局部缩小，直至整体有序
			//对组内元素进行排序,
			T* group[10] = {}; //之后改为动态数组。

			int j = 0;
			while (j < gapNum) {
				group[j] = &list[gap * j + i];
				j++;
			}
			shellSort_group(group, gapNum - 1);
			//组内进行排序，然后插入

			i++;
		}
		gap = gap / 2;
		gapNum++;
	}
}

template<typename T, int n>void orderList<T, n>::exchangeSort_bubble()
{
	//冒泡排序(交换排序的一种)可以利用已有序列，至多遍历n-1次，如果某次遍历没有发生交换，说明已经形成有序数列。
	T tmp;
	int end = last;//n作为截止的最高位置，有序的过程是从最高位向最低位进行的。
	for (; end > 1; end--) {
		int i = 0;
		bool exTag = false;
		while (i < end) {
			//从首位遍历到n位依次两两比较。
			if (list[i] > list[i + 1]) {//如果相等，则不需要进行交换，这样就是稳定的排序。
				exTag = true;
				tmp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = tmp;
			}
			i++;
		}
		if (exTag == false) {
			break;//说明序列已经有序，不需要继续比较。
		}
	}
}

template<typename T, int n>void orderList<T, n>::exchangeSort_bubble_desc()
{
	//冒泡排序降序排序
	T tmp;
	int end = last;//n作为截止的最高位置，有序的过程是从最高位向最低位进行的。
	for (; end > 1; end--) {
		int i = 0;
		bool exTag = false;
		while (i < end) {
			//从首位遍历到n位依次两两比较。
			if (list[i] < list[i + 1]) {//如果相等，则不需要进行交换，这样就是稳定的排序。
				exTag = true;
				tmp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = tmp;
			}
			i++;
		}
		if (exTag == false) {
			break;//说明序列已经有序，不需要继续比较。
		}
	}
}
template<typename T, int n>void orderList<T, n>::selectSort_direct()
{
	//直接选择排序。必须遍历n-1次，每次选择出最大或者最小的一个，这样最没有效率，没有办法利用原有的有序程度。
	int maxI;//存放每次找到的最大数的下标。
	int end = last;
	for (; end > 0; end--)
	{
		int i = 0;
		maxI = i;
		T max = list[i++];
		while (i <= end) {//注意相等情况，也需要比较
			if (list[i] > max) {
				max = list[i];
				maxI = i;
			}
			i++;
		}
		list[maxI] = list[end];
		list[end] = max;
	}
}
