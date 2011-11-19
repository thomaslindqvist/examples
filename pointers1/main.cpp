//$Id: main.cpp 10 2011-06-11 16:48:12Z home.thomas.lindqvist@gmail.com $
#include <iostream>
#include "Data.h"
#include "Timer.h"

using namespace std;

void func3(const Data& data)
{

}

void func2(Data *data)
{

}

void func1(Data data)
{

}


int main()
{
   Timer timer;
   Data data(1000000);

   cout<<"func(Data data)\n";
   timer.start();
   func1(data);
   timer.stop();

   cout<<"\nfunc(Data *data)\n";
   timer.reset();
   func2(&data);
   timer.stop();

   cout<<"\nfunc(const Data& data)\n";
   timer.reset();
   func3(data);
   timer.stop();

   return 1;
}
