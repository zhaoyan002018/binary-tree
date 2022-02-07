#include<iostream>
#include<string>
using namespace std;
class Student2 {
	string coursename;
	int classhour;
	int credit;
	static const string UNUSE;
public:
	Student2() { coursename = UNUSE; classhour = 0; credit = 0; }
	virtual void Calculate() { credit = classhour / 16; }
	virtual Student2& func() { cout << "Student2 func" << endl; return *this; }
	void SetCourse(string str, int hour)
	{
		coursename = str;
		classhour = hour;
	}
	int GetHour() { return classhour; }
	void SetCredit(int credit) { this->credit = credit; }
	void Print() {
		cout << coursename << "\t" << classhour << "学时" << "\t" << credit << "学分" << endl;
	}
};
const string Student2::UNUSE = "#";

class GradeStudent :public Student2
{
public:
	GradeStudent() {};
	void Calculate() { SetCredit(GetHour() / 20); }//与基类的虚函数相同参数类型和返回值，可通过基类指针实现运行时多态。
	GradeStudent& func() { cout << "GradeStudent func" << endl; return *this; }//此时尽管返回类型不同，但如果是返回自身类型的引用是允许的。
};

void Calfun(Student2& ps, string str, int hour)
{
	ps.SetCourse(str, hour);
	ps.Calculate();
	ps.Print();
}

int main7()
{
	Student2 s;
	GradeStudent g;
	cout << "本科生";
	Calfun(s, "物理", 80);
	cout << "研究生";
	Calfun(g, "物理", 80);

	Student2* ps;
	ps = &s;
	ps->func();
	ps = &g;
	ps->func();
	return 0;
}

int main6()
{
	Student2 s, * ps;
	GradeStudent g;

	/*s.SetCourse("物理", 80);
	s.Calculate();
	g.SetCourse("物理", 80);
	g.Calculate();
	cout << "本科生" << '\t';
	s.Print();
	cout << "研究生" << '\t';
	g.Print();
*/
	s.SetCourse("数学", 160);
	g.SetCourse("数学", 160);
	/*s.Calculate();
	g.Calculate();
	cout << "本科生" << '\t';
	s.Print();
	cout << "研究生" << '\t';
	g.Print();*/

	ps = &s;
	ps->Calculate();
	ps->Print();

	ps = &g;
	ps->Calculate();
	ps->Print();
	return 0;

}
