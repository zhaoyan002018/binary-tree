#include"公司类.h"


void payFunc(employee* ep)
{
	ep->pay(0);
	cout << ep->name << "其月薪为：" << ep->salary << endl;
}

int main()
{
	employee* ep;
	technician t1("王二", 1, 1, 8000, 20, 150, 0.8);
	salesman s1("张三", 2, 1, 5000, 20000, 0.2);
	manager m1("李四", 3, 1, 10000, 5000, 0.5);

	ep = &t1;
	payFunc(ep);
	ep = &s1;
	payFunc(ep);
	ep = &m1;
	payFunc(ep);

	devel_opermanger do1("王五", 4, 2, 10000, 5000, 0.1, 20, 150, 1);
	salesmanager sm1("孙六", 5, 2, 8000, 5000, 0, 20000, 0.3);
	ep = &do1;
	payFunc(ep);
	ep = &sm1;
	payFunc(ep);

	technician t2(t1);
	ep = &t2;
	payFunc(ep);
}
