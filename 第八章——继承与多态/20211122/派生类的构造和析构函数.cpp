//由在测人员类公有派生学生类
#include<iostream>
#include<string>
using namespace std;

enum Tsex { mid, man, woman };
struct course {
	string coursename;
	int grade;
};
class Person {
	string IdPerson;
	string Name;
	Tsex Sex;
	int Birthday;
	string HomeAddress;
public:
	Person(string, string, Tsex, int, string);
	Person();
	virtual ~Person();
	Person& operator= (Person&);
	Person(Person& ps) { IdPerson = ps.IdPerson; Name = ps.Name; Sex = ps.Sex; Birthday = ps.Birthday; HomeAddress = ps.HomeAddress; }
	void SetName(string name) { Name = name; }
	string GetName() { return Name; }
	void SetSex(Tsex sex) { Sex = sex; }
	Tsex GetSex() { return Sex; }
	void SetId(string id) { IdPerson = id; }
	string GetId() { return IdPerson; }
	void SetBirth(int birth) { Birthday = birth; }
	int GetBirth() { return Birthday; }
	void SetHome(string home) { HomeAddress = home; }
	string GetHome() { return HomeAddress; }
	void PrintPersonInfo();
};
Person& Person::operator= (Person& ps)
{
	IdPerson = ps.IdPerson; Name = ps.Name; Sex = ps.Sex; Birthday = ps.Birthday; HomeAddress = ps.HomeAddress;
	return *this;
}
Person::Person(string id, string name, Tsex sex, int birh, string home)
{
	cout << "进入person 含参构造函数" << endl;
	IdPerson = id;
	Name = name;
	Sex = sex;
	Birthday = birh;
	HomeAddress = home;
}

Person::Person() {
	cout << "进入person 默认构造函数" << endl;
	IdPerson = "#"; Name = "#"; Sex = mid; Birthday = 0; HomeAddress = "#";
}

Person::~Person() { cout << "person析构" << endl; }//string内部动态数组的释放，由string自带的析构函数完成。

void Person::PrintPersonInfo()
{
	int i;
	cout << "身份证号:" << IdPerson << '\n' << "姓名" << Name << '\n' << "性别";
	if (Sex == man) cout << "男" << '\n';
	else if (Sex == woman) cout << "女" << '\n';
	else cout << "" << '\n';
	cout << "出生年月日：";
	i = Birthday;
	cout << i / 10000 << "年";
	i = i % 10000;
	cout << i / 100 << "月" << i % 100 << "日" << '\n' << "家庭地址：" << HomeAddress << '\n';
}
/******************************************************************************************************************/
class Student :public virtual Person
{
	string NoStudent;
	course cs[30];
	static const string UNUSE;
public:
	Student(string, string, Tsex, int, string, string);
	Student();
	~Student();
	//赋值兼容规则：在任何需要基类对象的地方都可以用公有派生类的对象来代替
	Student(Student& std) :Person(std) {
		//按照赋值规则，student类型的std，可以作为person构造函数的参数。
		NoStudent = std.NoStudent;
		int i;
		for (i = 0; i < 30; i++)
		{
			cs[i].coursename = std.cs[i].coursename;
			cs[i].grade = std.cs[i].grade;
		}
	}
	Student& operator=(Student&);
	int SetCourse(string, int);
	int GetCourse(string);
	void PrintStudentInfo();
};
const string Student::UNUSE = "#";

Student& Student::operator=(Student& std)
{
	cout << "进入Student=运算符重载函数" << endl;
	this->Person::operator=(std);
	int i;
	NoStudent = std.NoStudent;
	for (i = 0; i < 30; i++)
	{
		cs[i].coursename = std.cs[i].coursename;
		cs[i].grade = std.cs[i].grade;
	}
	return *this;
}

Student::Student(string id, string name, Tsex sex, int birh, string home, string nostudent)
//:Person(id, name, sex, birh, home)
{
	/*思考如果不写:基类名，还会去调动基类的构造函数吗？答案会进入默认构造函数中,而且是率先调用基类的构造函数*/
	cout << "进入Student含参构造函数" << endl;
	//共有派生类中也无法直接访问基类中的私有成员
	SetId(id);
	SetName(name);
	SetSex(sex);
	SetBirth(birh);
	SetHome(home);
	NoStudent = nostudent;
	int i;
	for (i = 0; i < 30; i++)
	{
		cs[i].coursename = UNUSE;
		cs[i].grade = 0;
	}
}

Student::Student()
{
	cout << "进入Student默认构造函数" << endl;
	int i;
	NoStudent = "0";
	for (i = 0; i < 30; i++)
	{
		cs[i].coursename = UNUSE;
		cs[i].grade = 0;
	}
}


Student::~Student() {}//基类析构函数以及成员对象析构函数自动调用。
int Student::SetCourse(string coursename, int grade)
{
	int i;
	bool b = false;
	for (i = 0; i < 30; i++)
	{
		if (cs[i].coursename == UNUSE) {
			//判断表是否进入未使用部分。思考，这里可以把#未使用部分，额外用常量表示出来，可读性更好，在一开始就声明#在实际中的含义是什么，而不需要阅读代码逻辑来推测。
			cs[i].coursename = coursename;
			cs[i].grade = grade;
			b = false;
			break;
		}
		else if (cs[i].coursename == coursename) {
			//是否已有该课程
			cs[i].grade = grade;
			b = true;
			break;
		}
	}
	if (i == 30) return 0;
	if (b) return 1;
	else return 2;
}

