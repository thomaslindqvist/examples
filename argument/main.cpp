#include "argument.h"
#include <iostream>

int main(int argc, char* argv[])
{
   Argument arg;
   arg.parse(argc, argv);

   for(auto it = arg.getArgumentA().begin(); it != arg.getArgumentA().end(); it++)
   {
      std::cout << "-a: " << *it << std::endl;
   }

      std::cout << "-b: " << arg.getArgumentB() << std::endl;

   return 1;
}
