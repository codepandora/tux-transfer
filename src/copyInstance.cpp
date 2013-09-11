
#include "../includes/copyInstance.h"

copyInstance::copyInstance( const char* src,  const char* dest)
{
	string source( src ), destination( dest ), resultantDestination;

	int srcLen = source.length();
	if( isDir( source.c_str() ) )	//if source is a directory, create the same named directory at destination first
	{
		int position;
		for( int cnt = 0; cnt < srcLen-2; cnt++ )
		{
			if( source.at( cnt )== '/' )
			{
				position  = cnt;
			}
		}
		string addToDestination = source;
		addToDestination.replace( 0, position, "" );
		destination.append( addToDestination );
		mkdir( destination.c_str(), 0777 );
	}

	if( source.at( source.length()-1 )!='/' )
		source.append("/");
	if( destination.at( destination.length()-1 )!='/' )
		destination.append("/");
	
	string finalCommand;
	string commandStart = "ls -Rr ";
	string commandEnd = " | awk ' /:$/&&f{s=$0;f=0} /:$/&&!f{sub(/:$/,\"\");s=$0;f=1;next} NF&&f{ print s\"/\"$0 }' > ../tmp/tmp.list";
	finalCommand = commandStart;
	finalCommand.append( source );
	finalCommand.append( commandEnd );
	system( finalCommand.c_str() );
	ifstream fileList( "../tmp/tmp.list" );
	string tmp;
	while( getline( fileList, tmp ) ){
		//printf( "\n%s-%s" ,src, tmp.c_str() );
		if( isDir( tmp.c_str() ) )
		{
			resultantDestination = tmp;
			resultantDestination.replace( 0, srcLen-1, destination);
			cout<< "result"<<resultantDestination<<endl;
			mkdir( resultantDestination.c_str(), 0777 );
		}
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
	const char* src = "/home/droidboyjr/Pictures/";
	const char* dest = "/home/droidboyjr/Desktop/tmp";
	copyInstance ci( src,dest );
	return 1;

}