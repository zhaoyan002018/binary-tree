#pragma once
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

class inventory
{
	string Decsription;
	string No;
	int Quantity;
	double Cost;
	double Retail;
public:
	inventory(string = "#", string = "0", int = 0, double = 0, double = 0);
	friend ostream& operator<<(ostream& dist, inventory& iv);
	friend istream& operator>>(istream& sour, inventory& iv);
	void Bdatatofile(ofstream& dist);
	void Bdatafromfile(ifstream& sour);
	void Bdatatofile(fstream& dist);
	void Bdatafromfile(fstream& sour);

	bool operator==(inventory& iv) { return No == iv.No; }
	bool operator<=(inventory& iv) { return No <= iv.No; }

};
inventory::inventory(string des, string no, int qua, double co, double re)
{
	Decsription = des;
	No = no;
	Quantity = qua;
	Cost = co;
	Retail = re;
}

ostream& operator<<(ostream& dist, inventory& iv)//os<<将对象插入到os中
{
	dist << left << '\n' << iv.Decsription << '\n' << iv.No;
	dist << right << '\n' << iv.Quantity << '\n' << iv.Cost << '\n' << iv.Retail << endl;
	return dist;
}
istream& operator>>(istream& sour, inventory& iv)//is>>从文件中提取给iv。
{
	sour >> iv.Decsription >> iv.No >> iv.Quantity >> iv.Cost >> iv.Retail;
	return sour;
}

void inventory::Bdatatofile(ofstream& dist)
{
	//二进制文件写入，不能像文本文件用<<，而是write并且需要指明长度。和c语言类似
	dist.write(Decsription.c_str(), 20);
	dist.write(No.c_str(), 10);
	dist.write((char*)& Quantity, sizeof(int));
	dist.write((char*)& Cost, sizeof(double));
	dist.write((char*)& Retail, sizeof(double));

}

void inventory::Bdatafromfile(ifstream& sour)
{
	char k[20];
	sour.read(k, 20);
	Decsription = k;
	sour.read(k, 10);
	No = k;
	sour.read((char*)& Quantity, sizeof(int));
	sour.read((char*)& Cost, sizeof(double));
	sour.read((char*)& Retail, sizeof(double));
}
void inventory::Bdatatofile(fstream& dist)
{
	//二进制文件写入，不能像文本文件用<<，而是write并且需要指明长度。和c语言类似
	dist.write(Decsription.c_str(), 20);
	dist.write(No.c_str(), 10);
	dist.write((char*)& Quantity, sizeof(int));
	dist.write((char*)& Cost, sizeof(double));
	dist.write((char*)& Retail, sizeof(double));

}

void inventory::Bdatafromfile(fstream& sour)
{
	char k[20];
	sour.read(k, 20);
	Decsription = k;
	sour.read(k, 10);
	No = k;
	sour.read((char*)& Quantity, sizeof(int));
	sour.read((char*)& Cost, sizeof(double));
	sour.read((char*)& Retail, sizeof(double));
}






template<typename T>class Array {
	T* ele;
	int sub;	//已用最大下标值
	int max;
	fstream datafile;
public:
	Array(int = 10);
	~Array();
	bool IsFull()const { return sub = max - 1; }
	void renews();
	void show() { cout << "已用最大下标值" << sub << '\t' << "可用元素个数：" << max << endl; }
	void ordinsert(T&);
	template< typename N> friend ostream& operator<<(ostream&, Array<N>&);
};

template<typename N>ostream& operator<<(ostream& dist, Array<N>& ar)
{
	int i;
	for (i = 0; i <= ar.sub; i++)cout << ar.ele[i];
	return dist;
}


template<typename T> Array<T>::Array(int m)
{
	max = m;
	sub = -1;
	T temp;
	ele = new T[max];//调用无参构造函数。但即使有了默认值的参数，也没法调用。
	datafile.open("mydatafile.txt", ios::in);
	if (datafile) {
		while (!datafile.eof())
		{
			datafile >> temp;
			if (datafile.eof() == 0) {
				ordinsert(temp);
			}
		}
		datafile.close();
	}
	datafile.clear(0);
}

template<typename T> Array<T>::~Array()
{
	int i;
	datafile.open("mydatafile.txt", ios::out);
	for (i = 0; i <= sub; i++)datafile << ele[i];
	datafile.close();
	delete[] ele;
}

template<typename T> void Array<T>::ordinsert(T& e)
{
	int i, j;
	//if (IsFull())renews();

	for (i = 0; i <= sub; i++)if (e <= ele[i])break;

	if (!(e == ele[i]))
	{
		j = sub;
		for (; j >= i; j--)ele[j + 1] = ele[j];
		sub++;
	}
	ele[i] = e;
	show();

}
