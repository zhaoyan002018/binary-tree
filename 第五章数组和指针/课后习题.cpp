#include"common.h"
#include<ctime>
//习题5.1.8
void func()
{
	int z3d[2][3][4] = {};
	int i = 1, j = 2, k = 3;
	cout << "z3d=" << '\t' << z3d << endl;
	cout << "z3d+1=" << '\t' << z3d + 1 << endl;
	//cout << hex << "del =:" << '\t' << sizeof((z3d + 1) - z3d) << "H" << endl;这种输出结果是错的，但不理解为什么这样输出。
	cout << "&z3d[1]=" << '\t' << &z3d[1] << endl;
	cout << "&z3d[0][0][1]=" << '\t' << &z3d[0][0][1] << endl;
	//答案是int的长度呢？还是int a[3][4]即int类型长度*3*4呢？结果为后者 48=30H，原因在于数组是一维的，将后面所有低维数组都看作成一个元素。
	cout << hex << "sizeof(int)" << sizeof(int) << "H" << endl;
	cout << hex << "sizeof(z3d[0])" << sizeof(z3d[0]) << "H" << endl;
	cout << "&z3d[0][0][0] + 1=" << &z3d[0][0][0] + 1 << endl;
	int* t = &z3d[0][0][0];//猜测应该只有指针+1的情况下才会有1是指向元素的步长的效果。直接地址+1就不会+的是元素的长度，因为没有额外信息可以告诉编译器，但指针本身有指向元素的类型。
	//但结果，不论是直接输出取元素地址+1，还是间接用指针+1都能实现步长+1。猜测原因在于&数组元素+1时，编译器从元素类型得到步长，将元素地址加上一个步长单位，下面可以用基础类型做测试。
	cout << "t + 1=" << t + 1 << endl;

	//如果直接取得基础类型+1，会和数组元素以及指针一样移动一个步长吗？猜测应该不会。
	int addr = 0;
	cout << "&addr=" << &addr << endl;
	cout << "&addr+1=" << &addr + 1 << endl;
	//但从结果来看，是移动了一个步长的。打脸了。说明&后的地址+任意一立即数，移动的都是所取变量地址的类型长度（即步长）*立即数。

	//如果就只是想移动长度1的地址呢？这样应该不被允许，与对齐原则相悖，可能造成寻址错误，推测无法实现。
	//同样的在指针中，要想对指针变量+1，肯定也没法对地址本身+1，而是+的是指向元素的长度，只有这样才不会造成之后寻址内容出错。



	//问题1：第i行第j列第k页元素的指针的3种表达方式
	//首先该元素的类型是int，那么其指针类型就是int *。
	int* p1 = &z3d[i][j][k];//可想而知，下标运算符在编译器中会被转换为指针进行操作，那么直接用指针怎么表示呢？猜测编译器的一种做法是先得到最低维度元素的长度，然后通过行列页的个数进行积运算再乘以元素长度得到[i][j][k]的位置。如果是[i][j]也是同理，只不过不用找到上一个[k]的维度，而是把他看作[j]的内容，当做一个整体。
	int* p2 = (&z3d[i][j][0] + k);
	int* p3 = (&z3d[0][0][0] + i * 3 * 4 + j * 4 + k);//表达式前面的&元素决定了后面+的立即数要乘以的步长是多大，由元素自身大小确定，这里z3d[0][0][0]是int类型，所以是一个int长度
	//上面有一个特点，因为要寻址到第k页，所以不论怎么样,z3d进行偏移，都要从[0][0][0]号元素开始，而不能升高一个维度到[0][0]，因为这样低纬度的内容就不可寻址了。
	//int* p3=(&z3d[0][0][0] + i * 3 * 4 + j * 4 + k)会产生算数溢出，其原因在于俩个int类型的乘积，结果可能会超过int类型的范围，导致丢失低精度，所以想要用更大的类型接受。
	//参考:void foo(){
	//float a = 0.1;
	//float b = 0.2;
	//sin(a * b)
	//}
	//函数认为两个float做运算精度可能超过4个自己，可能要8个字节存储，那么现在你继续使用float类型存储，那么计算出来的结果精度就丢了4位，这样即使再转为double类型的也没有价值，所以报了警告

	//因此修改p3表达式
	p3 = (&z3d[0][0][0] + long long(i) * (3) * 4 + long long(j) * 4 + k);


	cout << "p=" << p1 << endl;
	cout << "p2=" << p2 << endl;
	cout << "p3=" << p3 << endl;

	int* anser1 = z3d[i][j] + k;	//这里z3d[i][j]并没有当做元素，而是地址(数组第一个元素的地址)，是因为+k吗？由于没有使用&，所以+立即数，其步长也并非是其自身类型（int [][4]）长度。
	int* anser2 = *(z3d[i] + j) + k;
	int* anser3 = *(*(z3d + i) + j) + k;
	cout << "anser1=" << anser1 << endl;
	cout << "anser2=" << anser2 << endl;
	cout << "anser3=" << anser3 << endl;
	//发觉 &z3d[i][j][k] 等效于 z3d[i][j]+k ,能理解的是 &z3d[i][j][0]+k，能完成偏移，而z3d[i][j]也同样能作为数组名的作用，指向其首个元素，但指向的是值呢？还是地址呢？
	//如果输出z3d[i][j]，输出的是什么？首先退一步如果输出的是z3d[i][j][k]，知道是一个int类元素，而z3d[][]的元素是int[4]数组，那么z3d[i][j]的值是什么呢?
	//z3d[i][j]是一个int[4]数组，他是等于[4]数组的首个元素的值呢？还是这个数组首个元素的地址呢？这里很明显是把他当做了地址来使用，所以才可以+立即数进行偏移。


	int tmp[4][3];
	int(*x)[3] = tmp + 1;
	int* x2 = *(tmp + 1) + 1;

	//问题2：第i行第j列第k页元素的3种表达方式
	//元素的类型是int，也就是给出三种寻址方式。
	z3d[i][j][k] = 2;
	int i1 = z3d[i][j][k];
	int i2 = *(&z3d[i][j][0] + k);
	int i3 = *(&z3d[i][0][0] + (long long)j * 4 + k);//强制类型转换C风格形式
	cout << "i1=" << i1 << endl;
	cout << "i2=" << i2 << endl;
	cout << "i3=" << i3 << endl;

	int i4 = *(z3d[i][j] + k);
	int i5 = *(*(z3d[i] + j) + k);
	int i6 = *(*(*(z3d + i) + j) + k);
	cout << "i4=" << i4 << endl;
	cout << "i5=" << i5 << endl;
	cout << "i6=" << i6 << endl;

}
//杨辉三角参考资料：
//第n行的数字有n项。
//每个数字等于上一行的左右两个数字之和。
void func5_3()
{
	cout << "enter func5_3" << endl;
	//打印10行杨辉三角形
	//二维数组，一维存行数，另一维存列
	//所以高维的大小为10，低位的大小也为10
	//int yh_arr[10][10] = { 1 };
	int yh_arr[10][11] = { 0,1 };//为了计算统一，增加最左边一列全为0的列。（并不需要额外处理，只要初始化默认都是0即可）
	//只需对第一行进行明确初始即可，其他元素都是0.
	int i = 1;

	while (i < 10)
	{
		int n = i + 1;//该行要打印的个数
		int j = 0;//该行第j个数
		j = 1;//优化算法后，实际从第2列存放真实数据
		while (n) {
			//下面需要考虑俩种情况，那么怎么样优化算法可以使其无特例呢？
			//下面的特例是，如果是每行首个元素，他等于上一行的首元素，而不是俩个左右元素的和。
			//解决方案：都是左右的和，但首元素没有，就增加一列全为0的列。
		/*	if (j == 0)
				yh_arr[i][j] = yh_arr[i - 1][j];
			else*/
			yh_arr[i][j] = yh_arr[i - 1][j - 1] + yh_arr[i - 1][j];
			j++;
			n--;
		}
		i++;
	}

	i = 0;
	while (i < 10)
	{
		int k = 10 - i;
		while (k)
		{
			cout << " ";
			k--;
		}

		int n = i + 1;
		int j = 0;
		j = 1;//优化算法后，实际从第2列存放真实数据
		while (n)
		{
			cout << yh_arr[i][j] << " ";
			j++;
			n--;
		}
		cout << endl;
		i++;
	}

}

