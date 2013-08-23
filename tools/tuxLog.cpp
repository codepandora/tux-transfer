#include "tuxLog.h"

using namespace std;

TuxLog::trace(string t)
{
  cout<<"Trace:"<<t<<endl;
}

TuxLog::debug(string d)
{
  cout<<"Debug:"<<d<<endl;
}

TuxLog::warning(string w)
{
  cout<<"Warning:"<<w<<endl;
}

TuxLog::error(string e)
{
  cout<<"Error:"<<e<<endl;
}

TuxLog::fatal(string f)
{
  cout<<"**Fatal**:"<<f<<endl;
}
