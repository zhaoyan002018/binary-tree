#pragma once
#include<iostream>
using namespace std;
/*
	实现运行时多态，通过虚函数进行。
*/
//雇员类
class employee
{
public:
	string name;//姓名
	int emNo;//雇员编号
	int level;//工资级别
	float salary;//月薪
	float bs_salary;//实发基本工资
	float pf_salary;//业绩工资

	employee(string n = "", int en = 0, int le = 0, float bssa = 0) {
		name = n;
		emNo = en;
		level = le;
		bs_salary = bssa;
		pf_salary = 0;
		salary = bssa + pf_salary;
	}
	employee(employee& ep) {
		name = ep.name;
		emNo = ep.emNo;
		level = ep.level;
		bs_salary = ep.bs_salary;
		pf_salary = ep.pf_salary;
		salary = ep.salary;
	}
	virtual void pay(int leaveN) = 0;
	virtual ~employee() {}
};
//技术人员
class technician : public virtual employee
{
public:
	float addSalary_hours;//时薪加成
	int hours;//当月工时
	float wk_coefficient;//研究完成系数

	technician(string n, int en, int le, float bssa, float addsh, int h, float wkc) :employee(n, en, le, bssa)
	{
		addSalary_hours = addsh;
		hours = h;
		wk_coefficient = wkc;
	}
	void pay(int leaveN) {
		pf_salary = addSalary_hours * hours * wk_coefficient;
		//假定一个月上22天。
		int onN = 22 - leaveN;
		float per = onN / 22;
		salary = pf_salary + bs_salary * per;
	}
	~technician() {}

	technician(technician& th) :employee(th) {
		//基类要用不用赋值？答案是需要，因此要不要给基类也编写复制构造函数？
	/*	name = th.name;
		emNo = th.emNo;
		level = th.level;
		bs_salary = th.bs_salary;
		pf_salary = th.pf_salary;
		salary = th.salary;*/
		//这部分能放在基类中自动调用吗？ 可以 通过:employee

		addSalary_hours = th.addSalary_hours;
		hours = th.hours;
		wk_coefficient = th.wk_coefficient;
	}

};
//销售员
class salesman : public virtual employee
{
public:
	float sale;//销售额
	float perRemuneration;//酬金提取百分比

	salesman(string n, int en, int le, float bssa, float sa, float pr) :employee(n, en, le, bssa)
	{
		sale = sa;
		perRemuneration = pr;
	}

	void pay(int leaveN)
	{
		pf_salary = sale * perRemuneration;
		//假定一个月上22天。
		int onN = 22 - leaveN;
		float per = onN / 22;
		salary = pf_salary * per + bs_salary * per;
	}
	~salesman() {}
};

//经理
class manager : public virtual employee
{
public:
	float bonus;//固定奖金额
	float pf_coefficient;//业绩系数

	manager(string n, int en, int le, float bssa, float b, float pfc) :employee(n, en, le, bssa)
	{
		bonus = b;
		pf_coefficient = pfc;
	}

	void pay(int leaveN)
	{
		pf_salary = bonus * pf_coefficient;
		//假定一个月上22天。
		int onN = 22 - leaveN;
		float per = onN / 22;
		salary = pf_salary * per + bs_salary * per;
	}
	~manager() {}
};

class devel_opermanger :public manager, public technician
{
public:
	devel_opermanger(string n, int en, int le, float bssa, float b, float pfc, float addsh, int h, float wkc)
		:manager(n, en, le, bssa, b, pfc), technician(n, en, le, bssa, addsh, h, wkc), employee(n, en, le, bssa)
	{}
	void pay(int leaveN) {
		pf_salary = (addSalary_hours * hours * wk_coefficient + bonus * pf_coefficient) / 2;
		int onN = 22 - leaveN;
		float per = onN / 22;
		salary = pf_salary * per + bs_salary * per;
	}
};

class salesmanager :public salesman, public manager
{
public:
	salesmanager(string n, int en, int le, float bssa, float b, float pfc, float sa, float pr)
		: manager(n, en, le, bssa, b, pfc), salesman(n, en, le, bssa, sa, pr), employee(n, en, le, bssa)
	{}
	void pay(int leaveN) {
		pf_salary = bonus / 2 + sale * perRemuneration;
		int onN = 22 - leaveN;
		float per = onN / 22;
		salary = pf_salary * per + bs_salary * per;

	}
};
