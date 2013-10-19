#include<iostream>
#include<sstream>
#include<string>
#include<fstream>

using namespace std;

int main(void)
{

	fstream read("tmpFileList.lst", ios::in | ios::out );

	string num;
	string fname("tmp000.tmp");
	long n = 23123;
	stringstream str;
	str << n;
	str >> num;
	cout << num;
	read.write(fname.c_str(), fname.length());
	read.write(num.c_str(), num.length());
	read.close();

	read.open("tmpFileList.lst", ios::in | ios::out );
	read.seekp(10);
	getline(read, fname);
	cout<< fname;
	return 1;
}