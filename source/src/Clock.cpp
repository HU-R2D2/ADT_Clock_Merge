#include "../include/Clock.hpp"

//============================================================================================================
//Class Clock
//============================================================================================================
TimeStamp Clock::get_current_time()
{
	return TimeStamp((std::chrono::high_resolution_clock::now().time_since_epoch().count() / 1000));
}