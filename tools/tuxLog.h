/* 
 *Tux Transfer Logging Tool 
 *version 0.1
 *
*/

#ifndef TUX_LOG_H
#define TUX_LOG_H

#include<iostream.h>
#include<string.h>

class TuxLog
{

 public:
  static void trace(string);
  static void debug(string);
  static void info(string);
  static void warning(string);
  static void error(string); 
  static void fatal(string);
 private:

};

#endif
