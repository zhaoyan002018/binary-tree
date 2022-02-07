#include"common.h"


//放在头文件中多个cpp文件include会出现多次重载的错误，因为它本身是全局的函数，并非类的成员。
ostream& operator<<(ostream& os, element2& ele)
{
	os << ele.key;
	return os;//这样就可以连续使用<<,譬如cout<<5<<ele<<endl;
}
/*………………………………………………………………………………………………………………………………*/

int main4()
{
	int n[10] = { 1,22,33,44,51,62,74,81,90,92 };
	element<int> e[10];//类名<>中要填入实际参数

	element2 e2[10];

	int i = 0;
	for (; i < 10; i++) {
		e[i].putKey(n[i]);
		e2[i].putKey(n[i]);
	}

	orderList< element<int>, 100>orderlist;//一个模板的模板参数，是另一个模板？这样难道没有完成模板实例化吗？
	//后面进行比较的时候，尽管重载了element类的比较运算符，但依旧调用orderList类的Binarysearch提示找不到重载的运算符。
	//但如果是element2类就可以，其key的类型确定为int。但在给orderlist初始化时，已经给出了element的key的类型为int，貌似适合下面orderlist2是等效的才是，但实际过程中却无法通过。
	//解决了，实际上初始化没有问题，问题出在element类型对<的重载

	orderList<element2, 100>orderlist2;

	while (i) {

		i--;

		orderlist.insert(e[i], 0);
		orderlist2.insert(e2[i], 0);
	}


	element<int> ele = 44;
	element2 ele2 = 44;


	//orderlist.traverse();
	orderlist.print();
	int m = 1 + orderlist.Binarysearch(ele, 0, 9);
	cout << "查到的位置是：" << m << endl;

	orderlist2.traverse();//之前无法使用<<输出，由于<<没有重载 其右操作数为我们自己定义的类的方式，因此最好输出是使用类自身提供的成员函数，当然如果是基础类型就可以<<输出
	//orderlist2.print();
	int k = 1 + orderlist2.Binarysearch(ele2, 0, 9);
	k = 1 + orderlist2.Binarysearch(ele2);
	cout << "查到的位置是：" << k << endl;
	return 0;
}
