#include "../includes/ProgressTracker.h"
#include<fstream>

bool ProgressTracker::instantiated = false;

//ifstream ProgressTracker::this->fileReader( this->progressTrackerFile, ios::binary );
//ofstream ProgressTracker::this->fileWriter( this->progressTrackerFile, ios::binary );
//int ProgressTracker::this->numberOfCopyInstances = 0;

	

ProgressTracker::ProgressTracker(): tmpFileNameLen( 11 ), lineNumberLen( 8 ), lineNumberOffset( 11 ), offsetStorageLen( 8 ), offsetStorageOffset( 19 )
{
	progressTrackerFile = "tmpFileList.lst";
	if(! fileExists( progressTrackerFile ) )
	{
		ofstream makeFile( progressTrackerFile );
		makeFile.close();
	}

	fileWriter.open(progressTrackerFile, ios::in | ios::out | ios::binary );
	fileReader.open(progressTrackerFile, ios::in | ios::binary );
	recordLen = tmpFileNameLen + lineNumberLen;	
	cout<< endl<<"recordlength "<<recordLen<<endl;
	numberOfCopyInstances = getCopyInstanceCount();
	cout<< "current copy instance count" << numberOfCopyInstances<<endl;
	
	
}

bool ProgressTracker::fileExists( const char* fileName)
{
	ifstream tmpHandle( fileName );
	if( tmpHandle )
		return true;
	else
		return false;
}

const char* ProgressTracker::getTmpFileName()
{

	this->fileReader.seekg( ( this->currentCopyInstanceSequenceNumber * sizeof( copyInstanceRecord ) ) );
	cout<<endl<<" reading from "<< this->fileReader.tellg() << " " << this->currentCopyInstanceSequenceNumber << endl;
	copyInstanceRecord tmpRecord;
	this->fileReader.read((char*)&tmpRecord, sizeof( copyInstanceRecord ) );
	string name(tmpRecord.name);
	return name.c_str();
}

long ProgressTracker::getCurrentlyCopyingFileNameIndex()
{
	this->fileReader.seekg( ( this->currentCopyInstanceSequenceNumber * sizeof( copyInstanceRecord ) ) );
	//cout<<endl<<" reading from "<< this->fileReader.tellg() << " " << this->currentCopyInstanceSequenceNumber << endl;
	copyInstanceRecord tmpRecord;
	this->fileReader.read((char*)&tmpRecord, sizeof( copyInstanceRecord ) );
	return tmpRecord.lineNumber;
}
	
long ProgressTracker::getOffsetToCopyFrom()
{
	//this->fileReader.open( this->progressTrackerFile, ios::binary );
	long offsetToCopyFrom = 0;
	this->fileReader.seekg( ( this->currentCopyInstanceSequenceNumber * recordLen ) + offsetStorageOffset );
	this->fileReader.read( reinterpret_cast<char *>( &offsetToCopyFrom ), sizeof( offsetToCopyFrom ) );
	//this->fileReader.close();
	return offsetToCopyFrom;
}

void ProgressTracker::putTmpFileName( const char* fileName )
{
	copyInstanceRecord record;
	strcpy(record.name, fileName);
 	//this->fileWriter.open( this->progressTrackerFile,ios::in |  ios::out | ios::binary );
	int lastCount = getCopyInstanceCount();
	this->currentCopyInstanceSequenceNumber = lastCount;
	this->fileWriter.seekp( lastCount * sizeof( copyInstanceRecord ) ); 
	cout<< endl << this->fileWriter.tellp() <<endl<< sizeof( copyInstanceRecord );
	this->fileWriter.write( ( char* )&record, sizeof( copyInstanceRecord ) );
	//this->fileWriter.write( "\0\n0\0\n", 5 );
	this->fileWriter.flush();
	//this->fileWriter.close();

	//this->fileWriter.open( this->progressTrackerFile, ios::binary );
	cout<< endl << "writing" <<fileName<< " instance number"<< this->currentCopyInstanceSequenceNumber;
	
	this->numberOfCopyInstances++;

}

