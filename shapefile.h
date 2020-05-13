#pragma once
#ifndef SHAPEFILE_H_
#define SHAPEFILE_H_

#include<iostream>
#include<map>
#include"shape.h"
class shapefile
{
	using ptr_shape = std::shared_ptr<shape>;
	public:
		shapefile(std::ifstream&);
		void generate();
		void print();
		std::vector<ptr_shape> shapes_;
		std::vector<ptr_shape> compositeshapes_;
		void read(std::string s);
		std::map<std::string, point> m;
};

#endif 