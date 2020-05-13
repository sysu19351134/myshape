#pragma once
#pragma once
#ifndef EDGE_H_
#define EDGE_H
#include<iostream>
#include<math.h>
class point {
private:
	double x;
	double y;
public:
	point() { x = 0; y = 0; }
	point(double a, double b) :x(a), y(b) {}
	void print() const { std::cout << "(" << x << "," << y << ")"; }
	double getx()const { return x; }
	double gety()const { return y; }
};
class edge {
private:
	point a;
	point b;
public:
	edge() {}
	edge(point a, point b) :a(a), b(b) {}
	point geta()const { return a; }
	point getb()const { return b; }
	double length()const {
		return sqrt(a.getx() * a.gety() + b.getx() * b.gety());
	}
	void print()const {
		double m = length();
		std::cout << "¶Ëµã:";
		a.print();
		b.print();
		std::cout << "±ß³¤:" << m << std::endl;
	}
};

#endif