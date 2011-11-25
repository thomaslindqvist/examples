//$Id: main.cpp 12 2011-06-11 16:51:37Z home.thomas.lindqvist@gmail.com $

#include <iostream>
#include <glog/logging.h>

using namespace std;

int main(int argc, char* argv[])
{
   
   // Initialize Google's logging library.
   google::InitGoogleLogging(argv[0]);
   
   LOG(INFO)   << "Thomas logging_1"; 
   LOG(ERROR)  << "Thomas logging_2";
   return 1;
}
