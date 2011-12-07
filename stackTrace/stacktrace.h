#ifndef TL_STACKTRACE_H_
#define TL_STACKTRACE_H_

/** \brief This class is used for print the call stack.
 *  Can be used when an application receive a signal from
 *  the operating system i.e. SIGTERM.
 *  

    This source is free to use without any limitations.
    @author Thomas Lindqvist
*/

#include <execinfo.h>
#include <glog/logging.h>
#include <vector>

class StackTrace
{
   public:
   
     /** Default constructor 
      *  The call stack length is set to 10
      *  @param None.
      *  @return None.
      */
      StackTrace()
      :m_nTrace(10)
      ,m_offset(0)
      {
         print();
      }

     /** Constructor 
      *  The call stack length is set in the argument length. 
      *  @param length number of traces in the call stack
      *  @return None.
      */
      StackTrace(unsigned int length)
      :m_nTrace(length)
      ,m_offset(0)
      {
         print();
      }

     /** Constructor 
      *  The call stack length is set in the argument length. 
      *  @param length number of traces in the call stack
      *  @param offset position from begining of the call stack 
      *  @return None.
      */
      StackTrace(unsigned int length, unsigned int offset)
      :m_nTrace(length)
      ,m_offset(offset)
      {
         print();
      }      
      
   private:
     /** Print the call stack. 
      *  @param None.
      *  @return None.
      */
      void print()
      {  
          std::vector<void*> array(m_nTrace);

          //Actual number of traces can be less then nTrace
          int nSize = backtrace(array.data(), m_nTrace);
          
          if(nSize != 0)
          {          
            //Pointer to trace information 
            char** symbols = backtrace_symbols(array.data(), nSize);

            LOG(ERROR) << "StackTrace:";

            //Start from 2, constructor and print is removed from output
            for(unsigned int i = 2 + m_offset; i < nSize-1; i++)
            {
               LOG(ERROR)  << *(symbols+i);
            }
         }
      }
      
      /** Number of traces that will be printed. */ 
      const unsigned int m_nTrace;

      /** Offset from begining of the call stack. */
      const unsigned int m_offset; 
};

#endif
