/*
 *Main Tux Transfer Execution File
 *Author: CodePandora
 *Version: 0.1
 */

#include "includes/TuxTray.h"
#include<iostream>

void displayHelp()
{  
  cout<<"==========================================================="<<endl;
  cout<<"-------------------------TUX TRANSFER----------------------"<<endl;
  cout<<"----------------------------ver 0.1------------------------"<<endl;
  cout<<"==========================================================="<<endl;
  cout<<"-----------------------------------------------------------"<<endl;
  cout<<"\t\t\t\tUsage"<<endl;
  cout<<"-----------------------------------------------------------"<<endl;
  cout<<"Copy: TuxTransfer -c <SOURCE FILES> -d <DESTINATION PATH>"<<endl;
  cout<<"Move: TuxTransfer -m <SOURCE FILES> -d <DESTINATION PATH>"<<endl;
  cout<<"Help: TuxTransfer -h"<<endl;
  cout<<"-----------------------------------------------------------"<<endl;
}

int main(int argc, char *argv[])
 {
     if(argc==1)
     {	
     	QApplication app(argc, argv);
     	app.setAttribute(Qt::AA_DontShowIconsInMenus, false);    

     	TuxTray *icon = new TuxTray();
     	//icon->hide();

     	return app.exec();
     }
   
     if(argc>1 && argv[1][0]=='-')
     {
	switch(argv[1][1])
	{
		case 'c': cout<<"Copy"<<endl;
			  break;
		case 'h': displayHelp();
			  break;
		default:  cout<<"Invalid arguments specified."<<endl;
			  displayHelp();
	}
     }
     else
     {
	cout<<"Invalid arguments specified."<<endl;
	displayHelp();
     }
 }
