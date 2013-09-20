
#ifndef CopyInstance
#define CopyInstance

#include<iostream>
#include<sys/stat.h>
#include<string.h>
#include<malloc.h>
#include<dirent.h>
#include<stdlib.h>
#include<fstream>
#include<boost/thread.hpp>
#include<boost/thread/thread.hpp>
#define NEWDIR ( dir* ) malloc( sizeof( dir ) )
#define NEWFILE ( file* ) malloc( sizeof( file ) )

using namespace std;


class copyInstance
{		

		char* source, destination, pathToSource, command;
		char buffer[512];
		int sourceType;
		long totalBytesToCopy;
		void initializeSourceDirStructure();
		bool isDir( const char* );
		bool isFile( const char*, long* );
		void copyWork( string, string );
		void testPrint();
		void reader();
		void writer();
		ifstream readerStream;
		ofstream writerStream;

	public:
		copyInstance( const char*[], int, const char* );

};

#endif

