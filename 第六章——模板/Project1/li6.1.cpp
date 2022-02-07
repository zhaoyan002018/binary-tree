#include"common.h"

//函数模板
template <typename TYPE> TYPE getMax(TYPE arr[], int n)
{
	if (n < 1) {
		//return false;//异常情况如何处理？
		exit(0);
	}

	TYPE maxEle = arr[0];
	int i = 1;
	for (; i < n; i++)
	{
		if (maxEle < arr[i])
			maxEle = arr[i];
	}
	return maxEle;
}



int main1()
{
	int a[5] = { 12, 22, 44, 14, 64 };
	float b[5] = { 0.23,1.45,6.6,7.7,7.6 };
	char c[5] = { 'a','A','B','C','D' };
	string d[5] = { "北京","深圳","广州","上海","杭州" };//C风格的字符串char* 由于不是类，没有重载比较符，所以无法使用模板

	cout << "int作为类型，数组最大值为：" << getMax(a, 5) << endl;
	cout << "float作为类型，数组最大值为：" << getMax(b, 5) << endl;
	cout << "char作为类型，数组最大值为：" << getMax(c, 5) << endl;
	cout << "string作为类型，数组最大值为：" << getMax(d, 5) << endl;
	return 0;
}