int my_atoi(char s[])
{
	int out = 0;
	int i = 0;
	bool symbol = true;
	if (s[i] == '-')
	{
		i++;
		symbol = false;
	}
	while (s[i] != '\0')
	{
		int place = s[i] - '0';
		out *= 10;
		out += place;
		i++;
	}

	if (!symbol)
		out *= -1;
	return out;
}
void func5_5()
{
	cout << "请输入数字：" << endl;
	char s[10] = {};
	cin >> s;
	cout << my_atoi(s) << endl;

}

void func5_7()
{
	int i = 1;
	double d = 1.1;
	char c = 'a';

	int* i_p = &i;
	double* d_p = &d;
	char* c_p = &c;

	//指针指向的目标的值，和地址。
	cout << i << ',' << hex << &i << endl;
	cout << d << ',' << hex << &d << endl;
	cout << c << ',' << hex << (void*)(&c) << endl;
	cout << endl;

	//各指针的值，与指针本身的地址、各指针占用的字节长度：
	cout << *i_p << ',' << hex << i_p << ',' << sizeof(i_p) << endl;
	cout << *d_p << ',' << hex << d_p << ',' << sizeof(d_p) << endl;
	cout << *c_p << ',' << hex << (void*)c_p << ',' << sizeof(c_p) << endl;

}


