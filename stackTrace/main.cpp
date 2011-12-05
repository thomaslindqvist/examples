#include <stacktrace.h>

using namespace std;

void foo()
{
   StackTrace(2);
}

int main()
{
   StackTrace();
   foo();
   return 1;
}
