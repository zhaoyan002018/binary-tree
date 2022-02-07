#include<iostream>
#include<cmath>
using namespace std;

//TODO思考在申请对象时，数据的分配是怎么样的？目前来至少private修饰的数据要先于public，而跟代码顺序无关。

class Test {
private:
	int v1;
public:
	void Printf()
	{
		cout << "v1=" << v1;

	}
	//test类中不能出现Complex2，因为声明顺序的问题。那怎么访问Complex2对象呢？
	//void Printf_Com(Complex2& c)
	//{
	//	cout << "c.real=" << c.Real << endl;//如果Test类并非Complex2的友元类，则不能访问c.Real;

	//}
	void Printf_Com();
	Test(int v = 0) {
		v1 = v;
	}
};
//TODO 类complex与Complex区分大小写吗？
class Complex2
{
private:
	double Real, Image;
	friend Test;//test应该同样和其他友元函数一样，并不占用Complex2对象的空间，而是Test类中的每个成员函数都可以访问Complex2类中的任一成员。
public:
	//疑问？这里只是构造参数为2的情况，那么参数为1，或0时有没有进行构造呢？ 答案是都进入到了该构造函数中
	Complex2(double r = 0.0, double i = 0.0) {
		cout << "构造Complex2" << endl;
		Real = r;
		Image = i;
	}
	Complex2(Complex2& com)//如果复制构造函数和=重载的成员函数参数都是自身类型的引用，那么在使用=时如何区分开来呢？猜测是看是否已经经过过初始化。TODO测试
	{
		cout << "copy Complex2" << endl;
		Real = com.Real;
		Image = com.Image;
	}
	~Complex2()
	{
		cout << "析构Complex2" << endl;
	}

