//! @file <LengthTest.cpp>
//! @date Created: <5-3-16>
//! @version <1.0.1>
//!
//! @author <Remco Nijkamp & Koen de Groot>
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
#include "../source/include/Length.hpp"
#include <iostream>
using namespace r2d2;
// constructors:
TEST(Length, DefaultConstructor) {
    Length a;
    ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "length";
}

TEST(Length, doubleConstructor) {
    Length a(2 * Length::METER);
    ASSERT_DOUBLE_EQ(a/Length::METER , 2) << "length";
}

// operatoren:
TEST(Length, AssignLength){
    Length a;
    a = 2 * Length::METER;
    ASSERT_DOUBLE_EQ(a/Length::METER , 2) << "empty l";
}

TEST(Length, AddLength) {
    Length a = 0 * Length::METER;
    Length b;
    a = a + b;
    ASSERT_DOUBLE_EQ(a/Length::METER , 0.0) << "empty+empty";
	
    Length c = 2 * Length::METER;
    b = b + c;
    ASSERT_DOUBLE_EQ(b/Length::METER , 2.0) << "empty+full";
	
    Length d = 3 * Length::METER;
    d = d + c;
    ASSERT_DOUBLE_EQ(d/Length::METER , 5.0) << "full+full";
}

TEST(Length, SubstractLength) {
    Length a{};
    Length b;
    a = a - b;
    ASSERT_DOUBLE_EQ(a/Length::METER , 0.0) << "empty-empty";
	
    Length c = 2 * Length::METER;
    b = b - c;
    ASSERT_DOUBLE_EQ(b/Length::METER , -2.0) << "empty-full";
	
    c = c - a;
    ASSERT_DOUBLE_EQ(c/Length::METER , 2.0) << "full-empty";
	
    Length d = 1 * Length::METER;
    d = d - c;
    ASSERT_DOUBLE_EQ(d/Length::METER , -1.0) << "full-full neg";
    Length e= 3 * Length::METER;
    Length f= 2 * Length::METER;
    e = e - f;
    ASSERT_DOUBLE_EQ(e/Length::METER , 1.0) << "full-full";
}

TEST(Length, MultiplyLengthDouble) {
    double getal1 = 2;
    double getal2 = 2.5;
	
    Length a;
    a = a * 0;
    ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "empty*0 Length";
	
    a = a * getal1;
    ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "empty Length";
		
    Length b =1 * Length::METER;
    b = b * 0;
    ASSERT_DOUBLE_EQ(b/Length::METER , 0) << "full*0 Length";
		
    Length c =2 * Length::METER;
    c = c * getal1;
    ASSERT_DOUBLE_EQ(c/Length::METER , 4) << "full*getal1 Length";
	
    Length d =3  * Length::METER;
    d = d * getal2;
    ASSERT_DOUBLE_EQ(d/Length::METER , 7.5) << "full * getal2 Length";

}

TEST(Length, MultiplyDoubleLength) {
    double getal1 = 2;
    double getal2 = 2.5;
	
    Length a;
    a = 0 * a;
    ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "empty*0 Length";
	
    a = getal1 * a;
    ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "empty Length";
		
    Length b =1 * Length::METER;
    b = 0 * b;
    ASSERT_DOUBLE_EQ(b/Length::METER , 0) << "full*0 Length";
		
    Length c =2 * Length::METER;
    c = getal1 * c;
    ASSERT_DOUBLE_EQ(c/Length::METER , 4) << "full*getal1 Length";
	
    Length d =3  * Length::METER;
    d = getal2 * d;
    ASSERT_DOUBLE_EQ(d/Length::METER , 7.5) << "full * getal2 Length";
}

TEST(Length, DivideDouble) {
    double getal1 = 2;
    double getal2 = 2.5;
	
    Length a;
    a = a / 0;
    ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "empty / 0 Length";
	
    a = a / getal1;
    ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "empty x";
	
    Length b = 1 * Length::METER;
    b = b / 0;
    ASSERT_DOUBLE_EQ(b/Length::METER , 1) << "full / 0 Length";
	
    Length c = 1 * Length::METER;
    c = c / getal1;
    ASSERT_DOUBLE_EQ(c/Length::METER , 0.5) << "full / getal1 Length";
	
    Length d =1 * Length::METER;
    d = d / getal2;
    ASSERT_DOUBLE_EQ(d/Length::METER , 0.4) << "full / getal2 Length ";	
}

TEST(Length, DivideLength) {
    Length a;
    Length d;
    Length b = 4 * Length::METER;
    Length c = 2 * Length::METER;
	
    double z = a / d;
    ASSERT_DOUBLE_EQ(z , 0) << "empty / empty";	
	
    z = b / a;
    ASSERT_DOUBLE_EQ(z , 4) << "full / empty";
	
    z = b / c;
    ASSERT_DOUBLE_EQ(z , 2) << "full / full";	
}

TEST(Length, AddAssignLength) {
    Length a;
    Length b;
    a += b;
    ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "empty+empty";
	
    Length c = 2  * Length::METER;
    b += c;
    ASSERT_DOUBLE_EQ(b/Length::METER , 2) << "empty+full";

    Length d = 3 * Length::METER;
    d += c;
    ASSERT_DOUBLE_EQ(d/Length::METER , 5) << "full+full"; 
}

TEST(Length, SubtractAssignLength) {
    Length a;
    Length b;
    a -= b;
    ASSERT_DOUBLE_EQ(a/Length::METER , 0) << "empty-empty";
	
    Length c = 2  * Length::METER;
    b -= c;
    ASSERT_DOUBLE_EQ(b/Length::METER , -2) << "empty-full";
	
    c -= a;
    ASSERT_DOUBLE_EQ(c/Length::METER , 2) << "full-empty";

    Length d = 1 * Length::METER;
    d -= c;
    ASSERT_DOUBLE_EQ(d/Length::METER , -1) << "full-full neg";
    Length e = 5 * Length::METER;
    Length f = 3 * Length::METER;
    e -= f;
    ASSERT_DOUBLE_EQ(e/Length::METER , 2) << "full-full";
}	

TEST(Length, GreaterThan) {
    Length a(2 * Length::METER);
    Length b(1 * Length::METER);
    ASSERT_TRUE(a > b) << "greater than";
    ASSERT_FALSE(b > a) << "less than";
}

TEST(Length, LessThan) {
    Length a(1 * Length::METER);
    Length b(2 * Length::METER);
    ASSERT_TRUE(a < b) << "greater than";
    ASSERT_FALSE(b < a) << "less than";
}

TEST(Length, OutputStream) {
    Length a(1 * Length::METER);
    std::stringstream stream{};
    stream << a << std::endl;
    std::string output;
    std::getline(stream, output);
    EXPECT_EQ("1m", output);
}

TEST(Length, ReadFrom) {
    std::stringstream stream{};
    Length l;
    stream << "15m";
    stream >> l;
    ASSERT_DOUBLE_EQ(l/Length::METER , 15);
}