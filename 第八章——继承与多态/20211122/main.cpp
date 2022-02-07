#include"单链表派生类.h"
int main9()
{
	InfoObject* info;
	//int i = 0, arri[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//IntInfo ii[10];
	//while (i < 10)
	//{
	//	ii[i].setInfo(arri[i]);
	//	i++;
	//}

	int i = 0;
	StringInfo si[5];
	string arrs[5] = { "语文","数学","英语","历史","政治" };
	while (i < 5)
	{
		si[i].setInfo(arrs[i]);
		i++;
	}

	/*List list1;
	i = 0;
	while (i < 10)
	{
		info = &ii[i];
		list1.insertRear(info);
		i++;
	}
	list1.print();*/

	List list2;
	i = 0;
	while (i < 5)
	{
		info = &si[i];
		list2.insertRear(info);
		i++;
	}
	list2.print();

	return 0;
}