	void Printf() {
		cout << "Real=" << Real << '\t' << "Image=" << Image << "\n";
	}
	//friend Complex2 operator+(double, const Complex2&);
	friend Complex2 operator+(const Complex2&, const Complex2&);
	//friend Complex2 operator=(const Complex2&, const Complex2&);//=必须是成员函数
	friend Complex2& operator+=(Complex2&, const Complex2&);
	friend Complex2 operator*(const Complex2&, const Complex2&);
	friend Complex2 operator/(const Complex2&, const Complex2&);
	friend double abs(Complex2&);
	Complex2 operator=(const Complex2&);
	friend Complex2 operator++(Complex2&, int);//后置++
	friend Complex2 operator++(Complex2&);//前置++
	/*Complex2 operator+(const Complex2&);
	Complex2 operator+(double);
	Complex2 operator=(const Complex2&);
	Complex2 operator+=(const Complex2&);
	Complex2 operator*(const Complex2&);
	Complex2 operator/(const Complex2&);*/
	//double abs(void);
	//Complex2 operator++(int);//后置++
	//Complex2 operator++();//前置++
};
Complex2 Complex2::operator=(const Complex2& c)//实参类型为Complex2 形参类型为const Complex2 &会发生什么？ 因为const &有临时对象，引用和类型都换了，测试如下@
{
	cout << "进入重载=运算符的成员函数" << endl;

	Complex2 temp;
	temp.Real = c.Real;
	temp.Image = c.Image;

	Real = temp.Real;
	Image = temp.Image;

	return temp;
	//返回的是表达式本身的值，这样a=b=c时，b=c作为一个表达式整体的值，赋给a，能够连等使用。如果不返回一个表达式的值，单单给=表达式的左值赋值，则不能够连等。
	//那么其实可以返回左值的引用，因为表达式的值，也就是左值的大小。

	//这里左值和参数值相等，可以先返回参数值，等之后考虑如何返回自身。
	//Real = c.Real;
	//Image = c.Image;
	//return c;
	//思考当返回值类型和实际返回值类型不一致会发生什么？比如参数是引用，而返回值是正常类型？
}
/*
Complex2 Complex2::operator+(const Complex2& c)
{
	//static Complex2 temp(Real + c.Real, Image + c.Image);//这样每次运算都会产生一块无法立即释放的内存空间。如果返回局部变量的引用会不会出错呢？不可，返回后就指向垃圾内存了。
	//return temp;
	//那返回值存放在c中如何？由于c是const &,实际上也是有临时空间的，和局部变量无异，所以还是不可。要不在主函数中控制=的左值一定要是初始化过后的值？
	//局部变量temp尽管声明周期只在该函数域内，但是返回的局部变量会通过复制构造函数给一个临时变量，并将该临时变量传递给外部。

	//Complex2 temp(Real + c.Real, Image + c.Image);
	//return temp;
	cout << "进入重载+运算符的成员函数" << endl;
	Complex2 temp(Real + c.Real, Image + c.Image);
	return temp;
	//return Complex2(Real + c.Real, Image + c.Image);//报错，没有适当的构造函数。无法从Complex2 转化为Complex2?

	//结论：这里返回的就是局部变量，因为实际用途中a = b +c ，a=的+表达的值，要调用的是重载的=运算符，而非复制构造函数，因此不需要考虑返回值为引用。
	//
}
Complex2  Complex2::operator+(double d)
{
	cout << "进入+d的重构函数内" << endl;
	Complex2 temp(Real + d, Image);//temp的生命周期是表达式的生命周期。
	return temp;

	//return Complex2(Real + d, Image);//为什么发生没有对应的赋值构造函数的错误？难道现在不允许隐式说明局部对象了？
}
Complex2  Complex2::operator+=(const Complex2& c)
{
	Complex2 temp;
	temp.Real = Real + c.Real;
	temp.Image = Image + c.Image;

	Real = temp.Real;
	Image = temp.Image;

	return temp;//返回的是表达式本身的值
}

Complex2  Complex2::operator*(const Complex2& c)
{
	Complex2 temp;
	temp.Real = Real * c.Real - Image * c.Image;
	temp.Image = Real * c.Image + c.Real * Image;

	return temp;
}
Complex2  Complex2::operator/(const Complex2& c)
{
	Complex2 temp;
	double d = c.Real * c.Real + c.Image * c.Image;
	temp.Real = (Real * c.Real + Image * c.Image) / d;
	temp.Image = (Image * c.Real - Real * c.Image) / d;

	return temp;
}
*/
//Complex2 Complex2::operator++(int)
//{
//
//	Complex2 temp(Real++, Image++);
//	return temp;
//
//}
//Complex2 Complex2::operator++()
//{
//	Complex2 temp(++Real, ++Image);
//	return temp;
//}
//double Complex2::abs()
//{
//	return sqrt(Real * Real + Image * Image);
//}

//友元函数不能加Complex2::，因为它本身就不属于Complex2类，而是赋予这个函数访问Complex2类私有成员的权限。
//Complex2 operator+(double d, const Complex2& c)
//{
//	Complex2 tmp(d + c.Real, c.Image);
//	return tmp;
//}
Complex2 operator++(Complex2& c, int a)
{
	Complex2 temp(++c.Real, ++c.Image);
	return temp;
}
Complex2 operator++(Complex2& c)
{
	Complex2 temp(++c.Real, ++c.Image);
	return temp;
}
double abs(Complex2& c)
{
	return sqrt(c.Real * c.Real + c.Image + c.Image);
}
Complex2 operator+(const Complex2& c1, const Complex2& c2)
{
	cout << "进入友元函数内" << endl;
	Complex2 tmp(c1.Real + c2.Real, c1.Image + c2.Image);
	return tmp;
}

