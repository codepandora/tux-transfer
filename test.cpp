#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{
	ifstream reader("tmp.tmp", ios::in | ios::binary);
	ofstream writer("tmp.tmp", ios::out | ios::binary);

	writer.write("tmp.lst", 7);
	writer.seekp(12);
	writer.write("tmp2.lst", 8);
	char* str = new char[20];
	reader.seekg(7);
	reader.read(str,8);
	printf("%s",str);
}