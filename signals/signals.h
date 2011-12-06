#ifndef TL_SIGNALS_H_
#define TL_SIGNALS_H_

/** @brief This class is used for handle signals sent by the
 *  operating system when a serious error uccured i.e dived by zero
 *  or CTRL C command.

    This source is free to use without any limitations.
    @author Thomas Lindqvist
*/

#include <signal.h>
#include "stacktrace.h"

class Signals
{
   public:
   
      /** Enable all signals 
       *  Signal types: SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM
       *  @param None.
       *  @return None.
       */
      static void enableAll()
      {
         enable(SIGABRT);
         enable(SIGFPE);
         enable(SIGILL);
         enable(SIGINT);
         enable(SIGSEGV);
         enable(SIGTERM);
      };

      /** Enable a signal
       *  Signal types: SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM
       *  @param Signal type.
       *  @return None.
       */
      static void enable(const int signalType)
      {
         signal (signalType, terminate);
      };

      /** Ignore a signal
       *  Signal types: SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM
       *  @param Signal type.
       *  @return None.
       */
      static void ignore(const int signalType)
      {
         signal (signalType, SIG_IGN);
      };

      /** Disable a signal, means that you set it back
       *  to the default behaviour.
       *  Signal types: SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM
       *  @param Signal type.
       *  @return None.
       */
      static void disable(const int signalType)
      {
         signal (signalType, SIG_DFL);
      };
      
      /** Handle a raised signal that is enabled.
       *  Signal types: SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM
       *  @param Signal type.
       *  @return None.
       */
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
         exit(0);
      };
};
#endif
