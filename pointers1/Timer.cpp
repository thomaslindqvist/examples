//$Id: Timer.cpp 10 2011-06-11 16:48:12Z home.thomas.lindqvist@gmail.com $
#include "Timer.h"
#include <stdio.h>
#include <sys/time.h>
#include <time.h>


Timer::Timer()
:startTime()
,stopTime()
{
}

Timer::~Timer() {
}

void Timer::start(){
    gettimeofday(&startTime, NULL);
}

void Timer::stop(){
	gettimeofday(&stopTime, NULL);
	elepsedTime();
}

void Timer::reset(){
    start();
}

double Timer::elepsedTime(){
	localtime(&startTime.tv_sec);
	localtime(&stopTime.tv_sec);

	unsigned int sec, usec = 0;

	//Seconds
	sec = stopTime.tv_sec - startTime.tv_sec;

	//Minutes
	if(stopTime.tv_usec >= startTime.tv_usec)
	{
		usec = stopTime.tv_usec - startTime.tv_usec;
	}
	else
	{
		usec = (1000000 - startTime.tv_usec) + stopTime.tv_usec;
		sec--;
	}

	printf("%f ms\n", sec*1000.0 + usec/1000.0);

	//Return elepsed time in millisec
	return sec*1000.0 + usec/1000.0;
}