char* my_itoa_rc(int n, char* string)//返回值和参数string效果相同，是用来保存转化后字符数组地址的。
{	/*
	int rm = n % 10;//得到最右边的，但排列字符串，应从最左边开始。
	n = n / 10;


	if (n == 0)//此时到达最左边。
	{
		string[0] = rm + '0';
		return string;
	}
	else
	{
		my_itoa_rc(n, string);
		int i = 1;
		while (string[i++]);
		string[i - 1] = rm + '0';
	}
	return string;
	*/
	//优化算法，考虑到达最后一位时和之前的情况能不能统一？但仍需要存在一个回归点。

	if (n) {//满足处理条件，则提取一个数字给字符串。
		my_itoa_rc(n / 10, string);//注意，这里保证了n本身在当前函数作用域内没有发生过变化，减少变化性。
		int rm = n % 10;
		int i = 0;
		while (string[i++]);
		string[i - 1] = rm + '0';
	}
	//这里特殊的点在于，如果到达了回归点，并不需要做任何操作。完成对上面的算法的优化。将原本需要特殊处理的回归点放到正常处理的流程中，而更改了回归的位置。其实是多进行了一次函数调用的，为了方便算法统一。
	return string;//不论是否满足条件，都一定要返回。
}


//非递归
const char* my_itoa(int n, char* str)
{
	string s(str);

	while (n)
	{
		int rm = n % 10;
		n = n / 10;

		s += rm + '0';
	}

	reverse(s.begin(), s.end());

	const char* s2 = s.c_str();
	int i = -1;
	do {
		i++;
		*(str + i) = *(s2 + i);
	} while (*(s2 + i));

	return NULL;
	//return s.c_str();//注意此时转化的c语言风格的字符串的生命周期是多少呢？是和s声明周期一样呢？还是别的？猜测应该是动态申请的额外空间

}


void func5_9()
{
	char s[20] = {};
	int a;
	cout << "请输入一个整数:" << endl;
	cin >> a;
	my_itoa_rc(a, s);
	//cout << "s=" << s << endl;
	//my_itoa(a, s);
	//cout << "s=" << my_itoa(a, s) << endl; 输出异常
	cout << "s=" << s << endl;
}


class DateTime {

public:
	DateTime();
private:
	struct tm tb;
	time_t current;
	char s[30];

};

DateTime::DateTime()
{
	time(&current);
	localtime_s(&tb, &current);
	asctime_s(s, &tb);//如果第一个参数没用&会是怎么情况？参数就是char s[30]，好像实参不变还是s，但如果是char (&s)[30],在函数内部的操作会变得更容易？
	//考虑 char (*s)[30]是什么情况？数组指针，s指向数组，但实参s数组名本身就是地址，如果在函数中形参是数组而非数组指针，使用时就是s[i],若是后者，*s才能定位到数组元素起始，(*s)[i]才可以寻址，
	//虽然把数组指针改为数组引用，因而s[i]可以直接寻址，但这和直接把数组当做类型有什么区别呢？或许是无法直接操作数组的地址？继而更安全？因为数组名作为参数，本质上还是指针， 把指针替换为引用或许更符合c++的设计理念。
	cout << s << endl;
}


void func5_10()
{
	DateTime dt;
}

int main()
{
	func5_10();
}
