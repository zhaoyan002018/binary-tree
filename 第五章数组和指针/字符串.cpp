#include"common.h"

void strcpy1(char src[], char dst[])
{
	while (*dst++ = *src++);
	//当前位置赋值完后，(错误：向后偏移1位)，在进行判断当前表达式的值,向后偏移1位(应放在最后执行)。
}

int main3()
{
	char chr[] = "this is a string";
	int len = strlen(chr);
	int size = sizeof(chr);
	cout << "len =" << len << ",size=" << size << endl;
	//char* chr2 = "this is a string";并不能像C一样声明成功。
	const char* chr2 = "this is a string";
	int len2 = strlen(chr2);
	int size2 = sizeof(chr2);
	cout << "len2 =" << len2 << ",size2=" << size2 << endl;//指针常量，无法进行*间接解引用。

	//chr,和chr2指向的字符串有什么区别呢？
	//chr可以修改，chr2不可修改被引用的字符串,本质上chr是数组，而chr2是指针常量，即这个字符串是常量字符串。
	chr[0] = 'T';
	cout << "chr=" << chr << endl;
	//当数组形式为int chr[]，但输出chr,输出的逻辑上要输出的是地址，因为数组名是指针常量，数组名就是指针的地址，但C中输出字符串时，已经知道输出指针名即可，所以，其实是编译器对指针名的不同处理，如果该指针是char型时，编译器便会认为要输出的是指向的字符串，因而不仅使用了首地址，还使用了长度，找到\0作为结束。
	//所以现在明白为什么要输出&char，继而输出char型数据的地址时，需要进行(void *)强制转换了，因为遇到char型数据的地址，编译器会以为要输出字符串。
	//那么就想输出字符串地址怎么办？只要转化为其他任何类型指针，理论上都可以，但其实输出指针地址用不上类型，所以一般使用泛型即void类型指针。

	char tmp[] = "this is a temp";
	cout << "(void*)tmp" << (void*)tmp << endl;
	cout << "(int*)tmp" << (int*)tmp << endl;



	char chr3[30];

	strcpy1(chr, chr3);

	cout << "chr3=" << chr3;
	return 0;
}
