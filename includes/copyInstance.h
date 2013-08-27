
#ifndef COPYINSTANCE
#define COPYINSTANCE

#include<iostream>
#include<sys/stat.h>
#include<string.h>
#include<malloc.h>
#include<dirent.h>
using namespace std;

struct dir
{
	char* dirPath;
	char* direName;
	struct dir* subdirs;
	struct dir* files;
	struct dir* nextDir;
};

struct file
{
	char* filePath;
	char* fileName;
	long fileSize;
	char* type;
	struct file* nextFile;
};

class copyInstance
{	
	char* source;
	char* destination;
	char* pathToSource;
	int sourceType;
	long totalBytesToCopy;
	dir* dirHeadPtr;
	file* fileHeadPtr;
	const int IS_FILE;
	const int IS_DIR;

	void initializeSourceDirStructure();


	bool is_dir( const char* );
	


	bool is_file( const char* );
	
	public:
		
		copyInstance( const char*,  const char* );

};

#endif
