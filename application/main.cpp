#include "signals.h"
#include <glog/logging.h>

int main(int argc, char* argv[])
{
   //Handle signals
   Signals::enableAll();

   //Initialize Google's logging library.
   google::InitGoogleLogging(argv[0]);
   
   while(true)
   {
   char* a; *a=2;
   }

   return 1;
}
