#pragma once
#ifndef SHAPE_H_
#define SHAPE_H_
//#include"shapefile.h"
#include"edge.h"
#include<iostream>
#include<vector>


class shape {
	using ptr_shape = std::shared_ptr<shape>;
public:
	virtual double circumference()const = 0;
	virtual double area()const=0;
	virtual void print() const{
		std::cout << "circumference=" << circumference() << std::endl;
		std::cout << "area=" << area() << std::endl;
	}
	virtual bool isvalid()const = 0;

	static const int unknownvalue = -1;
	friend ptr_shape operator&(const ptr_shape& p1, const ptr_shape &p2);
	friend ptr_shape operator|(const ptr_shape& p1, const ptr_shape &p2);
};

class circle :public shape {
private:
	point center_;
	double radius_;
public:
	circle(){}
	circle(point c, double r) :center_(c), radius_(r) {}
	double circumference()const;
	double area()const;
	void print()const;
	bool isvalid()const;
};

class polygon :public shape {
private:
	std::vector<edge>edges_;
public:
	polygon(){}
	polygon(std::vector<point>points_);
	double circumference()const;
	double area()const;
	void print()const;
	bool isvalid()const;
};
#endif 

