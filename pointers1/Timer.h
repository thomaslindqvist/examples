//$Id: Timer.h 10 2011-06-11 16:48:12Z home.thomas.lindqvist@gmail.com $
/*! \brief Start and stop a timer with millisec resolution
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <time.h>
#include <stdlib.h>

class Timer {
public:
	/**
	 * Default constructor.
	 */
	Timer();

	/**
     	 * Destructor.
	 */
	virtual ~Timer();

	/**
	 * Start the timer from time zero.
	 */
	void start();

	/**
	 * Stop the timer and calculate elepsed time.
	 */
	void stop();

	/**
     	 * Restart the timer.
         * @see start
	*/
	void reset();

	/**
	 * Calcualate elepsed time in milli sec
	 */
	double elepsedTime();

private:
    	/**
     	 * Store the start time
         */
	timeval startTime;

	/**
	 * Store the stop time
	 */
	timeval stopTime;
};

#endif /* TIMER_H_ */
