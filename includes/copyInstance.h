
#ifndef COPYINSTANCE
#define COPYINSTANCE

#include<iostream>
#include<sys/stat.h>
#include<string.h>
#include<malloc.h>
#include<dirent.h>
#include<stdlib.h>
#define NEWDIR ( dir* ) malloc( sizeof( dir ) )
#define NEWFILE ( file* ) malloc( sizeof( file ) )

using namespace std;

struct dir
{
	char* dirPath;
	char* dirName;
	struct dir* subDirs;
	struct file* files;
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
	file* tmpFilePtr;
	dir*  tmpDirPtr;
	char* command;
	void initializeSourceDirStructure();
	void mapSubFileStructure(dir*);
	bool isDir( const char* );
	bool isFile( const char*, long* );
	
	public:
		
		copyInstance( const char*,  const char* );

};

#endif
