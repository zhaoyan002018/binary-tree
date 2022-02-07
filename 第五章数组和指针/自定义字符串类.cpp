#include"common.h";
#include<string>
#include<cctype>

const int n = 21;

class mystring
{
public:
	mystring();
	mystring(const char* str);
	mystring(mystring&);
	~mystring();

	void show();
	bool operator<(mystring&);
	mystring& operator=(const char* ms);
	mystring& operator=(const mystring& ms);
	char operator[](int);

private:
	char str[n];
	int maxsize;
	int last;
};

mystring::mystring()
{
	last = 0;
	maxsize = n;
	str[0] = '\0';
}

mystring::mystring(const char* s)
{
	cout << "mystring构造" << endl;
	last = -1;
	maxsize = n;
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
int main5()
{
	mystring s1("hello world");
	s1.show();
	mystring s2 = "nihao";//进入的是构造函数，并非=重载
	s2.show();
	cout << "s1<s2=" << (s1 < s2) << endl;
	s2 = s1;//进入=运算符重载2
	s2.show();
	s2 = "C++ world";
	s2.show();
	mystring s3(s2);//进入的是复制构造函数。
	s3.show();
	cout << "s3[1]=" << s3[1] << endl;
	return 0;
}
