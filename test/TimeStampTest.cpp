// ++--++
// @file <filename>
// @date Created: <5-3-16>
// @version <0.0.0>
//
// @author <full name>
//
// @section LICENSE
// License: newBSD
//
// Copyright � 2016, HU University of Applied Sciences Utrecht.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
// - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
// - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
// - Neither the name of the HU University of Applied Sciences Utrecht nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
// BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
// OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// ++--++
#include "gtest/gtest.h"
#include "../source/include/TimeStamp.hpp"
#include "../source/include/Duration.hpp"
#include "../source/include/Clock.hpp"
#include <ctime> // For time test
#include <stdint.h>
#include <iostream>
using namespace std;
//using namespace adt;
using namespace r2d2;
/**
   TimeStamp Tests

*/
namespace r2d2{
TEST(TimeStamp,  Constructors) {
    
    TimeStamp t1 = Clock::get_current_time();
    sleep(1);
    TimeStamp t2 = Clock::get_current_time();
    
    Duration d1 = t2 - t1;
    
    std::cout << "duration: " << d1 << ", t1: " << t1 << ", t2: " << t2 << '\n';
   // TimeStamp m1;
   // EXPECT_EQ( m1.get_time(), 0 ) << "Default constructor, system time";

   // double d = 10000;
   // TimeStamp m2 = test_clock.getTimeStamp(d);
   
   // EXPECT_EQ( m2.get_time(), d ) << "Given time value";
   // d = -10000;
   // try{
      // TimeStamp m3 = test_clock.getTimeStamp(d);
      // EXPECT_NE( m3.get_time(), d) << "Not negative";
   // }catch(TimeStampException e) {
      // cout << e.what() << endl;
   // }
}
   
}