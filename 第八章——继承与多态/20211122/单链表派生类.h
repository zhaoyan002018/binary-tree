#pragma once
#include<iostream>
using namespace std;

//将数据域改为指向虚基类的指针。
class InfoObject
{
public:
	InfoObject() { cout << "info基类构造" << endl; }
	virtual ~InfoObject() { cout << "info基类析构" << endl; }
	virtual void printInfo() = 0;
	//如果有设置info的虚函数，参数应该是在运行时才能确定，该如何实现呢？
	//virtual void setInfo(InfoObject*) = 0;
};

class IntInfo :public InfoObject
{
	int info;
public:
	IntInfo() :InfoObject() { cout << "intInfo默认构造" << endl; };
	IntInfo(int i) :InfoObject() { info = i; cout << "intInfo构造" << endl; };
	void printInfo() { cout << info << "\t"; }
	void setInfo(int inf) { info = inf; }
	~IntInfo() { cout << "intinfo析构" << endl; }
};

class StringInfo :public InfoObject
{
	string info;
public:
	StringInfo() :InfoObject() { cout << "StringInfo默认构造" << endl; };
	StringInfo(int i) :InfoObject() { info = i; cout << "StringInfo构造" << endl; };
	void printInfo() { cout << info << "\t"; }
	void setInfo(string inf) { info = inf; }
	~StringInfo() { cout << "StringInfo析构" << endl; }
};



class Node
{
	InfoObject* info;
	Node* link;
public:
	Node() {
		info = NULL;
		link = NULL;
	}
	Node(InfoObject* pinfo)
	{
		info = pinfo;
		link = NULL;
	}
	~Node() {}

	friend class List;
};

class List
{
	Node* head, * tail;
public:
	List() {
		head = tail = new Node();
	}
	~List()
	{
		clearList();
		delete head;
	}
	Node* createNode(InfoObject* info) {
		Node* node = new Node(info);
		return node;
	}
	Node* insertFront(InfoObject* info);
	Node* insertRear(InfoObject* info);
	int getLen();
	void deleteNode(Node* pnode);
	void print();
	void clearList();

};

Node* List::insertFront(InfoObject* info)
{
	Node* node = createNode(info);
	node->link = head->link;
	head->link = node;
	if (!tail) tail = node;
	return node;
}

Node* List::insertRear(InfoObject* info)
{
	Node* node = createNode(info);

	tail->link = node;
	tail = node;

	return node;
}

void List::print()
{
	Node* pnode = head->link;
	while (pnode)
	{
		pnode->info->printInfo();
		pnode = pnode->link;
	}
}

void List::clearList()
{
	while (head->link)
	{
		Node* tmp = head->link;
		head->link = head->link->link;
		delete tmp;

	}
	tail = head;
}
