#include "argument.h"
#include "signals.h"
#include <glog/logging.h>

int main(int argc, char* argv[])
{
   try
   {
      //Initialize Google's logging library.
      google::InitGoogleLogging(argv[0]);

      //Parse arguments in argv
      Argument args;
      args.parse(argc, argv);

      //Handle signals
      Signals::enableAll();
      
      while(true)
      {
      
      }

      return 1;
   }
   
   catch(std::exception e)
   {
      LOG(ERROR) << e.what();
      return 0;
   }
   catch(...)
   {
      LOG(ERROR) << "Received an unknown exception";
      return 0;
   }
}
