#include "../include/Clock.hpp"

//============================================================================================================
//Class Clock
//============================================================================================================
r2d2::TimeStamp r2d2::Clock::get_current_time()
{
    TimeStamp time;
    time = time((double)std::chrono::high_resolution_clock::now().time_since_epoch().count() / 1000);
	return time;
}