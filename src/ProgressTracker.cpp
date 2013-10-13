#include "../includes/ProgressTracker.h"
#include<fstream>

bool ProgressTracker::instantiated = false;

//ifstream ProgressTracker::fileReader( progressTrackerFile, ios::binary );
//ofstream ProgressTracker::fileWriter( progressTrackerFile, ios::binary );
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
	progressTrackerFile = "../tmpFileList.lst";
	fileWriter.open(progressTrackerFile, ios::in | ios::out | ios::binary );
	fileReader.open(progressTrackerFile, ios::in | ios::binary );
	recordLen = tmpFileNameLen + lineNumberLen;	
	cout<< endl<<"recordlength "<<recordLen<<endl;
	numberOfCopyInstances = 0;
	if(! fileExists( progressTrackerFile ) )
	{
		ofstream makeFile( progressTrackerFile );
		makeFile.close();
	}

	
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
	//fileReader.open( progressTrackerFile, ios::binary );
	char* fileName = new char[tmpFileNameLen + 1];
	if( index>0 )
		fileReader.seekg( (index*recordLen) );
	fileReader.read( fileName, tmpFileNameLen );
	//fileReader.close();
	*(fileName+11) = '\0';
	return fileName;

}

long ProgressTracker::getCurrentlyCopyingFileNameIndex( int index )
{
	//fileReader.open( progressTrackerFile, ios::binary );
	long fileNameLineNumber = 0;
	if( index>0 )
		fileReader.seekg( (index * recordLen) + lineNumberOffset );
	fileReader.read( reinterpret_cast<char *>( &fileNameLineNumber ), sizeof( fileNameLineNumber ) );
	//fileNameLineNumber = ( long ) tmp;
	//fileReader.close();
	return fileNameLineNumber;
}
	
long ProgressTracker::getOffsetToCopyFrom( int index )
{
	//fileReader.open( progressTrackerFile, ios::binary );
	long offsetToCopyFrom = 0;
	fileReader.seekg( (index * recordLen) + offsetStorageOffset );
	fileReader.read( reinterpret_cast<char *>( &offsetToCopyFrom ), sizeof( offsetToCopyFrom ) );
	//fileReader.close();
	return offsetToCopyFrom;
}

void ProgressTracker::putTmpFileName( const char* fileName )
{
 	//fileWriter.open( progressTrackerFile,ios::in |  ios::out | ios::binary );
	fileWriter.seekp( numberOfCopyInstances * recordLen );
	
	fileWriter.write( fileName, tmpFileNameLen );
	fileWriter.flush();
	//fileWriter.close();

	//fileWriter.open( progressTrackerFile, ios::binary );
	cout<< "writing" <<fileName<< " instance number"<< numberOfCopyInstances;
	numberOfCopyInstances++;
}

void ProgressTracker::putNextFileNameIndexToCopy( int index, long fileNameLineNumber )
{
	//fileWriter.open( progressTrackerFile, ios::in | ios::out | ios::binary );
	fileWriter.seekp( (index * recordLen) + lineNumberOffset );
	fileWriter.write( reinterpret_cast<char*>( &fileNameLineNumber ), lineNumberLen );
	fileWriter.flush();
	//fileWriter.close();
	//fileWriter.open( progressTrackerFile, ios::binary );	
}

void ProgressTracker::putOffsetToCopyFrom( int index, long offsetToCopyFrom )
{	
	//fileWriter.open( progressTrackerFile, ios::in | ios::out | ios::binary );
	fileWriter.seekp( (index * recordLen) + offsetStorageOffset );
	fileWriter.write( reinterpret_cast<char*>( &offsetToCopyFrom ), offsetStorageLen );
	fileWriter.flush();
	//fileWriter.close();
	//fileWriter.open( progressTrackerFile, ios::binary );	
}

int ProgressTracker::getCopyInstanceCount()
{
	ifstream recordCounterStream( progressTrackerFile, ios::in | ios::binary );
	recordCounterStream.seekg( 0, recordCounterStream.end );
	cout<< endl<<recordCounterStream.tellg()<<endl;
	return ( ( recordCounterStream.tellg()/( recordLen - 1 ) ) );
}


int ProgressTracker::getCopyInstanceSequenceNumber()
{
	return currentCopyInstanceSequenceNumber;
}


ProgressTracker::~ProgressTracker()
{
	fileReader.close();
	fileWriter.close();
}



int main(void)
{
	char tmp;
	ProgressTracker* tracker = new ProgressTracker();
	tracker->putTmpFileName( "231tmp.list" );
	//cin>>tmp;
	tracker->putTmpFileName( "456tmp.list" );
	//tracker->putTmpFileName( "656tmp.list" );
	//tracker->putTmpFileName( "856tmp.list" );
	//cin>>tmp;
	//tracker->putNextFileNameIndexToCopy( 2, (long)342);
	//tracker->putOffsetToCopyFrom(2,(long)534534);
	//cin>>tmp;
	//cout<< tracker->getTmpFileName( 0 );
	//long newNum;
	//cin>>newNum;
	//long newNum = 4;
	//tracker->putNextFileNameIndexToCopy( 0, newNum);
	//cout<< endl<<"fileName - "<< endl<< tracker->getTmpFileName( 0 );
	//printf("\n %s %d %d",tracker->getTmpFileName( 2 ),(int)tracker->getCurrentlyCopyingFileNameIndex( 2 ), (int)tracker->getOffsetToCopyFrom(2));
	cout<< endl<<"number of records" << tracker->getCopyInstanceCount();
	return 1;
}
