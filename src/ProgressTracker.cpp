#include "../includes/ProgressTracker.h"
#include<fstream>
const char* ProgressTracker::progressTrackerFile = "../tmpFileList.lst";

bool ProgressTracker::instantiated = false;

ifstream ProgressTracker::fileReader( progressTrackerFile, ios::binary );
ofstream ProgressTracker::fileWriter( progressTrackerFile, ios::binary );
//int ProgressTracker::numberOfCopyInstances = 0;

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
	numberOfCopyInstances = 0;
	if(! fileExists( progressTrackerFile ) )
	{
		ofstream makeFile( progressTrackerFile );
		makeFile.close();
	}

	//fileReader.open( progressTrackerFile, ios::binary );
	cout<< "opened in read mode"<<endl;
	//fileWriter.open( progressTrackerFile, ios::binary );
	cout<< "opened in write mode"<<endl;
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

long ProgressTracker::getCurrentlyCopyingFileNameIndex( int index )
{
	long fileNameLineNumber = 0;
	fileReader.seekg( (index * recordLen) + lineNumberOffset );
	fileReader.read( ( char* ) &fileNameLineNumber, sizeof( fileNameLineNumber ) );
	return fileNameLineNumber;
}
	
long ProgressTracker::getOffsetToCopyFrom( int index )
{
	long offsetToCopyFrom = 0;
	fileReader.seekg( (index * recordLen) + offsetStorageOffset );
	fileReader.read( ( char* ) &offsetToCopyFrom, sizeof( offsetToCopyFrom ) );
	return offsetToCopyFrom;
}

void ProgressTracker::putTmpFileName( const char* fileName )
{
	//ofstream fileWriter( progressTrackerFile );
	fileWriter.seekp( numberOfCopyInstances * recordLen );
	cout<< "writing" <<fileName;
	fileWriter.write( fileName, 11 );
	numberOfCopyInstances++;
}

void ProgressTracker::putNextFileNameIndexToCopy( int index, long fileNameLineNumber )
{
	fileWriter.seekp( (index * recordLen) + lineNumberOffset );
	fileWriter.write( ( const char* ) &fileNameLineNumber, 8 );	
}

void ProgressTracker::putOffsetToCopyFrom( int index, long offsetToCopyFrom )
{
	fileWriter.seekp( (index * recordLen) + offsetStorageOffset );
	fileWriter.write( ( const char* ) &offsetToCopyFrom, 8 );
}


ProgressTracker::~ProgressTracker()
{
	fileReader.close();
	fileWriter.close();
}
int main(void)
{
	ProgressTracker* tracker = ProgressTracker::getInstance();
	tracker->putTmpFileName( "tmp.list" );

	tracker->putNextFileNameIndexToCopy( 0, 1432 );

	cout<< endl<<"fileName - "<<tracker->getTmpFileName( 0 )<<endl;
	return 1;
}
