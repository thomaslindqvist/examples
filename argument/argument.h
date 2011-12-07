#ifndef TL_ARGUMENT_H_
#define TL_ARGUMENT_H_

#include <unistd.h>
#include <glog/logging.h>
#include <vector>

class Argument
{
   public:
   Argument()
   :m_argA()
   ,m_argB(false)
   {

   }

   bool parse(int argc, char **argv)
   {
     //Disable output from getopt;
     //opterr = 0;
     
     //A ':' after a flag means a value is expected
     //.i.e. -a 100
     int arg;
     while ((arg = getopt (argc, argv, "a:b")) != -1)
       switch (arg)
         {
         case 'a':
           LOG(INFO) << "Argument '-a': " << optarg;
           m_argA.push_back(optarg);
           break;
         case 'b':
           LOG(INFO) << "Argument '-b': true";
           m_argB = true;
           break;
         case '?':
           LOG(ERROR) << "Unknown option -" << static_cast<char>(optopt);
           return false;
         default:
           return false;
         }

     for (int index = optind; index < argc; index++)
     {
        LOG(ERROR) << "Non-option argument " << argv[index];
        return false; 
     }
     return true;
   }
   
   std::vector<char*>& getArgumentA() 
   {
      return m_argA;
   }

   bool getArgumentB() const
   {
      return m_argB;
   }

   private:
      std::vector<char*> m_argA;
      bool m_argB;
};

#endif

