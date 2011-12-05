#ifndef TL_SIGNALS_H_
#define TL_SIGNALS_H_

#include <signal.h>
#include "stacktrace.h"

class Signals
{
   public:
      static void enableAll()
      {
         enable(SIGABRT);
         enable(SIGABRT);
         enable(SIGFPE);
         enable(SIGILL);
         enable(SIGINT);
         enable(SIGSEGV);
         enable(SIGTERM);
      };

      static void enable(const int signalType)
      {
         signal (signalType, terminate);
      };

      static void ignore(const int signalType)
      {
         signal (signalType, SIG_IGN);
      };

      static void disable(const int signalType)
      {
         signal (signalType, SIG_DFL);
      };

      static void terminate(const int signalType) 
      {
         switch(signalType)
         {
            case SIGABRT:
               std::cout << "\n(Signal Abort) Abnormal termination, such as is initiated by the abort function.\n";
               StackTrace();
            break;
            case SIGFPE:
	            std::cout << "\n(Signal Floating-Point Exception) Erroneous arithmetic operation, such as zero divide.\n";
               StackTrace();
            break;
            case SIGILL:
               std::cout << "\n(Signal Illegal Instruction) Invalid function image, such as an illegal instruction.\n";
               StackTrace();
            break;      
            case SIGINT:
               std::cout << "\n(Signal Interrupt) Interactive attention signal.\n";
            break;            
            case SIGSEGV:
               std::cout << "\n(Signal Segmentation Violation) Invalid access to storage.\n";
               StackTrace();
            break;         
            case SIGTERM:
               std::cout << "\n(Signal Terminate) Termination request sent to program.\n";
               StackTrace();
            break;
            default:
	            std::cout << "\n(Unknown signal) Terminating...\n";
               StackTrace();
         }
         std::cout << "More about signals, http://www.cplusplus.com/reference/clibrary/csignal/signal\n";
         
         //Shutdown after rececived a signal
         exit(1);
      };
};
#endif