void ProgressTracker::putNextFileNameIndexToCopy( long fileNameLineNumber )
{
	this->fileReader.seekg( ( this->currentCopyInstanceSequenceNumber * sizeof( copyInstanceRecord ) ) );
	cout<<endl<<" reading from "<< this->fileReader.tellg() << " " << this->currentCopyInstanceSequenceNumber << endl;
	copyInstanceRecord tmpRecord;
	this->fileReader.read((char*)&tmpRecord, sizeof( copyInstanceRecord ) );
	tmpRecord.lineNumber = fileNameLineNumber;
	this->fileWriter.seekp( ( this->currentCopyInstanceSequenceNumber * sizeof( copyInstanceRecord ) ) );
	this->fileWriter.write( ( char* )&tmpRecord, sizeof( copyInstanceRecord ) );
	this->fileWriter.flush();
}

void ProgressTracker::putOffsetToCopyFrom( long offsetToCopyFrom )
{	
	//this->fileWriter.open( this->progressTrackerFile, ios::in | ios::out | ios::binary );
	this->fileWriter.seekp( ( this->currentCopyInstanceSequenceNumber * recordLen) + offsetStorageOffset );
	this->fileWriter.write( reinterpret_cast<char*>( &offsetToCopyFrom ), offsetStorageLen );
	this->fileWriter.flush();
	//this->fileWriter.close();
	//this->fileWriter.open( this->progressTrackerFile, ios::binary );	
}

int ProgressTracker::getCopyInstanceCount()
{
	ifstream recordCounterStream( this->progressTrackerFile, ios::in | ios::binary);
	recordCounterStream.seekg(0, recordCounterStream.end);
	return ( (recordCounterStream.tellg() )/ (sizeof(copyInstanceRecord) ) );
}


int ProgressTracker::getCopyInstanceSequenceNumber()
{
	return this->currentCopyInstanceSequenceNumber;
}


ProgressTracker::~ProgressTracker()
{
	this->fileReader.close();
	this->fileWriter.close();
}
/*


int main(void)
{
	char tmp;
	ProgressTracker* tracker = new ProgressTracker();
	
	tracker->putTmpFileName( "231tmp.list" );
	tracker->putNextFileNameIndexToCopy( (long)342);
	//cin>>tmp;
	ProgressTracker* tracker1 = new ProgressTracker();
	tracker1->putTmpFileName( "456tmp.list" );
	tracker1->putNextFileNameIndexToCopy( (long)2452);


	ProgressTracker* tracker2 = new ProgressTracker();
	tracker2->putTmpFileName( "777tmp.list" );
	tracker2->putNextFileNameIndexToCopy( (long)6532);
	
	//tracker->putTmpFileName( "656tmp.list" );
	//tracker->putTmpFileName( "856tmp.list" );
	//cin>>tmp;
	
	//tracker->putOffsetToCopyFrom(2,(long)534534);
	//cin>>tmp;
	cout<< endl << "currently copying in 2" << tracker1->getTmpFileName( );
	cout << "currently copying in 1 " << tracker->getTmpFileName( );
	cout <<" currently copying in 3" << tracker2->getTmpFileName( ) ;
	cout << "currently copying in 1 " << tracker2->getCurrentlyCopyingFileNameIndex( );
	//long newNum;
	//cin>>newNum;
	//long newNum = 4;
	//tracker->putNextFileNameIndexToCopy( 0, newNum);
	//cout<< endl<<"fileName - "<< endl<< tracker->getTmpFileName( 0 );
	//printf("\n %s %d %d",tracker->getTmpFileName( 2 ),(int)tracker->getCurrentlyCopyingFileNameIndex( 2 ), (int)tracker->getOffsetToCopyFrom(2));
	cout<< endl << "number of records" << tracker->getCopyInstanceCount();
	return 1;
}
*/