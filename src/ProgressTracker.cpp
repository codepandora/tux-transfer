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
	fileReader.read( reinterpret_cast<char *>( &fileNameLineNumber ), sizeof( fileNameLineNumber ) );
	//fileNameLineNumber = ( long ) tmp;
	return fileNameLineNumber;
}
	
long ProgressTracker::getOffsetToCopyFrom( int index )
{
	long offsetToCopyFrom = 0;
	fileReader.seekg( (index * recordLen) + offsetStorageOffset );
	fileReader.read( reinterpret_cast<char *>( &offsetToCopyFrom ), sizeof( offsetToCopyFrom ) );
	return offsetToCopyFrom;
}

void ProgressTracker::putTmpFileName( const char* fileName )
{
	//ofstream fileWriter( progressTrackerFile );
	fileWriter.seekp( numberOfCopyInstances * recordLen );
	
	fileWriter.write( fileName, tmpFileNameLen );
	cout<< "writing" <<fileName<< " instance number"<< numberOfCopyInstances;
	numberOfCopyInstances++;
}

void ProgressTracker::putNextFileNameIndexToCopy( int index, long fileNameLineNumber )
{
	fileWriter.seekp( (index * recordLen) + lineNumberOffset );
	fileWriter.write( reinterpret_cast<char*>( &fileNameLineNumber ), lineNumberLen );	
}

void ProgressTracker::putOffsetToCopyFrom( int index, long offsetToCopyFrom )
{
	fileWriter.seekp( (index * recordLen) + offsetStorageOffset );
	fileWriter.write( reinterpret_cast<char*>( &offsetToCopyFrom ), offsetStorageLen );
}


ProgressTracker::~ProgressTracker()
{
	fileReader.close();
	fileWriter.close();
}


int main(void)
{
	char tmp;
	ProgressTracker* tracker = ProgressTracker::getInstance();
	tracker->putTmpFileName( "231tmp.list" );
	cin>>tmp;
	tracker->putTmpFileName( "456tmp.list" );
	//cin>>tmp;
	tracker->putNextFileNameIndexToCopy( 0, (long)342);
	//cin>>tmp;
	//cout<< tracker->getTmpFileName( 0 );
	//long newNum;
	//cin>>newNum;
	//tracker->putNextFileNameIndexToCopy( 0, newNum);
	cout<< endl<<"fileName - "<< endl<< tracker->getTmpFileName( 1 );
	printf("%s %d",tracker->getTmpFileName( 0 ),tracker->getCurrentlyCopyingFileNameIndex( 0 ));
	return 1;
}