Complex2& operator+=(Complex2& c1, const Complex2& c2)
{
	c1.Real = c1.Real + c2.Real;
	c1.Image = c1.Image + c2.Image;
	return c1;
}
Complex2 operator*(const Complex2& c1, const Complex2& c2)
{
	Complex2 temp;
	temp.Real = c1.Real * c2.Real - c1.Image * c2.Image;
	temp.Image = c1.Real * c2.Image + c2.Real * c1.Image;

	return temp;
}
Complex2 operator/(const Complex2& c1, const Complex2& c2)
{
	Complex2 temp;
	double d = c2.Real * c2.Real + c2.Image * c2.Image;
	temp.Real = (c1.Real * c2.Real + c1.Image * c2.Image) / d;
	temp.Image = (c1.Image * c2.Real - c1.Real * c2.Image) / d;

	return temp;
}

void Test::Printf_Com()
{
	Complex2 c;
	cout << "c.Real=" << c.Real << endl;
}




static void func(Complex2);
static void func2(Complex2&);
static void func3(const Complex2&);

static void fun4(const char& c);
static void fun5(const Complex2& c);
static void fun6(char& c);
static void fun7(Complex2& c);

//测试非友元函数，能否访问私有成员。
static void fun8(Complex2& c);
int main10()
{
	cout << __cplusplus << endl;
	//Complex2 test(1.0, 1.0);
	//Complex2 test2(1.9);
	//Complex2 test3;
	/*上面调用的都是同一个构造函数*/

	//下面是对const 引用和引用作为函数参数类型时的研究
	/*
	Complex2 cc;
	func(cc);
	func2(cc);
	func3(cc);*/
	//只有func进行了复制拷贝。而func3虽然生成了一个临时对象，但并未调用复制构造函数。
	//实际上不管是引用，还是const引用，都创建了一个临时对象，引用指向这个空间，但是用户无法访问。（猜测是相当于封装了一层指针，该指针指向源地址。后面测试证明确实如此）
	//在引用修饰函数参数的情况下，const引用和引用的区别，在内存存储机制上还未有区分，但内存访问机制由于const的缘故，其修饰的关键字是引用，则该引用的对象无法进行写操作。


	//下面分析的是引用和const引用类型不作为参数，而是普通变量的修饰符时的情况：
	//double dval = 'a';
	//const char& ri = dval;//@回答上面形参和实参类型不一致的问题，说明由于临时对象，隐式的进行了引用和类型的转化。

	//double dval_d = ri;
	//long dval_l = ri;
	//发现const引用类型可以接受任意类型，而同样的，const 引用可以赋值给任意类型。 为什么呢？
	//一个类型去接受const &类型时具体是怎么执行的呢？当const char& ri =dval类型去接受时相当于先申请了一个char temp =dval；再用const char&ri =temp;ri指向这个临时temp对象。所以ri引用的地址和dval不在一处，而是temp。
	//那么接受时，也应该申请一个临时对象，比如,double dval_d=ri;时，ri对应的临时对象是char temp;是不是dval_d = (double) temp;对char型的temp 进行了一次类型转换赋给了dval_d？但这怎么证明呢？

	//cout << "dval=" << dval << "\t" << "ri=" << ri << "\t" << "dval_d=" << dval_d << "\t" << "dval_l=" << dval_l << "\t" << endl;//值都一致
	//cout << "&dval=" << &dval << "\t" << "&ri=" << (void*)& ri << "\t" << "&dval_d=" << &dval_d << "\t" << "&dval_l=" << &dval_l << "\t" << endl;//地址都不同，尽管ri是引用。
	//问题：对引用类型进行解引用获得的是什么呢？const &和普通&的区别在哪？结论：对引用类型进行解引用，实际上获得的还是被引用变量处的地址，如果该引用是const类型，且经过类型转换，那么可能首地址会改变。

	/*
	对于普通&而言，在非函数参数的前提下，解引用是得到引用变量自身的地址。编译器把引用类型声明的变量名，作为别名使用。
	对于const &而言，在非函数参数的前提下，解引用得到的是临时对象的地址。用户无法访问这个临时空间，但输出ri时，实际上是从临时对象的内存空间取出数据的。
	@2那么作为函数参数时，这个临时对象是类的话，会不会进行copy呢？上面已经试验过，并没有copy，那么猜测这个临时对象在作为参数时，可能是指针类型。验证方法还是sizeof引用类型的变量。
	*/
	//注意上面三行是错误的结论。不管怎么样都无法去访问临时对象的。实际上不管是普通&还是const &，都会申请一个临时对象，这个临时对象应该是指针，因为测试后发现和指针占用的长度一致。
	//而这个临时对象，不管是否引用是参数还是普通变量，都无法访问到，所以解引用操作其实操作的是被引用的地址，而非临时对象。


	//下面尝试访问下这个临时对象：
	//char* test = &ri; //并不能通过编译，无法取得const &类型的值，用于初始化。

	//int& ri_i = dval; 由于类型不匹配，导致编译不通过。
	/*
	double& ri_d = dval;
	const double& ri_i = dval;
	cout << "&dval=" << &dval << "\t" << "&ri_d=" << &ri_d << "\t" << "&ri_i=" << &ri_i << "\t" << "&ri=" << (void*)& ri << endl;
	*/
	//发现ri_d引用类型，是指向同一地址的，但是ri作为const引用类型，则与dval本身不是同一地址。但若const 引用类型的基础数据类型与被引用数据类型相同则还是同一地址，
	//那么ri到底存储的是什么呢？可以通过观察他本身占用内存地址的空间来判断：
	//补充结论：引用不论有没有const，&和其他操作都应该操作的还是被引用变量的地址，临时对象用户不能访问，就如同字面意思一样，无法操作。
	//需要注意的如果const引用类型由于基础类型不同，发生了类型转换的话，那么会发现引用的首地址，并非被引用变量的首地址。这应该与地址的变长有关，需要关注的是若是从字节长度小的转化为长的会怎么样？反过来呢？
	//这里测试了由长字节变为短字节的情况：dval的首地址为：00EFF7C0,char 类型的ri的首地址为:00EFF7AB，中间差了0x15，。
	//TODO@3思考double数据的内存分配，前四个字节为高位，后四个字节为低位，由于dval数据保存在后四个字节，于是ri指向的是dval偏移4个字节后的位置。错误。。。。
	//TODO@4猜测，如果由短到长，也就是一个const引用的基础类型要是占用空间大于被引用的，就会发生错误。

	//cout << "ri占用字节数:" << sizeof(ri) << endl;//注意这里的说法并不准确，并非ri占用的字节数，实际上操作的还是ri所引用的对象。ri引用本身指向的是一个临时对象，但是这个对象不可访问。
	/*
	4个字节，是32位系统下指针的长度，可见创建的临时对象，是一个指针。但我们却无法通过输出直接知道这个指针的值是否指向dval，因为编译器做了限制。你若想输出ri，实际上编译器并非要输出ri对应临时对象（即指针）中的值，查看是否是dval的地址，而是直接编译语义为dval的值，看上去是进行了一层语义的封装。而对ri进行取地址&操作后，得到的地址确实是这个临时对象的。而非也封装了语义使其指到dval。
	上面结论有问题的，当把ri的类型改为const char&时，sizeof的大小是1，书中说ri指向的是临时对象，而这个临时对象并不是指针。而是const 修饰的存储类型，即char。
	可想而知，把const char&改为const double&后，ri引用指向的便是double临时变量，那么其大小则是double长度。
	//注意上方3行都是错误的推导过程。因为以为sizeof可以操作引用类型本身，也就是临时对象。对sizeof不熟悉导致。
	*/
	//const double& rd = dval;
	//cout << "rd占用字节数:" << sizeof(rd) << endl;
	//错误，实际上临时对象确实是指针，只不过测试过程中以为sizeof能够操作这个临时对象，实际上包含&、sizeof所有操作，操作都已经引向了被引用的变量，而非临时对象。


	/*//@2测试：
	//fun4(dval); fun4(dval_l);//结论：如果是基本数据类型，const &表现形式和普通使用过程中表现一致。
	Complex2 com;
	cout << "com对象的大小为：" << sizeof(com) << "com的首地址为：" << &com << endl;
	//fun5(dval);
	fun5(com);//当实参并非Complex2类型时，编译可以通过，但是在函数操作过程中，实际会不会造成错误？
	char chr = 'b';
	cout << "chr的首地址为：" << (void*)& chr << endl;
	//输出char型地址为什么会乱码？TODO 第四版第十二章。

	fun6(chr);
	fun7(com);

	fun5(chr);//此时外部实参chr的长度小于形参的Complex
	//TODO输出结果为：chr地址:0099F9AB，形参地址：0099F8D0 首先明显不相等。
	*/


	Complex2 c1(1.0, 1.0), c2(2.0, 2.0), c3(4.0, 4.0), c, c4;
	double d = 0.5;
	//c1.Printf();
	//c4 = c = c2 + c3;//提示，没有合适的构造函数，构造函数默认的参数是引用，现在c2+c3返回的是一个值，那该怎么办？修改为引用的话，那就不能作为局部变量返回了。
	//发现无论左值是否已经进行过初始化，都会调用复制构造函数。这和之前例4.7结论不相符。
	//实际上c1 = +成员函数的返回值，是想让他走=的重载函数，而非复制构造函数的，这里错走了复制构造函数才是根本问题。
	//不能走=运算符的重载成员函数，原因在于参数的类型。
	//假如+重载的成员函数返回值类型是Complex2,而=重载的成员函数参数是Complex2，应该是可以的。
	//假如+重载的成员函数返回值类型是Complex2,而=重载的成员函数参数是const Complex2&，由于const引用做了隐式转换，则也可以。
	//假如+重载的成员函数返回值类型是Complex2&,而=重载的成员函数参数是Complex2，则将会走复制重构函数。
	//假如+重载的成员函数返回值类型是Complex2&,而=重载的成员函数参数是const Complex2&，则可以但+过程中肯定要生成一个新的值，如果是引用，则新值保存在加数上，则加数本身不可再用了，所以感觉+的返回值不应该为引用。
	//=的返回值则可以返回自身的引用，因为=不会在后面改变参数的值。
	cout << "c实参的地址:" << &c << endl;
	c.Printf();

	//c += c1; c.Printf();
	//c = c + d; c.Printf();
	//c = c3 * c2; c.Printf();
	//c = c3 / c1; c.Printf();
	//cout << "c3的模为:" << c3.abs() << endl;
	//c = c3 = c2 = c1; c.Printf();
	//c += c3 += c2 += c1; c.Printf();

	//c = d + c;
	//c.Printf();//这里d虽然是double，但是在实际运行过程中，作为参数传给Comlex2的默认构造函数，进入了友元函数对+的重构。可以看到是不同类型的转化，但不单单只是首地址改变。
	//注意这里对d实参传递到const &形参时，进行了一次默认构造函数，说明不仅仅是指针了？而是申请了一个类的空间。这是什么机制？

	/*
	fun5(d);
	//发现，d实参在传给形参时经过一次构造函数，是不是这样？：引用是指针，但指向的不是源地址，而是确实存在一个临时对象，该临时对象根据被引用的类型转换而来，所以一个引用，存在三个地址概念？
	fun5(c);
	//问题：如果是同基础类型作为实参，则不会经过构造函数，那猜测还会有临时对象的存在吗？临时对象存储在哪里呢？生命周期是可想而知是函数的生命周期。
	fun5(d);
	//首先经过测试，可以确认如果类型是const &，解引用得到的确实是临时对象的地址，而非d的，因为俩次调用fun5(d)时输出的c地址并不相同，而d本身的位置是不会变得。
	//但是每次，不论实参是d还是c，mark的地址都一致，但感觉这个临时对象并不在栈中，因为mark地址都一致表示进入执行到mark时每次栈的位置都是固定的，长度不变。所以栈中保存的是引用的大小。
	//猜测是动态申请的临时对象，因而是保存在堆中的。
	fun5(c);
	//发现c作为实参时，形参输出的地址便是实参地址，说明引用指向的是实参，并没有指向临时对象，这是不是说明没有临时对象的存在？。因为没有临时对象，自然而然不用构造函数了。
	*/

	/*c = c2 + c3; c.Printf();
	c += c2 += c1; c.Printf();
	c = c + d; c.Printf();
	c = d + c; c.Printf();
	c = c3 * c2; c.Printf();
	c = c3 / c1; c.Printf();
	c = c3 * d; c.Printf();
	c = c3 / d; c.Printf();
	cout << "c3的模为:" << abs(c3) << endl;

	c = c3++;*/

	Test test;
	test.Printf_Com();

	//cout << "main地址" << &main << "退出main函数" << endl;

	return 0;
}
static void func(Complex2 c)
{
	c.Printf();
	cout << "进入func函数" << endl;
}
static void func2(Complex2& c)
{
	c.Printf();
	cout << "进入fun2c函数" << endl;
}
static void func3(const Complex2& c)//c只读，不可写。
{
	//c.Printf();//无法调用，why？这里有写操作吗？
	cout << "进入func3函数" << endl;
}

