#include "../includes/CopyInstance.h"
#include "threadPool.cpp"
copyInstance::copyInstance( const char* src[], int numberOfSources, const char* dest):destination( "" ), isBuffer1Free(true), isBuffer2Free(true), fileNotCompleted(true)
{
	i = 0;
	string source( src[0] ), destination( dest );

	progressTracker = new ProgressTracker();

	sourcePath = string( getPathFromSource( source ) );
	//cout<<"sourc -"<< sourcePath<<endl; 
	if( destination.at( destination.length()-1 )!='/' )
		destination.append("/");
	this->destination = destination;

	tmpFileName = string( generateTempFileName() );

	string command( "echo \"" );
	command.append( destination );
	command.append( "\" >> tmp/");
	command.append( tmpFileName ); // generate source directory name at destination
	system( command.c_str() );


	progressTracker->putTmpFileName( tmpFileName.c_str() );
	for( int srcListCounter = 0; srcListCounter < numberOfSources; srcListCounter++ )
	{
		string source( src[srcListCounter] );
			
		if( isDir( source.c_str() ) )	//if source is a directory, create the same named directory at destination first
		{
			// adding source directory name to be generatedat destination
			cout<< "destination "<<destination<< endl;
			command = string( "echo \"" );
			command.append( source );
			command.append( "\" >> tmp/");
			command.append( tmpFileName ); // generate source directory name at destination
			system( command.c_str() ); 
	
			if( source.at( source.length()-1 )!='/' )
				source.append("/");
			
			
			string commandStart = "ls -Rr ";
			string commandEnd = " | awk ' /:$/&&f{s=$0;f=0} /:$/&&!f{sub(/:$/,\"\");s=$0;f=1;next} NF&&f{ print s\"/\"$0 }' >> tmp/";
			
			string finalCommand;
			finalCommand = commandStart;
			finalCommand.append( source );
			finalCommand.append( commandEnd );
			finalCommand.append( tmpFileName );
			system( finalCommand.c_str() ); // execution of command to list everything in source directory
		}
		else
		{
			string command( "echo \"" );
			command.append( source );
			command.append( "\" >> tmp/");
			command.append( tmpFileName );
			system( command.c_str() ); 
			
		}

	}
	copyWork();	// start copy work for given 
}

void copyInstance::testPrint()
{
	cout<< endl<<"testing"<<endl;
	
	
		cout<<this->i<<endl;
		this->i++;
	
}

string copyInstance::generateTempFileName()
{
	int copyInstanceCount = progressTracker->getCopyInstanceCount();
	string destTempFileName;
	if(copyInstanceCount < 10 )
		destTempFileName = string( "00" );
	else if( copyInstanceCount < 100 )
		destTempFileName = string( "0" );
	destTempFileName.append( boost::to_string( copyInstanceCount ) );
	destTempFileName.append( "tmp.list");
	return destTempFileName;
}

void copyInstance::copyWork()
{
	int srcLen = sourcePath.length();
	string resultantDestination, tmpListFile( "tmp/" );
	tmpListFile.append( tmpFileName );
	ifstream fileList( tmpListFile.c_str() );
	getline( fileList, destination );

		string tmp;
		while( getline( fileList, tmp ) ){
			resultantDestination = tmp;
			resultantDestination.replace( 0, srcLen, destination);
			if( isDir( tmp.c_str() ) )
			{
				mkdir( resultantDestination.c_str(), 0777 );
				cout<< "result - "<<resultantDestination<<endl;
			}
			else
			{
				cout<< "result - "<<resultantDestination<<endl;
				writerStream1.open( resultantDestination.c_str(), ios::in | ios::out | ios::binary );
				writerStream2.open( resultantDestination.c_str(), ios::in | ios::out | ios::binary );
				readerStream.open( tmp.c_str(), ios::binary );

				pool = new ThreadPool(3);
				pool->run_task(boost::bind(&copyInstance::reader,this));
				pool->run_task(boost::bind(&copyInstance::writer,this));
				//pool->join();
				//pool->run_task(boost::bind(&copyInstance::writer,this));
			}
		}		

}

void copyInstance::writer()
{
	while( this->fileNotCompleted )
	{
		if( !this->isBuffer1Free && !this->isBuf1BeingWritten)
		{
			this->isBuf1BeingWritten = true;
			this->writerStream1.seekp( this->buf1Position );
			this->writerStream1.write( this->buffer1, CHUNK_SIZE );
			this->writerStream1.flush();
			this->isBuffer1Free = true;
			this->isBuf1BeingWritten = false;		
		}

		if( !this->isBuffer2Free && !this->isBuf2BeingWritten )
		{
			this->isBuf2BeingWritten = true;
			this->writerStream2.seekp( this->buf2Position );
			this->writerStream2.write( this->buffer2, CHUNK_SIZE );
			this->writerStream2.flush();
			this->isBuffer2Free = true;
			this->isBuf2BeingWritten = false;		
		}
	}
	this->writerStream1.close();
	this->writerStream2.close();
}

void copyInstance::reader()
{
	cout<< endl<<"buffer position"<<this->buf1Position<< endl;
	this->buf1Position = 0;
	this->buf2Position = 0;
	unsigned long currentReadPosition = 0;
	while( this->fileNotCompleted )
		{
			if( this->isBuffer1Free )
			{
				
				if( !this->readerStream.read( this->buffer1, CHUNK_SIZE) )
					this->fileNotCompleted = false;
				this->buf1Position = currentReadPosition;
				currentReadPosition += CHUNK_SIZE;
			}

			if( this->isBuffer2Free )
			{
				
				if( !this->readerStream.read( this->buffer2, CHUNK_SIZE) )
					this->fileNotCompleted = false;
				this->buf2Position = currentReadPosition;
				currentReadPosition += CHUNK_SIZE;
			}
		}
	this->readerStream.close();
}


bool copyInstance::isDir( const char* path )
{
	struct stat sourcePathStat;
	int status;
	status = stat( path, &sourcePathStat);
		if( S_ISDIR( sourcePathStat.st_mode ) )
			return true;
		else
			return false;
}

bool copyInstance::isFile( const char* path, long* size )
{
	struct stat sourcePathStat;
	int status;
	status = stat( path, &sourcePathStat);
		if( S_ISREG( sourcePathStat.st_mode ) )
		{
			*size = ( long ) sourcePathStat.st_size;
			return true;
		}
		else
		{
			*size = 0;
			return false;
	}
}

//template< typename string >
string copyInstance::getPathFromSource( string path )
{
	int srcLen = path.length();
	int position = 0;

	for( int cnt = 0; cnt < srcLen-2; cnt++ )
	{
		if( path.at( cnt )== '/' )
		{
			position  = cnt;
		}
	}
	path.replace( ( position+1 ), ( path.length()-1 ),"" );
	return path;
}





int main( void )
{
	const char* srcs[] = {"/home/droidboyjr/Pictures/walls","/home/droidboyjr/Pictures/background.jpg","/home/droidboyjr/Pictures/bans"};
	const char* dest = "/home/droidboyjr/Documents/fresh";
	copyInstance ci( srcs, 3, dest );
	return 1;

}
