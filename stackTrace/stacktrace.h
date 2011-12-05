#ifndef STACKTRACE_H_
#define STACKTRACE_H_

#include <execinfo.h>
#include <iostream>

class StackTrace
{
   public: 
      StackTrace()
      :nTrace(10)
      {
         print();
      };

      StackTrace(unsigned int trace)
      :nTrace(trace)
      {
         print();
      };      
      
       void print()
      {
          //Number of steps to trace
          //const int nTrace = 10;
          void *array[nTrace];

	  //ToDo log to glog
http://stackoverflow.com/questions/77005/how-to-generate-a-stacktrace-when-my-gcc-c-app-crashes

          // print out all the frames to stderr or stdout
          std::cout << "\nStackTrace:\n";
          backtrace_symbols_fd(array, backtrace(array, nTrace), 1); //0=stdin, 1=stdout, 2=stderr
      }

   private:
      const unsigned int nTrace; 
};

#endif