int Student::GetCourse(string coursename)
{
	int i;
	for (i = 0; i < 30; i++)if (cs[i].coursename == coursename) return cs[i].grade;
	return -1;
}

void Student::PrintStudentInfo()
{
	int i;
	cout << "学号:" << NoStudent << '\n';
	PrintPersonInfo();
	for (i = 0; i < 30; i++)
	{
		if (cs[i].coursename != "#")cout << cs[i].coursename << '\t' << cs[i].grade << '\n';
		else break;
	}
	cout << "……完……" << endl;
}
/******************************************************************************************************************/
class GStudent :public Student
{
	string NoGStudent;
public:
	GStudent(string id, string name, Tsex sex, int birh, string home, string nostudent, string nogstudent);
	GStudent();
	~GStudent() { cout << "析构GStudent" << endl; }
	void PrintGStudentInfo();
};
GStudent::GStudent(string id, string name, Tsex sex, int birh, string home, string nostudent, string nogstudent)
	:Student(id, name, sex, birh, home, nostudent), Person(id, name, sex, birh, home)
{//person作为虚基类，尽管不是直接基类，也必须出现。
	cout << "构造GStudent" << endl;
}
void GStudent::PrintGStudentInfo()
{
	cout << "研究生号：" << NoGStudent << "\n";
	PrintStudentInfo();
}
/******************************************************************************************************************/

class Employee :public virtual Person {
	string NoEmployee;
public:
	Employee(string id, string name, Tsex sex, int birh, string home, string noempl);
	Employee() { cout << "默认构造Employee" << endl; }
	~Employee() { cout << "析构Employee" << endl; }
	void PrintEmployeeInfo();
	void PrintEmployeeInfo1();

};
Employee::Employee(string id, string name, Tsex sex, int birh, string home, string noempl)
	:Person(id, name, sex, birh, home)
{
	cout << "构造Employee" << endl;
	NoEmployee = noempl;
}
void Employee::PrintEmployeeInfo()
{
	cout << "教职工号:" << NoEmployee << '\n';
	PrintPersonInfo();
}
void Employee::PrintEmployeeInfo1()
{
	cout << "教职工号:" << NoEmployee << '\n';
}
/******************************************************************************************************************/
class EGStudent :public Employee, public GStudent
{
	string NoEGStudent;
public:
	EGStudent(string id, string name, Tsex sex, int birh, string home, string noempl, string nostudent, string nogstudent, string noegstudent);
	EGStudent() { cout << "EGStudent默认构造函数" << endl; }
	~EGStudent() { cout << "析构EGStudent" << endl; }
	void PrintEGStudentInfo();
};
EGStudent::EGStudent(string id, string name, Tsex sex, int birh, string home, string noempl, string nostudent, string nogstudent, string noegstudent)
	:Employee(id, name, sex, birh, home, noempl), GStudent(id, name, sex, birh, home, nogstudent, noegstudent), Person(id, name, sex, birh, home)
{
	cout << "构造EGStudent" << endl;
	NoEGStudent = nogstudent;
}
void EGStudent::PrintEGStudentInfo()
{
	cout << "在职学生号" << NoEGStudent << '\n';
	PrintEmployeeInfo1();//避免多重继承时，重复打印虚基类Person的信息
	PrintGStudentInfo();//只在GStudent中打印Person的信息
}

int main2()
{
	EGStudent egstu1("201515614514", "周杰", man, 19971020, "名的公寓", "0110", "034189", "06283", "030217");
	egstu1.PrintEGStudentInfo();

	GStudent gstu1("201515614515", "赵焱", man, 19970930, "明德公寓", "034129", "06223");
	gstu1.PrintGStudentInfo();

	return 0;
}

int main4()
{
	string tmp;
	int i, k;
	//Person per1("201515614514", "赵焱", man, 19970930, "磊磊公寓");
	//per1.PrintPersonInfo();
	Student stu1("201515614514", "周杰", man, 19971020, "明德公寓", "0101");
	//Student stu2;
	cout << "请输入各科成绩:" << '\n';
	while (1)
	{
		cin >> tmp;
		if (tmp == "end") break;
		cin >> k;
		i = stu1.SetCourse(tmp, k);
		if (i == 0)
			cout << "成绩列表已满！" << endl;
		else if (i == 1) cout << "修改成绩" << '\n';
		else cout << "登记成绩" << '\n';
	}

	stu1.PrintStudentInfo();
	/*while (1)
	{
		cout << "查询成绩" << "\n" << "请输入科目" << '\n';
		cin >> tmp;
		if (tmp == "end")break;
		k = stu1.GetCourse(tmp);
		if (k == -1)cout << "未查到" << endl;
		else cout << k << '\n';
	}
	stu2 = stu1;
	stu2.PrintStudentInfo();
	Student stu3 = stu2;
	stu3.PrintStudentInfo();*/
	Person* pper4;
	Student* pstu4 = new Student();
	//Student* pstu4 = new Student; 加不加()效果一样，都是调用默认的构造函数。
	*pstu4 = stu1;
	pstu4->PrintStudentInfo();
	pper4 = pstu4;
	delete pper4;


	return 0;
}
