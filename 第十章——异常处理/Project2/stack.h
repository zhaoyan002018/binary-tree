#pragma once
#include<iostream>
using namespace std;
template<typename T> class pushOnFull
{
	T _value;
public:
	pushOnFull(T i) { _value = i; }
	T value() { return _value; }
	void print() { cerr << "栈满," << value() << "未压入栈" << endl; }
};

template<typename T>class popOnEmpty
{
public:
	void print() { cerr << "栈已空，无法出栈" << endl; }
};



template<typename T>class Stack
{
	int top;
	T* elements;
	int maxSize;
public:
	Stack(int = 20);
	~Stack() { delete[]elements; }
	void Push(const T& data);
	T Pop();
	T GetElem(int i) { return elements[i]; }
	void MakeEmpty() { top == -1; }
	bool IsEmpty()const { return top == -1; }
	bool IsFull()const { return top == maxSize - 1; }
	void PrintStack();

};
template<typename T> Stack<T>::Stack(int maxs)
{
	maxSize = maxs;
	top = -1;
	elements = new T[maxSize];
}
template<typename T> void Stack<T>::PrintStack()
{
	for (int i = 0; i < top; i++)
		cout << elements[i] << '\t';
	cout << endl;
}
template<typename T> void Stack<T>::Push(const T& data)
{
	if (IsFull())
		throw pushOnFull<T>(data);//无名对象
	elements[++top] = data;
}
template<typename T> T Stack<T>::Pop()
{
	if (IsEmpty())
		throw popOnEmpty<T>();
	return elements[top--];
}
