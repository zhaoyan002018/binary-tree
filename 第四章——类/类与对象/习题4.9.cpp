#include<iostream>
using namespace std;


class RMB
{
public:
	RMB(int a, int b, int c);
	~RMB();
	operator float();

private:
	int yuan;
	int jiao;
	int fen;
};

RMB::RMB(int a = 0, int b = 0, int c = 0)
{
	yuan = a;
	jiao = b;
	fen = c;
}

RMB::~RMB()
{
}

RMB::operator float()
{
	float result;
	result = yuan + float(jiao * 0.1) + float(fen * 0.01);
	return result;
}

int main()
{
	RMB rmb(1, 2, 5);
	cout << float(rmb) << endl;
}
