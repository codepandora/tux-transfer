#ifndef PROGRESS_TRACKER
#define PROGRESS_TRACKER

#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

class ProgressTracker
{

	public:
		ProgressTracker();
		~ProgressTracker();
		static ProgressTracker* getInstance();	// class is singlton
		const char* getTmpFileName( int );	// get tmpfile name of given index
		long getCurrentlyCopyingFileNameIndex( int ); // Get line number from tmpFile of file currently being copied
		long getOffsetToCopyFrom( int );	// get offset till which the curretly file being copied has completed copying
		void putTmpFileName( const char* );	// make new tmpFile name entry for new copyinstance
		void putNextFileNameIndexToCopy( int, long );	// set next file index to be copied after last one completed copying	
		void putOffsetToCopyFrom( int, long );	// update copy progress of current copy process after every successful copy 512kb
		int getCopyInstanceCount();
		bool fileExists( const char* );	// check if given file exists
		int getCopyInstanceSequenceNumber();

	private:
		const char* progressTrackerFile;	// file name to store all copying processes' progress
		bool static instantiated;	// if the class has been instantiated
		static ProgressTracker* progressTrackerPtr;	// pointer holding only object of class
		
		const int tmpFileNameLen, // length of tmpFile name
					lineNumberLen, // length of line number part of record
					lineNumberOffset, // offset of line number part in a record respective to start of record
					offsetStorageLen, 
					offsetStorageOffset; // offset of copied offset part in a record respective to start of record
		int recordLen, numberOfCopyInstances, currentCopyInstanceSequenceNumber;	// each record length in progress recording file
		ifstream fileReader;	// file reading ifstream object 
		ofstream fileWriter;	// file writing ofstream object
		
};

#endif
