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
// Copyright © 2016, HU University of Applied Sciences Utrecht.
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
class test_Clock{
public:
   TimeStamp getTimeStamp()   {
      return TimeStamp(time(0));
   }
   TimeStamp getTimeStamp(double time) {
      return TimeStamp(time);
   }
};
}
test_Clock test_clock;
TEST(TimeStamp,  Constructors) {
   TimeStamp m1;
   EXPECT_EQ( m1.get_time(), 0 ) << "Default constructor, system time";

   double d = 10000;
   TimeStamp m2 = test_clock.getTimeStamp(d);
   
   EXPECT_EQ( m2.get_time(), d ) << "Given time value";
   d = -10000;
   try{
      TimeStamp m3 = test_clock.getTimeStamp(d);
      EXPECT_NE( m3.get_time(), d) << "Not negative";
   }catch(TimeStampException e) {
      cout << e.what() << endl;
   }
}
TEST(TimeStamp, AssignmentOperator)  {
   TimeStamp m1;
   TimeStamp m2;
   m1 = test_clock.getTimeStamp(1000);
   m2 = test_clock.getTimeStamp(1000);
   TimeStamp m3;
   m1 = m2;
   EXPECT_EQ( m1.get_time(), m2.get_time()) << "Object Assignment failed, operation failed";
   EXPECT_EQ( m1.get_time(), 1000) << "Object Assignment failed, wrong object modified";
   EXPECT_NE( &m1, &m2) << "Object Assignment failed, pointer test failed";
   m3 = test_clock.getTimeStamp(666);
   m1 = m2 = m3;
   EXPECT_EQ(m1.get_time(), m2.get_time()) << "Object Chaining failed";
   EXPECT_EQ(m2.get_time(), m3.get_time()) << "Object Chaining failed";
}

TEST(TimeStamp , AddAndSubtract)  {
   TimeStamp m1 = test_clock.getTimeStamp(5000);
   TimeStamp m2 = test_clock.getTimeStamp(10000);
   TimeStamp m3 = test_clock.getTimeStamp(5000);
   TimeStamp m4 = test_clock.getTimeStamp(30);
   TimeStamp m5 = test_clock.getTimeStamp(10);
   Duration d1 = m4 - m5;
   intptr_t ptrValue = (intptr_t)&m3;
   double test = m1.get_time();

   m3 = m3 = m1 - d1 - d1;
   intptr_t ptrValue2 = (intptr_t)&m3;

   ASSERT_EQ(test - 40/*4960*/, m3.get_time()) << "Duration subtracted from TimeStamp failed";
   ASSERT_EQ(ptrValue, ptrValue2) << "Object does not remain the same";
   Duration d2(m2 - m1);
   ASSERT_EQ(5000, d2.get_seconds()) << "TimeStamp subtracted from TimeStamp failed";
}
TEST(TimeStamp , AddAndSubtract2)  {
   TimeStamp m1 = test_clock.getTimeStamp (1000);
   Duration d1 = test_clock.getTimeStamp (1000) - test_clock.getTimeStamp (500);
   intptr_t ptrValue = (intptr_t)&m1;
   double testTime = m1.get_time();
   m1 += d1;
   intptr_t ptrValue2 = (intptr_t)&m1;
   ASSERT_EQ(d1.get_seconds() + testTime, m1.get_time()) << "+= returns incorrect value";
   ASSERT_EQ(ptrValue, ptrValue2) << "+= returned not the same object";
   testTime = m1.get_time();
   m1 -= d1;
   ptrValue = (intptr_t)&m1;
   ASSERT_EQ(testTime - d1.get_seconds(), m1.get_time()) << "-= returns incorrect value";
   ASSERT_EQ(ptrValue, ptrValue2) << "-= returned not the same object";
}
TEST(TimeStamp,  StreamOperators) {
   TimeStamp m1 = test_clock.getTimeStamp(0);
   TimeStamp m2 = test_clock.getTimeStamp(0);
   stringstream ss;
   ss.str("500 1000");
   ss >> m1 >> m2;

   ASSERT_EQ(m1.get_time(), 500) << "First inputstream for TimeStamp is incorrect";
   ASSERT_EQ(m2.get_time(), 1000) << "Second inputstream for TimeStamp is incorrect";

   stringstream ss2;
   ss2 << m1 << " " << m2;

   double firstDouble, secondDouble;
   ss2 >> firstDouble >> secondDouble;
   
   ASSERT_EQ(m1.get_time(), firstDouble) << "First outputstream for TimeStamp is incorrect";
   ASSERT_EQ(m2.get_time(), secondDouble) << "First outputstream for TimeStamp is incorrect";
}
TEST(TimeStamp, RelationalOperators)   {
   TimeStamp m1 = test_clock.getTimeStamp(500);
   TimeStamp m2 = test_clock.getTimeStamp(1000);
   ASSERT_EQ(m2 > m1, true) << "Greater than Comparison failed, should return true but did not";
   ASSERT_EQ(m1 > m2, false) << "Greater than Comparison failed, should return false but did not";
   
   ASSERT_EQ(m1 < m2, true) << "Smaller than Comparison failed, should return true but did not";
   ASSERT_EQ(m2 < m1, false) << "Smaller than Comparison failed, should return false but did not";
}
TEST(TimeStamp, ExceptionSafety) {
   
   double d = -10000;
   try{
     TimeStamp m3 = test_clock.getTimeStamp(d);
     EXPECT_NE( m3.get_time(), d) << "Not negative";
   }catch(...) {
     //cout << "Error thrown and handled, throw working properly" << endl;
   }
   TimeStamp m1 = test_clock.getTimeStamp(0);
   TimeStamp m2 = test_clock.getTimeStamp(0);
   stringstream ss;

   ss.str("test1 test2");
   try{
      ss >> m1 >> m2;
      ASSERT_EQ(m1.get_time(), 500) << "First inputstream for TimeStamp is incorrect";
      ASSERT_EQ(m2.get_time(), 1000) << "Second inputstream for TimeStamp is incorrect";

      stringstream ss2;
      ss2 << m1 << " " << m2;

      double firstDouble, secondDouble;
      ss2 >> firstDouble >> secondDouble;

      ASSERT_EQ(m1.get_time(), firstDouble) << "First outputstream for TimeStamp is incorrect";
      ASSERT_EQ(m2.get_time(), secondDouble) << "First outputstream for TimeStamp is incorrect";
   }catch(...){
      
   }
   
}