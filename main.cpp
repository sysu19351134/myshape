#include <iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include"shape.h"
#include"shapefile.h"
using namespace std;



using ptr_shape = std::shared_ptr<shape>;

int main()
{
	ifstream is;
	is.open("shape.txt");
	shapefile file(is);
	auto  m = file.m;
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first;
		it->second.print();
		cout << endl;
	}
	
	file.print();

}


