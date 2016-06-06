//!	Roborescue
//! @file <TranslationTest.cpp>
//! @date Created: <5-3-16>
//! @version <1.0.1>
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
#include "../source/include/Translation.hpp"
#include "../source/include/Length.hpp"
#include <iostream>
using namespace r2d2;
TEST(Translation, DefaultConstructor) {
    Translation a;
    ASSERT_DOUBLE_EQ(a.get_x() / Length::METER , 0.0) << "x";
    ASSERT_DOUBLE_EQ(a.get_y() / Length::METER , 0.0) << "y";
    ASSERT_DOUBLE_EQ(a.get_z() / Length::METER , 0.0) << "z";
}

TEST(Translation, ConstructorDouble) {
    Translation a(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    ASSERT_DOUBLE_EQ(a.get_x() / Length::METER , 1.0) << "x";
    ASSERT_DOUBLE_EQ(a.get_y() / Length::METER , 2.0) << "y";
    ASSERT_DOUBLE_EQ(a.get_z() / Length::METER , 3.0) << "z";
}

TEST( Translation, AssignTranslation ){
    Translation a;
    a = Translation(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
        
    ASSERT_DOUBLE_EQ(a.get_x() / Length::METER , 1.0) << "empty x";
    ASSERT_DOUBLE_EQ(a.get_y() / Length::METER , 2.0) << "empty y";
    ASSERT_DOUBLE_EQ(a.get_z() / Length::METER , 3.0) << "empty z";
        
    a = Translation(4 * Length::METER, 5 * Length::METER, 6 * Length::METER);
    ASSERT_DOUBLE_EQ(a.get_x() / Length::METER , 4.0) << "new x";
    ASSERT_DOUBLE_EQ(a.get_y() / Length::METER , 5.0) << "new y";
    ASSERT_DOUBLE_EQ(a.get_z() / Length::METER , 6.0) << "new z";  
}

TEST(Translation, AddTranslation) {
    Translation a;
    Translation b;
    a = a + b;
    ASSERT_DOUBLE_EQ(a.get_x() / Length::METER , 0.0) << "empty+empty x";
    ASSERT_DOUBLE_EQ(a.get_y() / Length::METER , 0.0) << "empty+empty y";
    ASSERT_DOUBLE_EQ(a.get_z() / Length::METER , 0.0) << "empty+empty z";
        
    Translation c(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    b = b + c;
    ASSERT_DOUBLE_EQ(b.get_x() / Length::METER , 1.0) << "empty+full x";
    ASSERT_DOUBLE_EQ(b.get_y() / Length::METER , 2.0) << "empty+full y";
    ASSERT_DOUBLE_EQ(b.get_z() / Length::METER , 3.0) << "empty+full z";
        
    Translation d(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    Translation e(4 * Length::METER, 5 * Length::METER, 6 * Length::METER);
    d = d + e;
    ASSERT_DOUBLE_EQ(d.get_x() / Length::METER , 5.0) << "full+full x";
    ASSERT_DOUBLE_EQ(d.get_y() / Length::METER , 7.0) << "full+full y";
    ASSERT_DOUBLE_EQ(d.get_z() / Length::METER , 9.0) << "full+full z";
}

TEST(Translation, SubstractTranslation) {
    Translation a;
    Translation b;
    a = a - b;
    ASSERT_DOUBLE_EQ(a.get_x() / Length::METER , 0.0) << "empty-empty x";
    ASSERT_DOUBLE_EQ(a.get_y() / Length::METER , 0.0) << "empty-empty y";
    ASSERT_DOUBLE_EQ(a.get_z() / Length::METER , 0.0) << "empty-empty z";
        
    Translation c(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    b = b - c;
    ASSERT_DOUBLE_EQ(b.get_x() / Length::METER , -1.0) << "empty-full x";
    ASSERT_DOUBLE_EQ(b.get_y() / Length::METER , -2.0) << "empty-full y";
    ASSERT_DOUBLE_EQ(b.get_z() / Length::METER , -3.0) << "empty-full z";

    Translation d(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    Translation e;
    d = d - e;
    ASSERT_DOUBLE_EQ(d.get_x() / Length::METER , 1.0) << "full-empty x";
    ASSERT_DOUBLE_EQ(d.get_y() / Length::METER , 2.0) << "full-empty y";
    ASSERT_DOUBLE_EQ(d.get_z() / Length::METER , 3.0) << "full-empty z";
        
    Translation f(4 * Length::METER, 5 * Length::METER, 6 * Length::METER);
    Translation g(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    f = f - g;
    ASSERT_DOUBLE_EQ(f.get_x() / Length::METER , 3.0) << "full-full x";
    ASSERT_DOUBLE_EQ(f.get_y() / Length::METER , 3.0) << "full-full y";
    ASSERT_DOUBLE_EQ(f.get_z() / Length::METER , 3.0) << "full-full z";
}

TEST(Translation, MultiplyTranslationDouble) {
    double getal1 = 2;
    double getal2 = 2.5;
        
    Translation a;
    a = a * 0;
    ASSERT_DOUBLE_EQ(a.get_x() / Length::METER , 0.0) << "empty*0 x";
    ASSERT_DOUBLE_EQ(a.get_y() / Length::METER , 0.0) << "empty*0 y";
    ASSERT_DOUBLE_EQ(a.get_z() / Length::METER , 0.0) << "empty*0 z";
        
    a = a * getal1;
    ASSERT_DOUBLE_EQ(a.get_x() / Length::METER , 0.0) << "empty*getal1 x";
    ASSERT_DOUBLE_EQ(a.get_y() / Length::METER , 0.0) << "empty*getal1 y";
    ASSERT_DOUBLE_EQ(a.get_z() / Length::METER , 0.0) << "empty*getal1 z";
        
    Translation b(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    b = b * 0;
    ASSERT_DOUBLE_EQ(b.get_x() / Length::METER , 0.0) << "full*0 x";
    ASSERT_DOUBLE_EQ(b.get_y() / Length::METER , 0.0) << "full*0 y";
    ASSERT_DOUBLE_EQ(b.get_z() / Length::METER , 0.0) << "full*0 z";
        
    Translation c(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    c = c * getal1;
    ASSERT_DOUBLE_EQ(c.get_x() / Length::METER , 2.0) << "full*getal1 x";
    ASSERT_DOUBLE_EQ(c.get_y() / Length::METER , 4.0) << "full*getal1 y";
    ASSERT_DOUBLE_EQ(c.get_z() / Length::METER , 6.0) << "full*getal1 z";
        
    Translation d(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    d = d * getal2;
    ASSERT_DOUBLE_EQ(d.get_x() / Length::METER , 2.5) << "full*getal2 x";
    ASSERT_DOUBLE_EQ(d.get_y() / Length::METER , 5.0) << "full*getal2 y";
    ASSERT_DOUBLE_EQ(d.get_z() / Length::METER , 7.5) << "full*getal2 z";
}

TEST(Translation, MultiplyDoubleTranslation) {
    double getal1 = 2;
    double getal2 = 2.5;

    Translation a;
    a = 0 * a;
    ASSERT_DOUBLE_EQ(a.get_x() / Length::METER , 0.0) << "0*empty x";
    ASSERT_DOUBLE_EQ(a.get_y() / Length::METER , 0.0) << "0*empty y";
    ASSERT_DOUBLE_EQ(a.get_z() / Length::METER , 0.0) << "0*empty z";
	
    a = getal1 * a;
    ASSERT_DOUBLE_EQ(a.get_x() / Length::METER , 0.0) << "getal1*empty x";
    ASSERT_DOUBLE_EQ(a.get_y() / Length::METER , 0.0) << "getal1*empty y";
    ASSERT_DOUBLE_EQ(a.get_z() / Length::METER , 0.0) << "getal1*empty z";
        
    Translation b(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    b = 0 * b;
    ASSERT_DOUBLE_EQ(b.get_x() / Length::METER , 0.0) << "0*full x";
    ASSERT_DOUBLE_EQ(b.get_y() / Length::METER , 0.0) << "0*full y";
    ASSERT_DOUBLE_EQ(b.get_z() / Length::METER , 0.0) << "0*full z";
        
    Translation c(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    c = getal1 * c;
    ASSERT_DOUBLE_EQ(c.get_x() / Length::METER , 2.0) << "getal1*full x";
    ASSERT_DOUBLE_EQ(c.get_y() / Length::METER , 4.0) << "getal1*full y";
    ASSERT_DOUBLE_EQ(c.get_z() / Length::METER , 6.0) << "getal1*full z";
        
    Translation d(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    d = getal2 * d;
    ASSERT_DOUBLE_EQ(d.get_x() / Length::METER , 2.5) << "getal2*full x";
    ASSERT_DOUBLE_EQ(d.get_y() / Length::METER , 5.0) << "getal2*full y";
    ASSERT_DOUBLE_EQ(d.get_z() / Length::METER , 7.5) << "getal2*full z";
}

TEST(Translation, DivideTranslationDouble) {
    double getal1 = 2;
    double getal2 = 2.5;
        
    Translation a;
    a = a / 0;			// dit mag niet, dus niks doen!
    ASSERT_DOUBLE_EQ(a.get_x() / Length::METER , 0.0) << "empty/0 x";
    ASSERT_DOUBLE_EQ(a.get_y() / Length::METER , 0.0) << "empty/0 y";
    ASSERT_DOUBLE_EQ(a.get_z() / Length::METER , 0.0) << "empty/0 z";
        
    a = a / getal1;
    ASSERT_DOUBLE_EQ(a.get_x() / Length::METER , 0.0) << "empty/getal1 x";
    ASSERT_DOUBLE_EQ(a.get_y() / Length::METER , 0.0) << "empty/getal1 y";
    ASSERT_DOUBLE_EQ(a.get_z() / Length::METER , 0.0) << "empty/getal1 z";
        
    Translation b(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    b = b / 0;			// dit mag niet, dus niks doen!
    ASSERT_DOUBLE_EQ(b.get_x() / Length::METER , 1.0) << "full/0 x";
    ASSERT_DOUBLE_EQ(b.get_y() / Length::METER , 2.0) << "full/0 y";
    ASSERT_DOUBLE_EQ(b.get_z() / Length::METER , 3.0) << "full/0 z";
        
    Translation c(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    c = c / getal1;
    ASSERT_DOUBLE_EQ(c.get_x() / Length::METER , 0.5) << "full/getal1 x";
    ASSERT_DOUBLE_EQ(c.get_y() / Length::METER , 1.0) << "full/getal1 y";
    ASSERT_DOUBLE_EQ(c.get_z() / Length::METER , 1.5) << "full/getal1 z";
        
    Translation d(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    d = d / getal2;
    ASSERT_DOUBLE_EQ(d.get_x() / Length::METER , 0.4) << "full/getal2 x";
    ASSERT_DOUBLE_EQ(d.get_y() / Length::METER , 0.8) << "full/getal2 y";
    ASSERT_DOUBLE_EQ(d.get_z() / Length::METER , 1.2) << "full/getal2 z";
}

TEST(Translation, DivideDoubleTranslation) {
    double getal1 = 2;
    double getal2 = 2.5;
	
    Translation a;
    a = 0 / a;
    ASSERT_DOUBLE_EQ(a.get_x() / Length::METER , 0.0) << "0/empty x";
    ASSERT_DOUBLE_EQ(a.get_y() / Length::METER , 0.0) << "0/empty y";
    ASSERT_DOUBLE_EQ(a.get_z() / Length::METER , 0.0) << "0/empty z";
        
    a = getal1 / a;
    ASSERT_DOUBLE_EQ(a.get_x() / Length::METER , 0.0) << "getal1/empty x";
    ASSERT_DOUBLE_EQ(a.get_y() / Length::METER , 0.0) << "getal1/empty y";
    ASSERT_DOUBLE_EQ(a.get_z() / Length::METER , 0.0) << "getal1/empty z";
        
    Translation b(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    b = 0 / b ;
    ASSERT_DOUBLE_EQ(b.get_x() / Length::METER , 0.0) << "0/full x";
    ASSERT_DOUBLE_EQ(b.get_y() / Length::METER , 0.0) << "0/full y";
    ASSERT_DOUBLE_EQ(b.get_z() / Length::METER , 0.0) << "0/full z";
        
    Translation c(1 * Length::METER, 2 * Length::METER, 4 * Length::METER);
    c = getal1 / c;
    ASSERT_DOUBLE_EQ(c.get_x() / Length::METER , 2.0) << "getal1/full x";
    ASSERT_DOUBLE_EQ(c.get_y() / Length::METER , 1.0) << "getal1/full y";
    ASSERT_DOUBLE_EQ(c.get_z() / Length::METER , 0.5) << "getal1/full z";
        
    Translation d(1 * Length::METER, 2 * Length::METER, 5 * Length::METER);
    d = getal2 / d;
    ASSERT_DOUBLE_EQ(d.get_x() / Length::METER , 2.5) << "getal2/full x";
    ASSERT_DOUBLE_EQ(d.get_y() / Length::METER , 1.25) << "getal2/full y";
    ASSERT_DOUBLE_EQ(d.get_z() / Length::METER , 0.5) << "getal2/full z";
}

TEST(Translation, AddAssignTranslation) {
    Translation a;
    Translation b;
    a += b;
    ASSERT_DOUBLE_EQ(a.get_x() / Length::METER , 0.0) << "empty+empty x";
    ASSERT_DOUBLE_EQ(a.get_y() / Length::METER , 0.0) << "empty+empty y";
    ASSERT_DOUBLE_EQ(a.get_z() / Length::METER , 0.0) << "empty+empty z";
        
    Translation c(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    b += c;
    ASSERT_DOUBLE_EQ(b.get_x() / Length::METER , 1.0) << "empty+full x";
    ASSERT_DOUBLE_EQ(b.get_y() / Length::METER , 2.0) << "empty+full y";
    ASSERT_DOUBLE_EQ(b.get_z() / Length::METER , 3.0) << "empty+full z";
        
    Translation d(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    Translation e(4 * Length::METER, 5 * Length::METER, 6 * Length::METER);
    d += e;
    ASSERT_DOUBLE_EQ(d.get_x() / Length::METER , 5.0) << "full+full x";
    ASSERT_DOUBLE_EQ(d.get_y() / Length::METER , 7.0) << "full+full y";
    ASSERT_DOUBLE_EQ(d.get_z() / Length::METER , 9.0) << "full+full z"; 
}

TEST(Translation, SubstractAssignTranslation) {
    Translation a;
    Translation b;
    a -= b;
    ASSERT_DOUBLE_EQ(a.get_x() / Length::METER , 0.0) << "empty-empty x";
    ASSERT_DOUBLE_EQ(a.get_y() / Length::METER , 0.0) << "empty-empty y";
    ASSERT_DOUBLE_EQ(a.get_z() / Length::METER , 0.0) << "empty-empty z";
        
    Translation c(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    b -= c;
    ASSERT_DOUBLE_EQ(b.get_x() / Length::METER , -1.0) << "empty-full x";
    ASSERT_DOUBLE_EQ(b.get_y() / Length::METER , -2.0) << "empty-full y";
    ASSERT_DOUBLE_EQ(b.get_z() / Length::METER , -3.0) << "empty-full z";
        
    Translation d(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    Translation e;
    d -= e;
    ASSERT_DOUBLE_EQ(d.get_x() / Length::METER , 1.0) << "full-empty x";
    ASSERT_DOUBLE_EQ(d.get_y() / Length::METER , 2.0) << "full-empty y";
    ASSERT_DOUBLE_EQ(d.get_z() / Length::METER , 3.0) << "full-empty z";
        
    Translation f(4 * Length::METER, 5 * Length::METER, 6 * Length::METER);
    Translation g(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    f -= g;
    ASSERT_DOUBLE_EQ(f.get_x() / Length::METER , 3.0) << "full-full x";
    ASSERT_DOUBLE_EQ(f.get_y() / Length::METER , 3.0) << "full-full y";
    ASSERT_DOUBLE_EQ(f.get_z() / Length::METER , 3.0) << "full-full z";
}

TEST(Translation, GreaterThan) {
    Translation a(2 * Length::METER, 2 * Length::METER, 2 * Length::METER);
    Translation b(1 * Length::METER, 1 * Length::METER, 1 * Length::METER);
    ASSERT_TRUE(a > b) << "greater than";
    ASSERT_FALSE(b > a) << "less than";
}

TEST(Translation, LessThan) {
    Translation a(1 * Length::METER, 1 * Length::METER, 1 * Length::METER);
    Translation b(2 * Length::METER, 2 * Length::METER, 2 * Length::METER);
    ASSERT_TRUE(a < b) << "less than";
    ASSERT_FALSE(b < a) << "greater than";
}

TEST(Translation, OutputStream) {
    Translation a(1 * Length::METER, 2 * Length::METER, 3 * Length::METER);
    std::stringstream stream{};
    stream << a << std::endl;
    std::string output;
    std::getline(stream, output);
    EXPECT_EQ("(1m, 2m, 3m)", output);
}

TEST(Translation, ReadFrom) {
    std::stringstream stream{};
    Translation d;
    const Translation * const originalPointer = &d;

    stream << "Translation (15m, 15m, 15m)";
    stream >> d;
    ASSERT_DOUBLE_EQ(d.get_x() / Length::METER , 15);
    ASSERT_DOUBLE_EQ(d.get_y() / Length::METER , 15);
    ASSERT_DOUBLE_EQ(d.get_z() / Length::METER , 15);
    ASSERT_EQ(originalPointer, &d);
}