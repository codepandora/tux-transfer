
#include "../includes/copyInstance.h"

	void copyInstance::initializeSourceDirStructure()
	{
			DIR* dirPtr;
			struct dirent *dirEnt;
			memset( dirHeadPtr, 0, sizeof( dir) );
			dirHeadPtr->dirPath = source;

			if( ( dirPtr = opendir( source ) ) != NULL )
			{
				while( (dirEnt = readdir( dirPtr ) ) != NULL )
				{
					char* fname = ( char* ) malloc( strlen( dirEnt->d_name ) + 1 );
					char* completePath = ( char* ) malloc( strlen( dirEnt->d_name ) + strlen( source ) + 2 );
					strcpy(completePath,source);
					completePath = strcat( completePath, "/" );
					completePath = strcat( completePath, dirEnt->d_name );

					if( is_file( completePath ) )
					{
						if( fileHeadPtr == NULL )
						{
							fileHeadPtr = NEWFILE;
							fileHeadPtr->filePath = completePath;
							tmpFilePtr = fileHeadPtr;
						}
						else
						{
							
							tmpFilePtr->nextFile = NEWFILE;
							tmpFilePtr = tmpFilePtr->nextFile;
							tmpFilePtr->filePath = completePath;
						}
						printf( "\n%s is file",completePath );
					}
					else
					{
						if( dirHeadPtr == NULL )
						{
							dirHeadPtr = NEWDIR;
							dirHeadPtr->dirPath = completePath;
							tmpDirPtr = dirHeadPtr;
						}
						else
						{
							tmpDirPtr->nextDir = NEWDIR;
							tmpDirPtr = tmpDirPtr->nextDir;
							tmpDirPtr->dirPAth = completePath;
						}
						printf( "\n%s is dir",completePath );
					}
				}
			}
	}

	dir* mapSubDirs( const char* )
	{

	}

	bool copyInstance::is_dir( const char* path )
	{
		struct stat sourcePathStat;
		int status;
		status = stat( path, &sourcePathStat);
			if( S_ISDIR( sourcePathStat.st_mode ) )
				return true;
			else
				return false;
	}


	bool copyInstance::is_file( const char* path)
	{
		struct stat sourcePathStat;
		int status;
		status = stat( path, &sourcePathStat);
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
			char tmp[ lastPositionOfPath+2 ];
			for( StrPointerPosition = 0; StrPointerPosition <= lastPositionOfPath; StrPointerPosition++)
			{
				tmp[ StrPointerPosition ] = *( src + StrPointerPosition );
			}

			tmp[ StrPointerPosition+1 ] = '\0';
					
			pathToSource = ( char* )malloc( lastPositionOfPath+1 );
			strcpy( pathToSource, tmp );
			printf( "\n\n %s is path \n",pathToSource );
			//char tmpPath[ lastPositionOfPath+1 ];

			//for( StrPointerPosition = 0; StrPointerPosition < lastPositionOfPath)

			strcpy( source, src );
			strcpy( destination, dest );
			if( is_dir( source ))
			{
				dirHeadPtr = NEWDIR;
				sourceType = IS_DIR;
				initializeSourceDirStructure();
			}
			else
			{
				fileHeadPtr = NEWFILE;
				fileHeadPtr->filePath = source;
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