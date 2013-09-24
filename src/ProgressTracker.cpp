#include "../includes/ProgressTracker.h"

const char* ProgressTracker::progressTrackerFile = "../tmpFileList.lst";

bool ProgressTracker::instantiated = true;

ProgressTracker* ProgressTracker::progressTrackerPtr = NULL;

ProgressTracker* ProgressTracker::getInstance()
{

	if(! instantiated )
	{
		progressTrackerPtr = new ProgressTracker();
		return progressTrackerPtr;
	}
	return progressTrackerPtr;
}

ProgressTracker::ProgressTracker(): tmpFileNameLen( 11 ), lineNumberLen( 8 ), lineNumberOffset( 11 ), offsetStorageLen( 8 ), offsetStorageOffset( 19 )
{
	recordLen = tmpFileNameLen + lineNumberLen + offsetStorageLen;	
	if(! fileExists( progressTrackerFile ) )
	{
		ofstream makeFile( progressTrackerFile );
		makeFile.close();
	}

	fileReader.open( progressTrackerFile, ios::binary );
	fileWriter.open( progressTrackerFile, ios::binary );

}

bool ProgressTracker::fileExists( const char* fileName)
{
	ifstream tmpHandle( fileName );
	if( tmpHandle )
		return true;
	else
		return false;
}

const char* ProgressTracker::getTmpFileName( int index )
{
	char* fileName = new char[tmpFileNameLen + 1];
	fileReader.seekg( (index*recordLen) );
	fileReader.read( fileName, tmpFileNameLen );
	*(fileName+11) = '\0';
	return fileName;

}

long ProgressTracker::getNextFileNameIndexToCopy( int index )
{
	long fileNameLineNumber = 0;
	fileReader.seekg( (index * recordLen) + lineNumberOffset );
	fileReader.read( ( char* ) fileNameLineNumber, sizeof( fileNameLineNumber ) );
	return fileNameLineNumber;
}
	
long ProgressTracker::getOffsetToCopyFrom( int index )
{
	long offsetToCopyFrom = 0;
	fileReader.seekg( (index * recordLen) + offsetStorageOffset );
	fileReader.read( ( char* ) offsetToCopyFrom, sizeof( offsetToCopyFrom ) );
	return offsetToCopyFrom;
}

void ProgressTracker::putTmpFileName( int index, const char* fileName )
{

}

void ProgressTracker::putNextFileNameIndexToCopy( int index, long fileNameLineNumber )
{

}

void ProgressTracker::putOffsetToCopyFrom( int index, long offsetToCopyFrom )
{

}


ProgressTracker::~ProgressTracker()
{
	fileReader.close();
	fileWriter.close();
}
int main(void)
{
	ProgressTracker* tracker = ProgressTracker::getInstance();
	return 1;
}
