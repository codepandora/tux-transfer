
#include "../includes/copyInstance.h"

	void copyInstance::initializeSourceDirStructure()
	{
		
			printf("%s",new1);
			DIR* dirPtr;
			struct dirent *dirEnt;
			if( ( dirPtr = opendir( source ) ) != NULL )
			{

				while( (dirEnt = readdir( dirPtr ) ) != NULL )
				{
					//printf("\n%s", dirEnt->d_name);
					char* fname = (char*) malloc( strlen(dirEnt->d_name) );
					const char* tmpname = fname;
					
				}
			}
	}

	bool copyInstance::is_dir( const char* path)
	{
		struct stat sourcePathStat;
		int status;
		status = stat( source, &sourcePathStat);
			if( S_ISDIR( sourcePathStat.st_mode ) )
				return true;
			else
				return false;
	}


	bool copyInstance::is_file( const char* path)
	{
		struct stat sourcePathStat;
		int status;
		status = stat( source, &sourcePathStat);
			if( S_ISREG( sourcePathStat.st_mode ) )
				return true;
			else
				return false;
	}


		copyInstance::copyInstance( const char* src,  const char* dest):IS_DIR(2),IS_FILE(1)
		{
			int StrPointerPosition = 0;
			int srcPathLen;
			int lastPositionOfPath = 0;
			source = ( char* )malloc( sizeof( strlen( src )+1 ) );
			destination = ( char* )malloc( sizeof( strlen( dest )+1 ) );

			srcPathLen = strlen( src );
			for( ; StrPointerPosition< srcPathLen; StrPointerPosition++)
			{
				if( *( src+StrPointerPosition ) == '/' )
				{
					lastPositionOfPath = StrPointerPosition;
				}
			}
			printf( "%d", lastPositionOfPath);
			char tmp[ lastPositionOfPath+1 ];
			for( StrPointerPosition = 0; StrPointerPosition <= lastPositionOfPath; StrPointerPosition++)
			{
				tmp[ StrPointerPosition ] = *( src + StrPointerPosition );
			}	
			tmp[ StrPointerPosition ] = '\0';
					
			pathToSource = ( char* )malloc( lastPositionOfPath+1 );
			strcpy( pathToSource, tmp );
			printf( "\n\n %s is path \n",pathToSource );
			//char tmpPath[ lastPositionOfPath+1 ];

			//for( StrPointerPosition = 0; StrPointerPosition < lastPositionOfPath)

			strcpy( source, src );
			strcpy( destination, dest );
			if( is_dir( source ))
			{	

				sourceType = IS_DIR;
				initializeSourceDirStructure();
			}
			else
			{
				sourceType = IS_FILE;
			}
		}







int main( void )
{
	const char* src = "/home/droidboyjr/Pictures";
	const char* dest = "/home/droidboyjr/Desktop";
	copyInstance ci( src,dest );
	return 1;
}