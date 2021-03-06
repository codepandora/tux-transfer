#ifndef PROGRESS_TRACKER
#define PROGRESS_TRACKER

#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

struct copyInstanceRecord{
	char name[12];
	unsigned long lineNumber;
	bool completed;
};

class ProgressTracker
{

	public:
		ProgressTracker();
		~ProgressTracker();
		const char* getTmpFileName( );	// get tmpfile name of given index
		long getCurrentlyCopyingFileNameIndex( ); // Get line number from tmpFile of file currently being copied
		long getOffsetToCopyFrom(  );	// get offset till which the curretly file being copied has completed copying
		void putTmpFileName( const char* );	// make new tmpFile name entry for new copyinstance
		void putNextFileNameIndexToCopy( long );	// set next file index to be copied after last one completed copying	
		void putOffsetToCopyFrom( long );	// update copy progress of current copy process after every successful copy 512kb
		int getCopyInstanceCount();
		bool fileExists( const char* );	// check if given file exists
		int getCopyInstanceSequenceNumber();

	private:
		const char* progressTrackerFile;	// file name to store all copying processes' progress
		bool static instantiated;	// if the class has been instantiated
		
		const int tmpFileNameLen, // length of tmpFile name
					lineNumberLen, // length of line number part of record
					lineNumberOffset, // offset of line number part in a record respective to start of record
					offsetStorageLen, 
					offsetStorageOffset; // offset of copied offset part in a record respective to start of record
		int recordLen, numberOfCopyInstances, currentCopyInstanceSequenceNumber;	// each record length in progress recording file
		ifstream fileReader;	// file reading ifstream object 
		fstream fileWriter;	// file writing ofstream object
		
};

#endif
