#include<iostream>
using namespace std;

#define PI 3.11
#define A(x,y) (x+y)*(x-y)
#define B(x,y) x*y/2


//文件包含指令
//为了避免头文件重复包含，可以用条件编译指令
//1、根据宏名是否定义来判断是否编译 

#ifdef PI
#include<math.h>
#else
#include<activaut.h>
#endif


#define DEBUG
#ifdef DEBUG
//cout << "this is test" << endl;  
//TODO这里为什么cout会出错呢？待研究完std命名域后再来。
#endif




//2、根据表达式的值来确定是否编译
#if 2
//cout << "fist";
#else
//cout << "second";
#endif // 0


int main9()
{
	//const int
	cout << PI << endl;
	cout << A(5, 3) << endl;
	cout << B(5 + 2, 3) << endl;
	return 0;
}
