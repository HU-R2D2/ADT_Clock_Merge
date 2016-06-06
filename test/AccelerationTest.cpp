////
//  ██████╗  ██████╗ ██████╗  ██████╗ ██████╗ ███████╗███████╗ ██████╗██╗   ██╗███████╗
//  ██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██║   ██║██╔════╝
//  ██████╔╝██║   ██║██████╔╝██║   ██║██████╔╝█████╗  ███████╗██║     ██║   ██║█████╗  
//  ██╔══██╗██║   ██║██╔══██╗██║   ██║██╔══██╗██╔══╝  ╚════██║██║     ██║   ██║██╔══╝  
//  ██║  ██║╚██████╔╝██████╔╝╚██████╔╝██║  ██║███████╗███████║╚██████╗╚██████╔╝███████╗
//  ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝
//                                                                                                                                          
//
// @file AccelerationTest.cpp
// @date Created: 18-03-2016
// @version 1.0
//
// @author Stephan Vivie
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
////

#include "../source/include/Length.hpp"
#include "../source/include/Acceleration.hpp"

#include <iostream>

#include "gtest/gtest.h"

using namespace r2d2;
static Duration oneSec = 1.0 * Duration::SECOND; // one second
static Speed oneMS = (1.0 * Length::METER) / oneSec; // Speed: one meter er second
static Acceleration oneMA = oneMS / oneSec; // Acceleration: one meter per second 

TEST(Acceleration, DefaultConstructor)
{
    Acceleration accel;
    ASSERT_DOUBLE_EQ(0.0, accel / oneMA);
}

TEST(Acceleration, Assign)
{
    Speed speed = 5.0 * Length::METER / Duration::SECOND;
    Duration duration = 2.0 * Duration::SECOND;

    Acceleration accel = speed / duration;
    ASSERT_DOUBLE_EQ(2.5, accel / oneMA);

}

TEST(Acceleration, MultiplyDouble)
{
    Speed speed = (5.0 * Length::METER) / Duration::SECOND;
    Duration duration = 2.0 * Duration::SECOND;
    Acceleration accel = speed / duration; // 2.5 m/s

    // multiply by 10
    accel = accel * 10.0; // 25 m/s
    ASSERT_DOUBLE_EQ(25.0, accel / oneMA);

    // multiply by 1
    accel = accel * 1.0;
    ASSERT_DOUBLE_EQ(25.0, accel / oneMA);

    // multiply by 0
    accel = accel * 0.0;
    ASSERT_DOUBLE_EQ(0.0, accel / oneMA);

    
}

TEST(Acceleration, MultiplyDoubleAssign)
{
    Speed speed = (5.0 * Length::METER) / Duration::SECOND;
    Duration duration = 2.0 * Duration::SECOND;
    Acceleration accel = speed / duration; // 2.5 m/s

    ASSERT_DOUBLE_EQ(2.5, accel / oneMA);

    // multiply by 10
    accel *= 10.0;
    ASSERT_DOUBLE_EQ(25.0, accel / oneMA);

    // multiply by 1
    accel *= 1.0;
    ASSERT_DOUBLE_EQ(25.0, accel / oneMA);

    // multiply by 0
    accel *= 0.0;
    ASSERT_DOUBLE_EQ(0.0, accel / oneMA);

}

TEST(Acceleration, DivideDouble)
{
    Speed speed = (50.0 * Length::METER) / Duration::SECOND;
    Duration duration = 2.0 * Duration::SECOND;
    Acceleration accel = speed / duration; //25 m/s

    // divide by 10
    accel = accel / 10.0;
    ASSERT_DOUBLE_EQ(2.5, accel / oneMA);

    // divide by 1
    accel = accel / 1.0;
    ASSERT_DOUBLE_EQ(2.5, accel / oneMA);

    // divide by 0
    accel = accel / 0.0;
    ASSERT_DOUBLE_EQ(2.5, accel / oneMA);

}

TEST(Acceleration, DivideDoubleAssign)
{
    Speed speed = (50.0* Length::METER) / Duration::SECOND;
    Duration duration = 2.0 * Duration::SECOND;
    Acceleration accel = speed / duration; //2.5 m/s

    ASSERT_DOUBLE_EQ(25.0, accel / oneMA);

    // dividee by 10
    accel /= 10.0;
    ASSERT_DOUBLE_EQ(2.5, accel / oneMA);

    // divide by 0
    accel /= 0.0;
    ASSERT_DOUBLE_EQ(2.5, accel / oneMA);

    // divide by 1
    accel /= 1.0;
    ASSERT_DOUBLE_EQ(2.5, accel / oneMA);
}

TEST(Acceleration, GreaterThan)
{
    Speed speed = (5.0 * Length::METER) / Duration::SECOND;
    Duration duration = 2.0 * Duration::SECOND;
    Acceleration accel = speed / duration; //2.5 m/s

    Speed fasterSpeed = (50.0 * Length::METER) / Duration::SECOND;
    Acceleration fasterAccel = fasterSpeed / duration; //25 m/s

    ASSERT_TRUE(fasterAccel > accel);
    ASSERT_FALSE(accel > fasterAccel);

    

}

TEST(Acceleration, LessThan)
{
    Speed speed = (5.0 * Length::METER) / Duration::SECOND;
    Duration duration = 2.0 * Duration::SECOND;
    Acceleration accel = speed / duration; //2.5 m/s

    Speed fasterSpeed = (50.0 * Length::METER) / Duration::SECOND;
    Acceleration fasterAccel = fasterSpeed / duration; //25 m/s

    ASSERT_TRUE(accel < fasterAccel);
    ASSERT_FALSE(fasterAccel < accel);
}


TEST(Acceleration, OutputStream)
{
    std::stringstream stream{};
    Speed speed = (5.0 * Length::METER) / Duration::SECOND;
    Duration duration = 2.0 * Duration::SECOND;
    Acceleration accel = speed / duration; //2.5 m/s
    stream << accel << std::endl;

    std::string output;
    std::getline(stream, output);

    EXPECT_EQ("2.5m/s/s", output);
    EXPECT_EQ(&stream, &(stream << accel)) << "Wrong stream is returned.";
    
}


TEST(Acceleration, InputStream)
{
    std::stringstream stream{};
    Speed speed = (5.0 * Length::METER) / Duration::SECOND;
    Duration duration = 2.0 * Duration::SECOND;
    Acceleration accel = speed / duration; //2.5 m/s

    // Check whether the coordinate is read in correct form from the stream.
    stream << "2.5m/s/s";
    stream >> accel;

    ASSERT_DOUBLE_EQ(2.5, accel / oneMA);

}


