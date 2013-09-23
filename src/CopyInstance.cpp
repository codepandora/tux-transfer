
#include "../includes/CopyInstance.h"

copyInstance::copyInstance( const char* src[], int numberOfSources, const char* dest)
{
	string source( src[0] ), destination( dest ), resultantDestination, sourcePath;
	cout<< source.c_str()<< ( sizeof( src )/ sizeof( *src ) )<< endl;
	int srcLen = source.length();
	int position;

		for( int cnt = 0; cnt < srcLen-2; cnt++ )
		{
			if( source.at( cnt )== '/' )
			{
				position  = cnt;
			}
		}
	
	sourcePath = source;
		sourcePath.replace( ( position+1 ), ( source.length()-1 ),"" );
		cout<<"sourc -"<< sourcePath<<endl; 
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
			
			string finalCommand;
			string commandStart = "ls -Rr ";
			string commandEnd = " | awk ' /:$/&&f{s=$0;f=0} /:$/&&!f{sub(/:$/,\"\");s=$0;f=1;next} NF&&f{ print s\"/\"$0 }' >> ../tmp/tmp.list";
			finalCommand = commandStart;
			finalCommand.append( source );
			finalCommand.append( commandEnd );

			system( finalCommand.c_str() );
			
			//boost::thread copyThread( boost::bind( &copyInstance::testPrint, this) ) ;
			//copyThread.join();
			copyWork( sourcePath, destination );	
		}
		else
		{
			string command( "echo \"" );
			command.append( source );
			command.append( "\" >> ../tmp/tmp.list ");
			system( command.c_str() ); 
			
		}

	}
}

void copyInstance::testPrint()
{
	cout<< endl<<"testing"<<endl;
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
				

				ofstream writerStream; //comment this
				ifstream readerStream; //comment this also and observe
				writerStream.open( resultantDestination.c_str(), ios::binary );
				readerStream.open( tmp.c_str(), ios::binary );
				while( readerStream.read( buffer, 512) )
				{
					writerStream.write( buffer, 512 );
				}
				//reader();   
				
			}
		}
}

void copyInstance::writer()
{
	writerStream.write( buffer, 512 );
}

void copyInstance::reader()
{
	while( readerStream.read( buffer, 512) )
				{
					writer();
				}
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







int main( void )
{
	const char* srcs[] = {"/home/droidboyjr/Pictures/walls","/home/droidboyjr/Pictures/background.jpg","/home/droidboyjr/Pictures/bans"};
	const char* dest = "/home/droidboyjr/Documents/fresh";
	copyInstance ci( srcs, 3, dest );
	return 1;

}