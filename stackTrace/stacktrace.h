#ifndef TL_STACKTRACE_H_
#define TL_STACKTRACE_H_

/** @brief This class is used for print the call stack.
 *  Can be used when an application receive a signal from
 *  the operating system i.e. SIGTERM.
 *  

    This source is free to use without any limitations.
    @author Thomas Lindqvist
*/

#include <execinfo.h>
#include <iostream>

class StackTrace
{
   public:
   
     /** Default constructor 
      *  The call stack length is set to 10
      *  @param None.
      *  @return None.
      */
      StackTrace()
      :nTrace(10)
      {
         print();
      };

     /** Constructor 
      *  The call stack length is set in the argument length. 
      *  @param length number of calls in the call stack
      *  @return None.
      */
      StackTrace(unsigned int length)
      :nTrace(length)
      {
         print();
      };      
      
     /** Constructor 
      *  Print the call stack. 
      *  @param None.
      *  @return None.
      */
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
      /** Store how many traces that will be printed. */ 
      const unsigned int nTrace; 
};

#endif
