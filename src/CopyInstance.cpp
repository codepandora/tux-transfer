#include "../includes/CopyInstance.h"
#include "threadPool.cpp"
copyInstance::copyInstance( const char* src[], int numberOfSources, const char* dest): isBuffer1Free(true), isBuffer2Free(true), fileNotCompleted(true)
{
	string source( src[0] ), destination( dest ), resultantDestination, tmpFileName;
	progressTracker = new ProgressTracker();

	sourcePath = getPathFromSource( source );
	cout<<"sourc -"<< sourcePath<<endl; 

	tmpFileName = generateTempFileName();
	progressTracker->putTmpFileName( tempFileName.c_str() );
	for( int srcListCounter = 0; srcListCounter < numberOfSources; srcListCounter++ )
	{
		string source( src[srcListCounter] );
			
		if( isDir( source.c_str() ) )	//if source is a directory, create the same named directory at destination first
		{
			cout<< "destination "<<destination<< endl;
			string command( "echo \"" );
			command.append( source );
			command.append( "\" >> ../tmp/tmp.list ");
			system( command.c_str() ); 
			if( source.at( source.length()-1 )!='/' )
				source.append("/");
			if( destination.at( destination.length()-1 )!='/' )
				destination.append("/");
			
			string commandStart = "ls -Rr ";
			string commandEnd = " | awk ' /:$/&&f{s=$0;f=0} /:$/&&!f{sub(/:$/,\"\");s=$0;f=1;next} NF&&f{ print s\"/\"$0 }' >> ../tmp/";
			
			
			string finalCommand;
			finalCommand = commandStart;
			finalCommand.append( source );
			finalCommand.append( commandEnd );
			finalCommand.append( tempFileName );
			system( finalCommand.c_str() );
			
			//boost::thread copyThread( boost::bind( &copyInstance::testPrint, this) ) ;
			//copyThread.join();
			copyWork( sourcePath, destination );	
		}
		else
		{
			string command( "echo \"" );
			command.append( source );
			command.append( "\" >> ../tmp/");
			command.append( tmpFileName );
			system( command.c_str() ); 
			
		}

	}
}

void copyInstance::testPrint()
{
	cout<< endl<<"testing"<<endl;
}

string CopyInstance::generateTempFileName()
{
	int copyInstanceCount = progressTracker->getCopyInstanceCount();
	string destTempFileName;
	if(copyInstanceCount < 10 )
		destTempFileName.append( "00" );
	else if( copyInstanceCount < 100 )
			 destTempFileName.append( "0" );
	destTempFileName.append( copyInstanceCount );
	destTempFileName.append( "tmp.list");
	return destTempFileName;
}



void copyInstance::copyWork( string sourcePath, string destination )
{
	int srcLen = sourcePath.length();
	string resultantDestination;
	ifstream fileList( "../tmp/tmp.list" );
		string tmp;
		while( getline( fileList, tmp ) ){
			//printf( "\n%s-%s" ,src, tmp.c_str() );
			if( isDir( tmp.c_str() ) )
			{
				resultantDestination = tmp;
				resultantDestination.replace( 0, srcLen, destination);
				//cout<< "result"<<resultantDestination<<endl;
				mkdir( resultantDestination.c_str(), 0777 );
				cout<< "result - "<<resultantDestination<<endl;
			}
			else
			{
				resultantDestination = tmp;
				resultantDestination.replace( 0, srcLen, destination);
				//cout<< "result"<<resultantDestination<<endl;
				cout<< "result - "<<resultantDestination<<endl;
				

				//ofstream writerStream; //comment this
				//ifstream readerStream; //comment this also and observe
				writerStream1.open( resultantDestination.c_str(), ios::in | ios::out | ios::binary );
				writerStream2.open( resultantDestination.c_str(), ios::in | ios::out | ios::binary );
				readerStream.open( tmp.c_str(), ios::binary );
				/*while( readerStream.read( buffer, CHUNK_SIZE) )
				{
					writerStream.write( buffer, CHUNK_SIZE );
				}
				//reader();   
				*/
				pool = new ThreadPool(3);
				pool->run_task(boost::bind(&copyInstance::reader,this));
				pool->run_task(boost::bind(&copyInstance::writer,this));
				pool->run_task(boost::bind(&copyInstance::writer,this));
			}
		}

}

void copyInstance::writer()
{

	while( fileNotCompleted )
	{
		if( !isBuffer1Free && !isBuf1BeingWritten)
		{
			isBuf1BeingWritten = true;
			writerStream1.seekp( buf1Position );
			writerStream1.write( buffer1, CHUNK_SIZE );
			writerStream1.flush();
			isBuffer1Free = true;
			isBuf1BeingWritten = false;		
		}

		if( !isBuffer2Free && !isBuf2BeingWritten )
		{
			isBuf2BeingWritten = true;
			writerStream2.seekp( buf2Position );
			writerStream2.write( buffer2, CHUNK_SIZE );
			writerStream2.flush();
			isBuffer2Free = true;
			isBuf2BeingWritten = false;		
		}
	}
	writerStream1.close();
	writerStream2.close();
}


void copyInstance::reader()
{
	buf1Position = 0;
	buf2Position = 0;
	unsigned long currentReadPosition = 0;
	while( fileNotCompleted )
		{
			if( isBuffer1Free )
			{
				
				if( !readerStream.read( buffer1, CHUNK_SIZE) )
					fileNotCompleted = false;
				buf1Position = currentReadPosition;
				currentReadPosition += CHUNK_SIZE;
			}

			if( isBuffer2Free )
			{
				
				if( !readerStream.read( buffer2, CHUNK_SIZE) )
					fileNotCompleted = false;
				buf2Position = currentReadPosition;
				currentReadPosition += CHUNK_SIZE;
			}
		}
	readerStream.close();
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


string CopyInstance::getPathFromSource( string path)
{

	int srcLen = path.length();
	int position;

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
