//! @file <DurationTest.cpp>
//! @date Created: <5-3-16>
//! @version <1.0.0>
//!
//! @author <Remco Nijkamp>
//!
//! @section LICENSE
//! License: newBSD
//!
//! Copyright © 2016, HU University of Applied Sciences Utrecht.
//! All rights reserved.
//!
//! Redistribution and use in source and binary forms, 
//! with or without modification, are permitted provided that 
//! the following conditions are met:
//! - Redistributions of source code must retain the above copyright notice, 
//!   this list of conditions and the following disclaimer.
//! - Redistributions in binary form must reproduce the above copyright notice, 
//!   this list of conditions and the following disclaimer in the documentation 
//!   and/or other materials provided with the distribution.
//! - Neither the name of the HU University of Applied Sciences Utrecht nor 
//!   the names of its contributors may be used to endorse or promote products 
//!   derived from this software without specific prior written permission.
//!
//! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//! "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, 
//! BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
//! FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY
//! OF APPLIED SCIENCES UTRECHT BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//! SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//! PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
//! OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
//! WHETHER IN CONTRACT, STRICT LIABILITY,
//! OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF 
//! THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "gtest/gtest.h"
#include "../source/include/Duration.hpp"
#include <iostream>
using namespace r2d2;
TEST(Duration, DefaultConstructor) {
    Duration a;
    ASSERT_DOUBLE_EQ(a.get_seconds() , 0.0) << "seconds";
}

TEST(Duration, ConstructorDouble) {
    Duration a(2 * Duration::SECOND);
    ASSERT_DOUBLE_EQ(a.get_seconds() , 2.0) << "seconds";
}

TEST( Duration, AssignDuration ){
    Duration a;
    a = 1 * Duration::SECOND;
    ASSERT_DOUBLE_EQ(a.get_seconds()  , 1.0) << "empty seconds";
        
    a = 4 * Duration::SECOND;
    ASSERT_DOUBLE_EQ(a.get_seconds()  , 4.0) << "new seconds"; 
}

TEST(Duration, AddDuration) {
    Duration a;
    Duration b;
    a = a + b;
    ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "empty+empty seconds";

    Duration c = 1 * Duration::SECOND;
    b = b + c;
    ASSERT_DOUBLE_EQ(b.get_seconds()  , 1.0) << "empty+full seconds";
	
    Duration d = 1 * Duration::SECOND;
    Duration e = 4 * Duration::SECOND;
    d = d + e;
    ASSERT_DOUBLE_EQ(d.get_seconds()  , 5.0) << "full+full seconds";
}

TEST(Duration, SubstractDuration) {
    Duration a;
    Duration b;
    a = a - b;
    ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "empty-empty seconds";
        
    Duration c = 1 * Duration::SECOND;
    b = b - c;
    ASSERT_DOUBLE_EQ(b.get_seconds()  , -1.0) << "empty-full seconds";
        
    Duration d = 1 * Duration::SECOND;
    Duration e;
    d = d - e;
    ASSERT_DOUBLE_EQ(d.get_seconds()  , 1.0) << "full-empty seconds";
        
    Duration f = 4 * Duration::SECOND;
    Duration g = 1 * Duration::SECOND;
    f = f - g;
    ASSERT_DOUBLE_EQ(f.get_seconds()  , 3.0) << "full-full seconds";
}

TEST(Duration, MultiplyDurationDouble) {
    double getal1 = 2.0;
    double getal2 = 2.5;
        
    Duration a;
    a = a * 0;
    ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "empty*0 seconds";
        
    a = a * getal1;
    ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "empty*getal1 seconds";

    Duration b = 1 * Duration::SECOND;
    b = b * 0;
    ASSERT_DOUBLE_EQ(b.get_seconds()  , 0.0) << "full*0 seconds";
        
    Duration c = 1 * Duration::SECOND;
    c = c * getal1;
    ASSERT_DOUBLE_EQ(c.get_seconds()  , 2.0) << "full*getal1 seconds";
        
    Duration d = 1 * Duration::SECOND;
    d = d * getal2;
    ASSERT_DOUBLE_EQ(d.get_seconds()  , 2.5) << "full*getal2 seconds";
}

