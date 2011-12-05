#include "signals.h"

int main()
{
   Signals::enableAll();

   char* nullPtr;
   *nullPtr = 1;

   return 1;
}
