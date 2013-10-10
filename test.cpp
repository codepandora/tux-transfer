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
	writer.close();
	char* str = new char[20];
	reader.seekg(12);
	reader.read(str,7);
	//writer.seekp(1);

	//writer.write("update.lst",10);
	//reader.read(str,10);
	printf("%s",str);
}