#include<iostream>
#include<string>

using namespace std;
class Person2
{
	int MarkAchieve;
	string Name;
public:
	Person2(string name) {
		cout << "Person2构造函数" << endl;
		Name = name;
		MarkAchieve = 0;
	}
	void SetMark(int mark) { MarkAchieve = mark; }
	virtual void Calmark() = 0;//calmark为纯虚函数，person为抽象类
	void Print() { cout << Name << "的业绩分为" << MarkAchieve << endl; }
};

class Student3 :public Person2
{
	int credit, grade;
public:
	Student3(string name, int cred, int grad) :Person2(name)
	{
		credit = cred;
		grade = grad;
	}
	void Calmark() { SetMark(credit * grade); }
};

class Teacher :public Person2 {
	int classhour, studnum;
public:
	Teacher(string name, int ch, int sn) :Person2(name)
	{
		classhour = ch;
		studnum = sn;
	}
	void Calmark()
	{
		int K = (studnum + 15) / 30;
		switch (K)
		{
		case 1:SetMark(classhour * studnum); break;
		case 2:SetMark(classhour * (30 + (studnum - 30) * 8 / 10)); break;
		case 3:SetMark(classhour * (30 + 24 + (studnum - 60) * 6 / 10)); break;
		case 4:SetMark(classhour * (30 + 24 + 18 + (studnum - 90) * 4 / 10)); break;
		case 5:SetMark(classhour * (30 + 24 + 18 + 12 + (studnum - 120) * 2 / 10)); break;
		default:
			SetMark(classhour * (30 + 24 + 18 + 12 + 6 + (studnum - 150) * 1 / 10));
			break;
		}
	}
};


int main8()
{
	//Person2 pp; 因为Person2是抽象类，所以无法初始化一个对象
	Person2* pp;
	Student3 s1("黎明", 20, 80);
	Teacher t1("范围", 64, 125), t2("离开", 80, 85);
	pp = &s1;
	pp->Calmark();
	pp->Print();

	pp = &t1;
	pp->Calmark();
	pp->Print();

	pp = &t2;
	pp->Calmark();
	pp->Print();
	return 0;
}
