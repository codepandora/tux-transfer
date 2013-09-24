#ifndef PROGRESS_TRACKER
#define PROGRESS_TRACKER

#include<iostream>
#include<string.h>
#include<fstream>

struct record
{
	char name[10];
	unsigned long offset;
};


using namespace std;

class ProgressTracker
{
	const static char* progressTrackerFile;
	static bool instantiated;
	static ProgressTracker* progressTrackerPtr;
	static bool fileExists( const char* );
	const int tmpFileNameLen;
	const int lineNumberLen;
	const int lineNumberOffset;
	const int offsetStorageLen;
	const int offsetStorageOffset;
	int recordLen;	
	ifstream fileReader;
	ofstream fileWriter;
	ProgressTracker();
	~ProgressTracker();

	public:
		static ProgressTracker* getInstance();
		const char* getTmpFileName( int );
		long getNextFileNameIndexToCopy( int );
		long getOffsetToCopyFrom( int );
		void putTmpFileName( int, const char* );
		void putNextFileNameIndexToCopy( int, long );
		void putOffsetToCopyFrom( int, long );
};

#endif
