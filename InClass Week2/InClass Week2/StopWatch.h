#ifndef STOPWATCH_HEADER_H
#define STOPWATCH_HEADER_H

#include <chrono>
using std::chrono::time_point;
using std::chrono::system_clock;
using std::chrono::duration;

class StopWatch
{
public:
	StopWatch() {}
	~StopWatch() {}

	void Start();

	void Stop();
	
	void Reset();

	double GetElapsedSeconds();

private:
	time_point<system_clock> startTime;
	time_point<system_clock> endTime;
	duration<double> elapsedTime;
};

#endif