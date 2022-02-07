
#include"lianxi.h"
#include<cstring>

CGoods::CGoods(char name[], int amount, float price)
{
	strcpy(goods.Name, name);
	goods.Amount = amount;
	goods.Price = price;
	goods.Total_value = amount * price;
}

CGoods::CGoods(char name[], float price)
{
	strcpy(goods.Name, name);
	goods.Amount = 0.0;
	goods.Price = price;
	goods.Total_value = 0.0;
}

CGoods::~CGoods()
{
}

CGoods::CGoods(CGoods& goods2)
{
	//goods.Amount = goods2.GetAmount();
	//goods.Price = goods2.GetPrice();
	//goods.Total_value = goods2.GetToal_value();
	//goods2.GetName(goods.Name);

	goods.Amount = goods2.goods.Amount;
	goods.Price = goods2.goods.Price;
	goods.Total_value = goods2.goods.Total_value;
	strcpy(goods.Name, goods2.goods.Name);
}

void CGoods::RegisterGoods(char name[], int amount, float price)
{
	strcpy(goods.Name, name);
	goods.Amount = amount;
	goods.Price = price;
}

void CGoods::CountTotal()
{
	goods.Total_value = goods.Price * goods.Amount;
}

void CGoods::GetName(char name[])
{
	strcpy(name, goods.Name);
}

int CGoods::GetAmount(void)
{
	return goods.Amount;
}
float CGoods::GetPrice(void)
{
	return goods.Price;
}
float CGoods::GetToal_value(void)
{
	return goods.Total_value;
}

int main2()
{

	char str[21];
	int number;
	float pr;
	cout << "请输入汽车型号：";
	cin.getline(str, 20);
	cout << "请依次输入汽车数量与单价";
	cin >> number >> pr;

	/*
	CGoods car2();
	CGoods car = car2;
	car2并非对象，而是函数，想要调用无参构造函数，只需CGoods car;即可
	*/

	CGoods car(str, number, pr);//相当于上面俩步。car2不是对象，而是函数，返回值为CGoods对象

	CGoods car3 = car;//调用复制构造函数
	CGoods car4(car3);//调用复制构造函数的另一种形式

	/*car.RegisterGoods(str, number, pr);
	car.CountTotal();*/

	//str[0] = '\0';

	car.GetName(str);

	cout << setw(20) << str << setw(5) << car.GetAmount();
	cout << setw(10) << car.GetPrice() << setw(20) << car.GetToal_value() << endl;
	return 0;

}
