
#include "../includes/copyInstance.h"

copyInstance::copyInstance( const char* src,  const char* dest)
{
	dirHeadPtr = NULL;
	fileHeadPtr = NULL;
	tmpDirPtr = NULL;
	tmpFilePtr = NULL;		
	totalBytesToCopy = 0;	
	int StrPointerPosition = 0;
	int srcPathLen;
	int lastPositionOfPath = 0;
	const char* commandPart1 = "ls -R ";
	const char* commandPart2 = " | awk ' /:$/&&f{s=$0;f=0} /:$/&&!f{sub(/:$/,\"\");s=$0;f=1;next} NF&&f{ print s\"/\"$0 }' > /home/droidboyjr/Documents/op ";
	source = ( char* )malloc( sizeof( strlen( src )+1 ) );
	strcpy( source, src );
	char* command = ( char* ) malloc( sizeof( src )+ sizeof( commandPart1 )+ sizeof( commandPart2 )+ 2);
	strcpy( command, commandPart1 );
	command = strcat( command, source );
	command = strcat( command,commandPart2 );
	cout<<endl<<command<<endl;
	system( command );
	/*destination = ( char* )malloc( sizeof( strlen( dest )+1 ) );
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
	strcpy( source, src );
	strcpy( destination, dest );
	if( isDir( source ))
	{
		dirHeadPtr = NEWDIR;
		dirHeadPtr->dirPath = source;
		tmpDirPtr = dirHeadPtr;
		//mapSubFileStructure( tmpDirPtr );

	}
	else
	{
		fileHeadPtr = NEWFILE;
		fileHeadPtr->filePath = source;
	}
	cout<<endl<<" totalBytesToCopy "<<totalBytesToCopy<< endl;
*/
}



/*
	void copyInstance::initializeSourceDirStructure()
	{
		file* tmpFilePtr = NULL;
		dir* tmpDirPtr = NULL;
		DIR* dirPtr;
		struct dirent *dirEnt;
		long* fileSize = new long;
		int fileCnt = 0, dirCnt = 0;
		if( NULL != ( dirPtr = opendir( this->tmpDirPtr->dirPath ) ) )
		{
			while(NULL != (dirEnt = readdir( dirPtr ) ) )
			{
				char* fname = new char[ strlen( dirEnt->d_name ) + 1 ];
				strcpy( fname, dirEnt->d_name );
				char* completePath = ( char* ) malloc( strlen( dirEnt->d_name ) + strlen( source ) + 2 );
				strcpy( completePath,source );
				completePath = strcat( completePath, "/" );
				completePath = strcat( completePath, dirEnt->d_name );
				
				if( isFile( completePath, fileSize ) )
				{
					if( NULL == this->tmpDirPtr->files )
					{
						tmpFilePtr = NEWFILE;
						memset( tmpFilePtr, 0, sizeof( file ) );
						tmpFilePtr->fileName = fname;
						tmpFilePtr->filePath = completePath;
						tmpFilePtr->fileSize = *fileSize;
						this->tmpDirPtr->files = tmpFilePtr;	
						this->totalBytesToCopy += *fileSize;
					}			
					else
					{
						tmpFilePtr->nextFile = NEWFILE;
						tmpFilePtr = tmpFilePtr->nextFile;
						tmpFilePtr->fileName = fname;
						tmpFilePtr->filePath = completePath;
						tmpFilePtr->fileSize = *fileSize;
						this->totalBytesToCopy += *fileSize;
					}
				}
				else
				{
					if( NULL == this->tmpDirPtr->subDirs )
					{
						tmpDirPtr = NEWDIR;
						memset( tmpDirPtr, 0, sizeof( dir ) );
						tmpDirPtr->dirPath = completePath;
						tmpDirPtr->dirName = fname;
						this->tmpDirPtr->subDirs = tmpDirPtr;		
					}
					else
					{
						tmpDirPtr->nextDir = NEWDIR;
						tmpDirPtr = tmpDirPtr->nextDir;	
						memset( tmpDirPtr, 0, sizeof( dir ) );
						tmpDirPtr->dirPath = completePath;
						tmpDirPtr->dirName = fname;
					}
				}
			}
		}
		
	}
*/
	void copyInstance::mapSubFileStructure( dir* parentDir )
	{
		file* tmpFilePtr = NULL;
		dir* tmpDirPtr = NULL;
		DIR* dirPtr;
		struct dirent *dirEnt;
		long* fileSize = new long;
		int fileCnt = 0, dirCnt = 0;
		if( NULL != ( dirPtr = opendir( parentDir->dirPath ) ) )
		{
			while(NULL != (dirEnt = readdir( dirPtr ) ) )
			{
				char* fname = new char[ strlen( dirEnt->d_name ) + 1 ];
				strcpy( fname, dirEnt->d_name );
				char* completePath = ( char* ) malloc( strlen( dirEnt->d_name ) + strlen( parentDir->dirPath ) + 2 );
				strcpy( completePath, parentDir->dirPath );
				completePath = strcat( completePath, "/" );
				completePath = strcat( completePath, dirEnt->d_name );
				
				if( isFile( completePath, fileSize ) )
				{
					if( NULL == parentDir->files )
					{
						tmpFilePtr = NEWFILE;
						memset( tmpFilePtr, 0, sizeof( file ) );
						tmpFilePtr->fileName = fname;
						tmpFilePtr->filePath = completePath;
						tmpFilePtr->fileSize = *fileSize;
						parentDir->files = tmpFilePtr;	
						this->totalBytesToCopy += *fileSize;
					}			
					else
					{
						tmpFilePtr->nextFile = NEWFILE;
						tmpFilePtr = tmpFilePtr->nextFile;
						tmpFilePtr->fileName = fname;
						tmpFilePtr->filePath = completePath;
						tmpFilePtr->fileSize = *fileSize;
						this->totalBytesToCopy += *fileSize;
					}
				}
				else
				{
					if( NULL == parentDir->subDirs )
					{
						tmpDirPtr = NEWDIR;
						memset( tmpDirPtr, 0, sizeof( dir ) );
						tmpDirPtr->dirPath = completePath;
						tmpDirPtr->dirName = fname;
						parentDir->subDirs = tmpDirPtr;
						mapSubFileStructure( tmpDirPtr );
					}
					else
					{
						tmpDirPtr->nextDir = NEWDIR;
						tmpDirPtr = tmpDirPtr->nextDir;	
						memset( tmpDirPtr, 0, sizeof( dir ) );
						tmpDirPtr->dirPath = completePath;
						tmpDirPtr->dirName = fname;
						mapSubFileStructure( tmpDirPtr );
					}
				}
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
	const char* src = "/media/general";
		const char* dest = "/home/droidboyjr/Desktop";
	copyInstance ci( src,dest );
	return 1;

}