static void fun4(const char& c)
{
	cout << "func4中c变量的长度:" << sizeof(c) << endl;
}

//下面的测试，sizeof都与外部实参类型大小一致，原因并非创建的临时对象与实参类型一致，而是sizeof无法操作临时对象，而是操作的外部实参本身的地址。
static void fun5(const Complex2& c)
{
	int mark;
	cout << "进入fun5时，mark的地址" << &mark << endl;
	cout << "func5中c变量的长度:" << sizeof(c) << ",c的地址：" << &c << endl;
	//（错误，以为sizeof操作的是临时变量本身)发现c的大小是Complex对象的大小，而不管实参的大小。如同const &创建的临时对象为Complex2类型一致，说明并非指针类型。
	//但若是新创建了Complex2对象的话，应该会调用构造函数的才是？Complex2 temp = 实参。
	//另一方面想：如果要是调用了构造函数，那么const Complex2&作为参数类型，和Complex2作为参数类型岂不是没有任何区别了？
	//补充：
}
static void fun6(char& c)
{
	//如果只是引用的话，c变量在栈中占有一块内存，指向的是外部实参的地址。补充：测试后发现引用本身即是占用空间的，大小和指针长度一致。
	cout << "func6中c变量的长度:" << sizeof(c) << ",c的地址：" << (void*)& c << endl;
	//但如果sizeof 这个引用的话，获得的并非这块内存的大小，而是外部实参占用的大小。
	//结论：因此无论是如何对类型为引用的变量进行，包含&以内的任何操作，实际上都会被指向被引用处地址。
	//这栈中临时的内存是访问不到的，和在函数中使用引用效果一致。
}
static void fun7(Complex2& c)
{
	cout << "func7中c变量的长度:" << sizeof(c) << ",c的地址：" << &c << endl;
	//这里实际上const 引用，也是引用，实现效果如fun6，都是栈中为参数申请了一块指针，但由于编译器封装了引用操作，所以对引用类型的变量进行的操作，都将操作的是外部实参。
}
//猜测：如果引用作为返回值，并非没有创建临时空间，而也是创建了一个指针，指向被引用位置，函数外接收返回值时，根据指针去被引用处获取所要的数据，那么就不会进行一次整个类型的copy了。
//TODO进行反汇编观察。
//感觉返回值往往不用声明为const。


static void fun8(Complex2& c)
{
	//c.Real;无法访问。
}
