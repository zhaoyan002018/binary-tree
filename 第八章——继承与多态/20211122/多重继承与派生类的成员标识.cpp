//圆和高通过多重继承派生出圆锥
#include<iostream>
#include<cmath>
using namespace std;
class Cicle {
protected:
	float x, y, r;

public:
	Cicle(float a = 0, float b = 0, float R = 0) { x = a; y = b; r = R; }
};

class Line {
protected:
	float High;
public:
	Line(float a = 0) { High = a; }
};

class Cone :public Cicle, public Line
{
	Cone(float a, float b, float R, float h) :Cicle(a, b, R), Line(h) {}
};
