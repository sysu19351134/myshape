#include "shapefile.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

shapefile::shapefile(ifstream& is) {
	string s;
	while (getline(is, s)) {
		read(s);
	}
}

void shapefile::read(string s)
{
	if (s[0] == 'P' && s[1] != 'o') {
		int pos = s.find(':');
		string name = s.substr(0, pos);
		int leftbracket = s.find('(');
		int douhao = s.find(',');
		int rightbracket = s.find(')');
		string x = s.substr(leftbracket + 1, douhao);
		string y = s.substr(douhao + 1, rightbracket);
		int xdou = stoi(x), ydou = stoi(y);
		m[name] = point(xdou, ydou);
	}
	else if (s[0] == 'C') {
		int maohao = s.find(':');
		int douhao = s.find(',');
		string name = s.substr(maohao + 2, douhao-maohao-2);
		string p = s.substr(douhao + 1);
		double r = stod(p);
		ptr_shape c(new circle(m[name], r));
		shapes_.push_back(c);
	}
	else if (s[0] == 'P' && s[1] == 'o') {
		int maohao = s.find(':');
		int begin = maohao + 2;
		vector<point> points;
		while (1) {
			string::size_type douhao = s.find(',', begin);
			string pname = s.substr(begin, douhao-begin);
			points.push_back(m[pname]);
			if (douhao == string::npos)
				break;
			begin = douhao+2;
		}
		ptr_shape p(new polygon(points));
		shapes_.push_back(p);
	}
	
}

void shapefile::generate()
{
	for (int i = 0; i < shapes_.size(); i++) {
		for (int j = i + 1; j < shapes_.size(); j++) {
			compositeshapes_.push_back(shapes_[i] & shapes_[j]);
			compositeshapes_.push_back(shapes_[i] | shapes_[j]);
		}
	}
}

void shapefile::print()
{
	int i = 0;
	for (i = 0; i < shapes_.size(); i++) {
		shapes_[i]->print();
	}
	generate();
	for (i = 0; i < compositeshapes_.size(); i++)
	{
		compositeshapes_[i]->print();
	}
}

