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

bool double_range(double d1, double d2, double offset = 0.001){
    return ((d1 - (offset)) < d2) &&
     (d2 < (d1 + (offset)));
}

namespace r2d2{
//assumes it is created if it doesn't crash
TEST(TimeStamp,  DefaultConstructor) {
    //TimeStamp t1();
}

TEST(TimeStamp,  CopyConstructor) {
    TimeStamp t1 = Clock::get_current_time();
    TimeStamp t2(t1);
    EXPECT_EQ(t2.get_time(), t1.get_time());
}

TEST(TimeStamp,  Assignment) {
    //TimeStamp ts1();
}
    
//TimeStamp operator+ ( const Duration& refDuration ) const;
TEST(TimeStamp, AddConstDuration) {
    TimeStamp ts1 = Clock::get_current_time();
    sleep(1);
    TimeStamp ts2 = Clock::get_current_time();
    Duration d = Duration(Duration::SECOND * 1);
    
    TimeStamp ts3 = ts1 + d;
    EXPECT_TRUE(double_range(ts2.get_time(), ts3.get_time()));
}
    
//TimeStamp& operator+= (const Duration& refDuration);
TEST(TimeStamp, AddAssignConstDuration) {
    TimeStamp ts1 = Clock::get_current_time();
    sleep(1);
    TimeStamp ts2 = Clock::get_current_time();
    Duration d = Duration(Duration::SECOND * 1);
    
    ts1 += d;
    EXPECT_TRUE(double_range(ts1.get_time(), ts2.get_time()));
}
    
//TimeStamp operator- ( const Duration& refDuration ) const;
TEST(TimeStamp, SubstractConstDuration) {
    TimeStamp ts1 = Clock::get_current_time();
    sleep(1);
    TimeStamp ts2 = Clock::get_current_time();
    Duration d = Duration(Duration::SECOND * 1);
    
    TimeStamp ts3 = ts2 - d;
    EXPECT_TRUE(double_range(ts1.get_time(), ts3.get_time()));
}
    
//TimeStamp& operator-= (const Duration& refDuration);
TEST(TimeStamp, SubstractAssignConstDuration) {
    TimeStamp ts1 = Clock::get_current_time();
    sleep(1);
    TimeStamp ts2 = Clock::get_current_time();
    Duration d = Duration(Duration::SECOND * 1);
    
    ts2 -= d;
    EXPECT_TRUE(double_range(ts1.get_time(), ts2.get_time()));
}
    
//Duration operator- (const TimeStamp& refTimeStamp) const;
TEST(TimeStamp, SubstractTimeStamp) {
    TimeStamp ts1 = Clock::get_current_time();
    sleep(1);
    TimeStamp ts2 = Clock::get_current_time();
    Duration d1 = Duration(Duration::SECOND * 1);
    
    Duration d2 = ts2 - ts1;
    EXPECT_TRUE(double_range(d1.get_seconds(), d2.get_seconds()));
}
}