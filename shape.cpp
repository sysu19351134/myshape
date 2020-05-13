#include "shape.h"
#include "shape.h"
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
double circle::circumference()const
{
	return radius_ * 2 * 3.1415926;
}
double circle::area()const
{
	return  radius_ * radius_ * 3.1415926;
}
void circle::print()const {
	cout << "半径：" << radius_ << endl;
	cout << "圆心:";
	center_.print();
	cout << "面积" << area() << endl;
}
double polygon::circumference()const
{
	double x = 0;
	for (auto a : edges_)
	{
		x = x + a.length();

	}
	return x;
}
double polygon::area()const
{
	int l = edges_.size();
	double x = 0, y = 0;
	for (vector<edge>::size_type i = 0; i < edges_.size() - 1; i++)
		x += edges_[i].geta().getx() * edges_[i + 1].geta().gety() - edges_[i + 1].geta().getx() - edges_[i].geta().gety();
	y = abs(x + edges_[edges_.size() - 1].geta().getx() * edges_[edges_.size() - 1].geta().gety() - edges_[0].geta().getx() * edges_[edges_.size() - 1].geta().gety())/2;
	return y;
}
bool circle::isvalid()const
{
	return radius_ > 0;

}
polygon::polygon(vector<point>points_) {
	int i;
	for (i = 0; i < points_.size() - 1; i++)
	{
		edge a(points_[i], points_[i + 1]);
		edges_.push_back(a);
	}
	edge b(points_[points_.size() - 1], points_[0]);
	edges_.push_back(b);
}

bool polygon::isvalid() const
{
	if (edges_.size() == 0)
		return false;
	else
		return true;
}

void polygon::print() const
{
	for (int i = 0; i < edges_.size(); i++)
	{
		cout << "第" << i+1 << "条边：";
		edges_[i].print();
	}
}
using ptr_shape = std::shared_ptr<shape>;
ptr_shape operator &(const ptr_shape& p1, const ptr_shape& p2)//bb
{
	if (typeid(*p1) != typeid(*p2)) {
		ptr_shape new_shape(new polygon());
		return new_shape;
	}
	else{
		return p1;//这里我写不出来就返回前一个图形了
	}
}
ptr_shape operator |(const ptr_shape& p1, const ptr_shape& p2)
{
	if (typeid(*p1) != typeid(*p2)) {
		ptr_shape new_shape(new polygon());
		return new_shape;
	}
	else {
		return p1;//这里我写不出来就返回前一个图形了
	}
}