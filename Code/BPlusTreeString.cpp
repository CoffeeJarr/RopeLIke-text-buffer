#include "BPlusTreeString.h"
#include <iostream>
#include <cstring>
using namespace std;

BPlusTreeString::BPlusTreeString(const string& filename) {
	// read from the text file line by line
	ifstream read_file;
	read_file.open("test.txt", ios::binary);
	string line;
	while(getline(read_file, line))
	{
		cout<<"line:"<<line.c_str()<<endl;
	}

}












