TEST(Duration, MultiplyDoubleDuration) {
    double getal1 = 2.0;
    double getal2 = 2.5;

    Duration a;
    a = 0 * a;
    ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "0*empty seconds";
        
    a = getal1 * a;
    ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "getal1*empty seconds";
        
    Duration b = 1 * Duration::SECOND;
    b = 0 * b;
    ASSERT_DOUBLE_EQ(b.get_seconds()  , 0.0) << "0*full seconds";
        
    Duration c = 1 * Duration::SECOND;
    c = getal1 * c;
    ASSERT_DOUBLE_EQ(c.get_seconds()  , 2.0) << "getal1*full seconds";
        
    Duration d = 1 * Duration::SECOND;
    d = getal2 * d;
    ASSERT_DOUBLE_EQ(d.get_seconds()  , 2.5) << "getal2*full seconds";
}

TEST(Duration, DivideDurationDouble) {
    double getal1 = 2.0;
    double getal2 = 2.5;
        
    Duration a;
    a = a / 0;
    ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "empty/0 seconds";

    a = a / getal1;
    ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "empty/getal1 seconds";
        
    Duration b = 1 * Duration::SECOND;
    b = b / 0;
    ASSERT_DOUBLE_EQ(b.get_seconds()  , 1.0) << "full/0 seconds";
        
    Duration c = 1 * Duration::SECOND;
    c = c / getal1;
    ASSERT_DOUBLE_EQ(c.get_seconds()  , 0.5) << "full/getal1 seconds";
        
    Duration d = 1 * Duration::SECOND;
    d = d / getal2;
    ASSERT_DOUBLE_EQ(d.get_seconds()  , 0.4) << "full/getal2 seconds";
}

TEST(Duration, AddAssignDuration) {
    Duration a;
    Duration b;
    a += b;
    ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "empty+empty seconds";
        
    Duration c = 1 * Duration::SECOND;
    b += c;
    ASSERT_DOUBLE_EQ(b.get_seconds()  , 1.0) << "empty+full seconds";

    Duration d = 1 * Duration::SECOND;
    Duration e = 4 * Duration::SECOND;
    d += e;
    ASSERT_DOUBLE_EQ(d.get_seconds()  , 5.0) << "full+full seconds"; 
}

TEST(Duration, SubstractAssignDuration) {
    Duration a;
    Duration b;
    a -= b;
    ASSERT_DOUBLE_EQ(a.get_seconds()  , 0.0) << "empty-empty seconds";
        
    Duration c = 1 * Duration::SECOND;
    b -= c;
    ASSERT_DOUBLE_EQ(b.get_seconds()  , -1.0) << "empty-full seconds";
        
    Duration d = 1 * Duration::SECOND;
    Duration e;
    d -= e;
    ASSERT_DOUBLE_EQ(d.get_seconds()  , 1.0) << "full-empty seconds";
        
    Duration f = 4 * Duration::SECOND;
    Duration g = 1 * Duration::SECOND;
    f -= g;
    ASSERT_DOUBLE_EQ(f.get_seconds()  , 3.0) << "full-full seconds";
}

TEST(Duration, GreaterThan) {
    Duration a = 2 * Duration::SECOND;
    Duration b = 1 * Duration::SECOND;
    ASSERT_TRUE(a > b) << "greater than";
    ASSERT_FALSE(b > a) << "less than";
}

TEST(Duration, LessThan) {
    Duration a = 1 * Duration::SECOND;
    Duration b = 2 * Duration::SECOND;
    ASSERT_TRUE(a < b) << "less than";
    ASSERT_FALSE(b < a) << "greater than";
}

TEST(Duration, OutputStream) {
    Duration a = 1 * Duration::SECOND;
    std::stringstream stream{};
    stream << a << std::endl;
    std::string output;
    std::getline(stream, output);
    EXPECT_EQ("1s", output);
}

TEST(Duration, ReadFrom) {
    std::stringstream stream{};
    Duration d;
    const Duration * const originalPointer = &d;

    stream << "Duration 15s";
    stream >> d;
    ASSERT_DOUBLE_EQ(15.0, d.get_seconds());
    ASSERT_EQ(originalPointer, &d) << "A wrong reference is returned.";
}