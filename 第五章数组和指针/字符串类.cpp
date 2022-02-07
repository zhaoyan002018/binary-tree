#include"common.h";
#include<string>
#include<cctype>


string remove_punct(string& str);

string make_lower(string& str);

bool is_pol(string& str);
//不区分大小写,过滤所有非字母字符。

int main4()
{
	//初始化：
	string str1;
	string str2("this is ");
	string str3 = "a string";
	string str4(str2 + str3);
	cout << "str1=" << str1 << ",str2=" << str2 << ",str3=" << str3 << ",str4=" << str4 << endl;

	//运算：
	cout << "(str2<str3)=" << (str2 < str3) << endl;//字典序，比较首个不相同字符的大小t>a，所以str2>str3


	cout << "str1 + str2=" << str1 + str2 << endl;

	str2 += str3;
	cout << "str2 += str3=" << str2 << endl;

	cout << "(str2==str4)=" << (str2 == str4) << endl;
	/*
	str4 = str2 - str3;
	cout << "str1 + str2=" << str4 << endl;并不存在-运算符
	*/
	//访问：
	cout << "str2[0] " << str2[0] << endl;
	cout << "str2.at(0) " << str2.at(0) << endl;
	//cout << "str2.at(20) " << str2.at(20) << endl;//会在运行时报错，at会检查一次访问是否越界。

	//输入：
	/*
	string str5;
	getline(cin, str5);
	cout << "输入的字符串str5为=" << str5 << endl;

	string str6;
	cin >> str6;
	cout << "输入的字符串为str6=" << str6 << endl;
	//如果输入hello world,getline是以\n作为结束符，但cin会以空格或者\n作为结束符
	*/
	//内置方法：
	cout << str4.substr(4, 5) << endl;
	cout << str4.append(",www") << endl;
	cout << str4.empty() << endl;
	cout << str4.insert(0, "hello,") << endl;
	cout << str4.length() << endl;
	cout << str4.find("www", 15) << endl;
	cout << str4.assign("clear") << endl;
	//cout << str4.back << endl;


	//c字符串到String的隐式转换：
	const char* c_str1 = "string";
	string str5(c_str1);
	//String到c字符串的显示转换：
	const char* c_str2 = str4.c_str();

	string str;
	getline(cin, str);

	if (is_pol(str))
	{
		cout << "是回文字符串" << endl;
	}
	else
	{
		cout << "不是回文字符串" << endl;
	}
	return 0;

}


string remove_punct(string& str)
{
	//过滤所有非字符
	string newStr;
	int len = str.length();
	int i = 0;
	int j = 0;
	while (i < len) {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			//newStr.append(1, str[i]);//注意+ +=运算符，并不能自动创建额外的空间。TODO 待研究，书上使用的是运算符而非函数 结果都可以。
			/*newStr = newStr + str[i];*/
			newStr += str[i];
		i++;
	}
	cout << "过滤后的字符串为：" << newStr << endl;
	return newStr;
}

string make_lower(string& str)
{
	string re_str = remove_punct(str);
	int len = re_str.length();
	int i = 0;
	int del = 'a' - 'A';
	while (i < len) {
		if (re_str[i] <= 'Z')
			re_str[i] += del;
		i++;
	}
	cout << "字符串全部转为小写后：" << re_str << endl;
	return re_str;
}

bool is_pol(string& str)
{
	//判断是否为回文字符串
	string low_str = make_lower(str);//将引用作为参数传给形参为引用的函数时，会寻址错误。应该是把一个基础类型的变量名赋给引用类型才可以，因为编译器内部做了指针的转化。但不能和形参为基础类型，传参就为基础类型的实参一样。
	//那么该如何解决，多重调用的情况下，还想使用形参为引用的情况呢？str为引用，&str获得的是被引用处的地址，所以要传&str给形参，而非str。但&str，并不能作为左值出现
	//感觉只能参考使用指针。

	//判断回文的方法：
	//1、从左右俩边分别进行遍历，比较是否相等。

	int len = low_str.length();
	if (len <= 3)
	{
		return false;
	}
	//回文字符串，应从3个字符的长度开始
	int mid = len / 2;
	bool out = true;
	int i = 0;
	while (i <= mid)
	{
		if (low_str[i] != low_str[len - 1 - i]) {
			out = false;
			break;
		}
		i++;
	}

	//如果字符串特别长呢？从节省空间的角度考虑：从效率的角度考虑：

	//2、当字符串特别长，无法立刻获得全部长度时，用什么数据结构存储再比较呢？

	//进阶，如果问题改成，求字符串中有多少种回文字符串呢？


	return out;

}
