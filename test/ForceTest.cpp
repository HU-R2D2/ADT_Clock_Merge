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
#include "../source/include/Force.hpp"
#include "gtest/gtest.h"
#include <iostream>
//Constructors


//static const Speed one = 1 * Length::METER/Duration::SECOND;
//static const Acceleration ac = one/Duration::SECOND;
//static const Force Force::NEWTON = 1 * Weight::KILOGRAM * ac;
//Assign

using namespace r2d2;
TEST(Force, Assign){
	Force a = 5 * Force::NEWTON;
	ASSERT_DOUBLE_EQ(a/(Force::NEWTON), 5) << "Force created";
	Force b = 7 * Force::NEWTON;
	a = b;
	ASSERT_DOUBLE_EQ(a/(Force::NEWTON), 7) << "assigned other Force to a Force";
}


TEST(Force, Divide){
	Force d = 5 * Mass::KILOGRAM * (1 * Length::METER/Duration::SECOND/Duration::SECOND);
	Force a = 4 * Force::NEWTON;
	Force b = 8 * Force::NEWTON;
	Force c = -16 * Force::NEWTON;
	ASSERT_DOUBLE_EQ(d/Force::NEWTON, 5);
	ASSERT_DOUBLE_EQ(b/a, 2) << "Divide positive by positive";
	ASSERT_DOUBLE_EQ(c/b, -2) << "Divide negative by positive";
}

//Smaller
TEST(Force, Smaller){
	Force a = 8 * Force::NEWTON;
	Force b = 6 * Force::NEWTON;
	EXPECT_EQ(a < b, false) << "a not smaller than b";
	EXPECT_EQ(b < a, true) <<  "b is smaller than a";
}

//Bigger
TEST(Force, Bigger){
	Force a = 6 * Force::NEWTON;
	Force b = 8 * Force::NEWTON;
	EXPECT_EQ(a > b, false) << "a not greater than b";
	EXPECT_EQ(b > a, true) <<  "b is greater than a";
}

//onedd
TEST(Force, Add){
	Force a = 3 * Force::NEWTON;
	Force b = 6 * Force::NEWTON;
	Force c = 0 * Force::NEWTON;
	Force d = -10 * Force::NEWTON;
	a = a + c;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 3) << "zero + a Force";
	a = a + b;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 9) << "positive + positive";
	a = a + d;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), -1) << "negative + positive";
	a = a + d;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), -11) << "negative + negative";
	a = a + b;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), -5) << "negative + negative";
}


//AddAssign
TEST(Force, AddAssign){
	Force a = 6 * Force::NEWTON;
	Force b = 5 * Force::NEWTON;
	a += b;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 11) << "AddAssign Force"; 
}

//Subtract
TEST(Force, Subtract){
	Force a = 3 * Force::NEWTON;
	Force b = 6 * Force::NEWTON;
	Force c = 0 * Force::NEWTON;
	Force d = -10* Force::NEWTON;
	a = a - c;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 3) << "positive - zero";
	a = a - b;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), -3) << "positive - positive";
	a = a - d;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 7) << "negative - negative";
	a = a - d;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 17) << "negative - positive";
}


//SubtractAssign
TEST(Force, SubtractAssign){
	Force a = 6 * Force::NEWTON;
	Force b = 5 * Force::NEWTON;
	a -= b;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 1) << "SubtractAssign Force"; 
	
}


//Multiply by double

TEST(Force,MultiplyDouble){
	Force a = 8 * Force::NEWTON;
	double pos = 2;
	a = a * pos;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON),16) << "Multiply positive by positive";
	a = -8 * Force::NEWTON;
	a = a * pos;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON),-16) << "Multiply negative by positive";
	double neg = -2;
	a = a * neg;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON),32) << "Multiply negative by negative";
	a = a * neg;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON),-64) << "Multiply positive by negative";
	double z = 0;
	a = a * z;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 0) << "Multiply by zero";
	a = 8 * Force::NEWTON;
	a = pos * a;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON),16) << "positive * positive rhs";
	a = -8 * Force::NEWTON;
	a = pos * a;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON),-16) << "negative * positive rhs";
	a = neg * a;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON),32) << "negative * negative rhs";
	a = neg * a;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON),-64) << "positive * negative rhs";
	a = z * a;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 0) << "Multiply by zero rhs";
}


//MultiplyAssign by double
TEST(Force, MultiplyAssignDouble){
	Force a = 6 * Force::NEWTON;
	double d = 7;
	a = a * d;
	EXPECT_DOUBLE_EQ(a/(Force::NEWTON), 42) << "MultiplyAssign Force"; 
	
}

TEST(Force, WriteTo){
   std::stringstream stream{};
   Force s = 5 * Force::NEWTON;
   stream << s << std::endl;
   std::string output;
   std::getline(stream, output);
   EXPECT_EQ("5N", output);
   EXPECT_EQ(&stream, &(stream << s)) << "Wrong stream is returned.";
}


TEST(Force, ReadFrom){
	std::stringstream stream{};
	const Force meter_per_second = Force::NEWTON;
	Force Force = meter_per_second;

	// Check whether the coordinate is read in correct form from the stream.
	stream << "15N";
	stream >> Force;
	ASSERT_DOUBLE_EQ(15, Force / meter_per_second);
	
}

