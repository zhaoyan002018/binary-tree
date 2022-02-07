#include"common.h"

const int N = 100;

class mystring
{
public:
	mystring();
	mystring(const char* str);
	mystring(mystring&);
	~mystring();

	void show();
	bool operator<(mystring&);
	bool operator==(mystring&);
	mystring& operator=(const char* ms);
	mystring& operator=(const mystring& ms);
	char operator[](int);

private:
	char str[N];
	int maxsize;
	int last;
};

mystring::mystring()
{
	last = 0;
	maxsize = N;
	str[0] = '\0';
}

mystring::mystring(const char* s)
{
	cout << "mystring构造" << endl;
	last = -1;
	maxsize = N;
	do {
		last++;//怪不得初始化为-1.除了初始，last始终指向当前字符。
		str[last] = s[last];
	} while (s[last] != '\0' && last < maxsize - 1);
	str[last] = '\0';
}
mystring::mystring(mystring& ms)
{
	cout << "进入复制构造函数" << endl;

	last = -1;
	do {
		last++;
		str[last] = ms.str[last];
	} while (last != ms.last);

}

mystring::~mystring()
{
}
bool mystring::operator<(mystring& mystr)
{
	int i = 0;
	bool out = false;//俩个字符串相等的情况下，<为假
	while (i < maxsize)
	{
		if (str[i] == mystr.str[i])
		{
			i++;
			continue;
		}
		if (str[i] < mystr.str[i])
			out = true;
		break;

	}
	return out;
}
bool mystring::operator==(mystring& mystr)
{
	int i = 0;
	bool out = true;
	while (i < maxsize)
	{
		if (str[i] == mystr.str[i])
		{
			i++;
			continue;
		}
		out = false;
		break;

	}
	return out;
}
mystring& mystring::operator=(const char* ms)
{
	cout << "进入=运算符重载" << endl;
	last = -1;

	do {
		last++;
		str[last] = ms[last];
	} while (last < maxsize - 1 && ms[last] != '\0');

	str[last] = '\0';
	return *this;
}
mystring& mystring::operator=(const mystring& ms)
{
	cout << "进入=运算符重载2" << endl;

	last = -1;
	do {
		last++;
		str[last] = ms.str[last];
	} while (last != ms.last);
	return *this;
}
char mystring::operator[](int i)
{
	return str[i];
}

void mystring::show()
{
	cout << str << endl;
}
//求数组元素中最大值的函数模板
template<typename T>T getArrMax(T arr[], int n)
{
	if (n < 0)
		exit(-1);

	T max = arr[0];
	int i = 1;
	while (i < n) {
		if (max < arr[i])
			max = arr[i];
		i++;
	}
	return max;
}

//对半查找的函数模板,返回下标，没找到返回-1
template<typename T>int Binarysearch(T arr[], T ele, int n)
{
	int first = 0, last = n - 1, mid = -1;
	while (first < last) {
		mid = (first + last) / 2;
		if (arr[mid] == ele) {
			break;
		}
		if (arr[mid] < ele) {
			first = mid + 1;
		}
		else {
			last = mid - 1;
		}
	}

	if (first > last) {
		return -1;
	}

	return mid;

}
//归并排序函数模板，对俩个有序数列合并成一个有序数列。目前是升序处理，也是稳定的排序
template<typename T>void mergerSort(T arr1[], T arr2[], T arr3[], int n1, int n2)
{
	int i = 0, j = 0;//分别用俩个指针指向俩个有序数组。
	int k = 0;//指向合并后的数组
	while (1) {
		if (arr1[i] < arr2[j]) {
			arr3[k++] = arr1[i++];
		}
		else {
			arr3[k++] = arr2[j++];
		}//注意如果俩个序列元素相当，俩个元素谁先插入都不影响原本其序列元素的先后顺序，所以是稳定的。
		if (i == n1 || j == n2)//说明有一组序列已经遍历到最后了。
		{
			break;
		}
	}
	while (i != n1) {
		arr3[k++] = arr1[i++];
	}
	while (j != n2) {
		arr3[k++] = arr2[j++];
	}

}

int* text()
{
	return NULL;
}
//习题6.15
void func()
{
	//int* (*)()(*arr)[6];

	int* (*f)() = text;
}
int main()
{
	mystring strings[] = { "nihao","hello","kounijiwa" };
	mystring max;
	max = getArrMax(strings, 3);
	cout << "strings数组元素中最大值为:";
	max.show();
	/*…………………………………………*/
	orderList<int, 100> disorderList;
	orderList<int, 100> disorderList2;
	int data[10] = { 23,45,12,67,88,19,22,23,88,47 };
	int i = 0;
	while (i < 10) {
		disorderList.insert(data[i], i);
		i++;
	}
	disorderList.exchangeSort_bubble_desc();
	disorderList.traverse();
	/*…………………………………………*/
	mystring e("hello");
	i = Binarysearch(strings, e, 3);
	cout << "查找的结果为：" << i << endl;
	/*…………………………………………*/

	int orderList[10] = { 2,12,33,45,56,67,77,78,79,80 };
	int orderList2[10] = { 1,4,6,23,45,67,79,90,93,99 };
	int orderList3[20] = {};
	mergerSort(orderList, orderList2, orderList3, 10, 10);
	cout << "归并后序列：" << endl;
	for (i = 0; i < 20; i++) {
		cout << orderList3[i] << "\t";
	}
	cout << endl;

	/*…………………………………………*/
	int data2[6] = { 20,26,49,21,15,6 };
	i = 0;
	while (i < 6) {
		disorderList2.insert(data2[i], i);
		i++;
	}
	disorderList2.insertSort_shellSort();
	cout << "希尔排序后序列：" << endl;
	disorderList2.traverse();
}
