#include"StopWatch.h"

void StopWatch::Start()
{
	startTime = system_clock::now();
}

void StopWatch::Stop()
{
	endTime = system_clock::now();
}

void StopWatch::Reset()
{
	elapsedTime = system_clock::now() - system_clock::now();
}

double StopWatch::GetElapsedSeconds()
{
	elapsedTime = endTime - startTime;
	return elapsedTime.count();
}
