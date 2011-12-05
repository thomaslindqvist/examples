//$Id: main.cpp 12 2011-06-11 16:51:37Z home.thomas.lindqvist@gmail.com $

#include <iostream>
#include <thread>
#include <queue>
#include <tr1/functional>
#include "foo.h"
#include <vector>
#include <numeric>
#include <future>

using namespace std;
std::mutex myLock;

void f(int id)
{
   myLock.lock();
   cout<<"Thread " << id <<" is running\n";
   myLock.unlock();
}
  
void test1()
{
   std::thread t1(std::bind(f, 1));
   t1.join();
   std::thread t2(std::bind(f, 2));
   t2.join();
}

template< class Funct, class Arg >
void g( Funct f, Arg t )
{
  f(t);
}

template< class Funct>
void g2( Funct f, ... )
{
  f();
}


void test2()
{
   std::queue<std::thread> q;
   for(int i=0; i<10; i++)
   {
      std::thread t(std::bind(f, i));
      q.push(std::move(t));
   }

   while(!q.empty())
   {
       q.front().join();
       q.pop();
   }
}

int acc(std::vector<int> v)
{
   return std::accumulate(v.begin(), v.end(), 0);
}

int main()
{
   std::vector<int> v;
   v.push_back(1);
   v.push_back(2);
   v.push_back(3);


   auto r1 = std::async(acc, v);
   auto r2 = std::async(acc, v);

   cout<<"Total: " << r1.get() + r2.get() << endl;
     
   Foo f;
   std::thread t(f);
   t.join();

   test1();
   test2();
   return 1;    
}

