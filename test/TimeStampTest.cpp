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
#include <chrono>
#include <stdint.h>
#include <iostream>
using namespace std;
using namespace r2d2;
/**
   TimeStamp Tests
*/

bool double_range(double d1, double d2, double offset = 0.005){
    return ((d1 - (offset)) < d2) &&
     (d2 < (d1 + (offset)));
}

namespace r2d2{
//assumes it is created if it doesn't crash
TEST(TimeStamp,  DefaultConstructor) {
    TimeStamp ts1();
}

TEST(TimeStamp,  CopyConstructor) {
    TimeStamp ts1 = Clock::get_current_time();
    TimeStamp ts2(ts1);
    EXPECT_EQ(ts2.get_time(), ts1.get_time());
}

TEST(TimeStamp,  Assignment) {
    TimeStamp ts1 = Clock::get_current_time();
    TimeStamp ts2 = ts1;
    
    EXPECT_EQ(ts1.get_time(), ts2.get_time());
}
    
//TimeStamp operator+ ( const Duration& refDuration ) const;
TEST(TimeStamp, AddConstDuration) {
    TimeStamp ts1 = Clock::get_current_time();
    sleep(1);
    TimeStamp ts2 = Clock::get_current_time();
    Duration d = Duration(Duration::SECOND * 1);
    
    TimeStamp ts4 = ts1;
    TimeStamp ts3 = ts1 + d;
    EXPECT_TRUE(double_range(ts2.get_time(), ts3.get_time()));
    EXPECT_EQ(ts1.get_time(), ts4.get_time())
    << "Ts1 has been edited in + operator";
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
    
    TimeStamp ts4 = ts2;
    TimeStamp ts3 = ts2 - d;
    EXPECT_TRUE(double_range(ts1.get_time(), ts3.get_time()));
    EXPECT_EQ(ts4.get_time(), ts2.get_time()) << 
    "Ts1 has been edited in + operator";
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
    
    TimeStamp ts3 = ts1;
    TimeStamp ts4 = ts2;
    
    Duration d2 = ts2 - ts1;
    EXPECT_TRUE(double_range(d1.get_seconds(), d2.get_seconds()));
    EXPECT_EQ(ts3.get_time(), ts1.get_time()) << 
    "Ts1 has been edited in - operator";
    EXPECT_EQ(ts4.get_time(), ts2.get_time()) << 
    "Ts2 has been edited in - operator";
}

//friend ostream& operator<< (ostream& lhs, const TimeStamp& refDuration);
//friend istream& operator>> (istream& lhs, TimeStamp& refDuration);
TEST(TimeStamp, StreamOperators){
    TimeStamp ts1;
    TimeStamp ts2;
    stringstream ss1;
    ss1.str("500 1000");
    ss1 >> ts1 >> ts2;
    
    EXPECT_EQ(ts1.get_time(), 500) << "First inpustream incorrect";
    EXPECT_EQ(ts2.get_time(), 1000) << "Second inputstream incorrect";
    
    stringstream ss2;
    
    ss2 << ts1 << ' ' << ts2;
    double d1, d2;
    
    ss2 >> d1 >> d2;
    
    EXPECT_EQ(ts1.get_time(), d1) << "First outputstream incorrect";
    EXPECT_EQ(ts2.get_time(), d2) << "Second outputstream incorrect";
}

TEST (TimeStamp, RelationalOperators){
    TimeStamp ts1 = Clock::get_current_time();
    sleep(1);
    TimeStamp ts2 = Clock::get_current_time();
    EXPECT_TRUE(ts2 > ts1);
    EXPECT_FALSE(ts1 > ts2);
    
    EXPECT_TRUE(ts1 < ts2);
    EXPECT_FALSE(ts2 < ts1);
}

//double get_time() const;
TEST(TimeStamp, get_time){
    TimeStamp ts1 = Clock::get_current_time();
    double d1 = (double)std::chrono::high_resolution_clock::now().time_since_epoch().count() 
    / timeFactor;
    EXPECT_EQ(ts1.get_time(), d1);
}

//Checks if unintended modifiers throw exceptions
TEST(TimeStamp, ExceptionSafety){
    TimeStamp ts1;
    double d1 = -1000, d2 = 1000;
    stringstream ss;
    
    ss << d2;
    ss >> ts1;
    EXPECT_EQ(ts1.get_time(), d2);
    
    ss << d1;
    try{
      ss >> ts1;
      EXPECT_NE(ts1.get_time(), d1);
   }catch(TimeStampException e){
   }
}
}