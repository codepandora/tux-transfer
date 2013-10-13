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
#include "../src/ProgressTracker.cpp"
#include "threadPool.h"
#define NEWDIR ( dir* ) malloc( sizeof( dir ) )
#define NEWFILE ( file* ) malloc( sizeof( file ) )
#define CHUNK_SIZE 512
using namespace std;


class copyInstance
{		

		char* source, destination, pathToSource, command;
		char buffer1[CHUNK_SIZE], buffer2[CHUNK_SIZE];
		int sourceType;
		unsigned long totalBytesToCopy, buf1Position, buf2Position;
		bool isBuffer1Free, isBuffer2Free, isBuf1BeingWritten,isBuf2BeingWritten, fileNotCompleted;
		ifstream readerStream;
		ofstream writerStream1,writerStream2;
		ThreadPool *pool;
		ProgressTracker *progressTracker;
		void initializeSourceDirStructure();
		bool isDir( const char* );
		bool isFile( const char*, long* );
		void copyWork( string, string );
		void testPrint();
		void reader();
		void writer();
		string getPathFromSource( string );
		string generateTempFileName();

	public:
		copyInstance( const char*[], int, const char* );

};

#endif

