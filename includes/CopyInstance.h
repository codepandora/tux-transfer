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
#include<boost/progress.hpp>
#include<boost/timer.hpp>
#include "../src/ProgressTracker.cpp"
#include "threadPool.h"
#define NEWDIR ( dir* ) malloc( sizeof( dir ) )
#define NEWFILE ( file* ) malloc( sizeof( file ) )
#define CHUNK_SIZE 512
using namespace std;


class copyInstance
{		

		char* source, pathToSource, command;
		string sourcePath, tmpFileName, destination;
		char buffer1[CHUNK_SIZE], buffer2[CHUNK_SIZE];
		int sourceType, i;
		unsigned long totalBytesToCopy, currentFileSize, buf1Position, buf2Position, tmpFileLineCounter;
		bool isBuffer1Free, isBuffer2Free, isBuf1BeingWritten,isBuf2BeingWritten, fileNotCompleted;
		fstream readerStream;
		fstream writerStream1,writerStream2;
		ThreadPool* pool, *readerPool, *writerPool, *completionUpdater;
		ProgressTracker* progressTracker;
		boost::progress_display* progressBar;
		void initializeSourceDirStructure();
		bool isDir( const char* );
		bool isFile( const char*, unsigned long* );
		void copyWork();
		void testPrint();
		void reader();
		void writer();

		//template<typename string>
		string getPathFromSource( string );
		//template<typename string>

		string generateTempFileName();
		void testCopy();	

	public:
		copyInstance( const char*[], int, const char* );

};

#endif

