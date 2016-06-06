// ++--++
// @file <Masstest.cpp>
// @date Created: <5-3-16>
// @version <0.0.1>
//
// @author <Job Verhaar>
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
#include "../source/include/Mass.hpp"
#include <iostream>
using namespace r2d2;
//constructors
TEST(Mass, DefaultConstructor){
	Mass w;
	ASSERT_DOUBLE_EQ(w/Mass::KILOGRAM, 0) << "Mass";
}

//Operatoren:
TEST(Mass, AssignMass){
	Mass w;
	ASSERT_DOUBLE_EQ(w/Mass::KILOGRAM, 0) << "Empty Mass";
	w = 2 * Mass::KILOGRAM;
	ASSERT_DOUBLE_EQ(w/Mass::KILOGRAM, 2) << "Assigned";
}

TEST(Mass, AddMass) { 						//operator+
	// leeg + leeg
	Mass a = 0 * Mass::KILOGRAM;
	Mass b;
	a = a + b;
	ASSERT_DOUBLE_EQ(a/Mass::KILOGRAM , 0.0) << "empty+empty";
	
	// leeg + vol
	Mass c = 2 * Mass::KILOGRAM;
	b = b + c;
	ASSERT_DOUBLE_EQ(b/Mass::KILOGRAM , 2.0) << "empty+full";
	
	// vol + vol
	Mass d = 3 * Mass::KILOGRAM;
	d = d + c;
 	ASSERT_DOUBLE_EQ(d/Mass::KILOGRAM , 5.0) << "full+full";
}

TEST(Mass, SubstractMass) { 				//operator-
	// leeg - leeg
	Mass a{};
	Mass b;
	a = a - b;
	ASSERT_DOUBLE_EQ(a/Mass::KILOGRAM , 0.0) << "empty-empty";
	
	// leeg - vol
	Mass c = 2 * Mass::KILOGRAM;
	b = b - c;
	ASSERT_DOUBLE_EQ(b/Mass::KILOGRAM , -2) << "empty-full";
	
	// vol - leeg
	c = c - a;
	ASSERT_DOUBLE_EQ(c/Mass::KILOGRAM , 2.0) << "full-empty";
	
	// vol - vol
	Mass d = 1 * Mass::KILOGRAM;
	d = d - c;
 	ASSERT_DOUBLE_EQ(d/Mass::KILOGRAM , -1.0) << "full-full neg";
	Mass e= 3 * Mass::KILOGRAM;
	Mass f= 2 * Mass::KILOGRAM;
	e = e - f;
 	ASSERT_DOUBLE_EQ(e/Mass::KILOGRAM , 1.0) << "full-full";
}

TEST(Mass, MultiplyMassDouble) { 						//operator* (1)
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg * 0
	Mass a;
	a = a * 0;
	ASSERT_DOUBLE_EQ(a/Mass::KILOGRAM , 0) << "empty*0 Mass";
	
	// leeg * getal1
	a = a * getal1;
	ASSERT_DOUBLE_EQ(a/Mass::KILOGRAM , 0) << "empty Mass";
		
	// vol * 0
	Mass b =1 * Mass::KILOGRAM;
	b = b * 0;
	ASSERT_DOUBLE_EQ(b/Mass::KILOGRAM , 0) << "full*0 Mass";
		
	// vol * getal1
	Mass c =2 * Mass::KILOGRAM;
	c = c * getal1;
	ASSERT_DOUBLE_EQ(c/Mass::KILOGRAM , 4) << "full*getal1 Mass";
	
	// vol * getal2
	Mass d =3  * Mass::KILOGRAM;
	d = d * getal2;
	ASSERT_DOUBLE_EQ(d/Mass::KILOGRAM , 7.5) << "full * getal2 Mass";

}

TEST(Mass, MultiplyDoubleMass) { 						//operator* (2)
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg * 0
	Mass a;
	a = 0 * a;
	ASSERT_DOUBLE_EQ(a/Mass::KILOGRAM , 0) << "empty*0 Mass";
	
	// leeg * getal1
	a = getal1 * a;
	ASSERT_DOUBLE_EQ(a/Mass::KILOGRAM , 0) << "empty Mass";
		
	// vol * 0
	Mass b =1 * Mass::KILOGRAM;
	b = 0 * b;
	ASSERT_DOUBLE_EQ(b/Mass::KILOGRAM , 0) << "full*0 Mass";
		
	// vol * getal1
	Mass c =2 * Mass::KILOGRAM;
	c = getal1 * c;
	ASSERT_DOUBLE_EQ(c/Mass::KILOGRAM , 4) << "full*getal1 Mass";
	
	// vol * getal2
	Mass d =3  * Mass::KILOGRAM;
	d = getal2 * d;
	ASSERT_DOUBLE_EQ(d/Mass::KILOGRAM , 7.5) << "full * getal2 Mass";

}

TEST(Mass, DivideDouble) { 					//operator/ (1)
    double getal1 = 2;
	double getal2 = 2.5;
	
	// leeg / 0
	Mass a;
	a = a / 0;			// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(a/Mass::KILOGRAM , 0) << "empty / 0 Mass";
	
	// leeg / getal1
	a = a / getal1;
	ASSERT_DOUBLE_EQ(a/Mass::KILOGRAM , 0) << "empty x";
	
	// vol / 0
	Mass b = 1 * Mass::KILOGRAM;
	b = b / 0;			// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(b/Mass::KILOGRAM , 1) << "full / 0 Mass";
	
	// vol / getal1
	Mass c = 1 * Mass::KILOGRAM;
	c = c / getal1;
	ASSERT_DOUBLE_EQ(c/Mass::KILOGRAM , 0.5) << "full / getal1 Mass";
	
	// vol / getal2
	Mass d =1 * Mass::KILOGRAM;
	d = d / getal2;
	ASSERT_DOUBLE_EQ(d/Mass::KILOGRAM , 0.4) << "full / getal2 Mass ";
	
}

TEST(Mass, DivideMass) { 					//operator/ (2)
    Mass a;
	Mass d;
	Mass b = 4 * Mass::KILOGRAM;
	Mass c = 2 * Mass::KILOGRAM;
	
	// leeg / leeg
	double z = a / d;		// dit mag niet, dus niks doen!
	ASSERT_DOUBLE_EQ(z , 0) << "empty / empty";	
	
	// vol / leeg
	z = b / a;
	ASSERT_DOUBLE_EQ(z , 4) << "full / empty";
	
	// vol / vol
	z = b / c;
	ASSERT_DOUBLE_EQ(z , 2) << "full / full";	
}

TEST(Mass, AddAssignMass) {					//operator+=
	// leeg + leeg
	Mass a;
	Mass b;
	a += b;
	ASSERT_DOUBLE_EQ(a/Mass::KILOGRAM , 0) << "empty+empty";
	
	// leeg + vol
	Mass c = 2  * Mass::KILOGRAM;
	b += c;
	ASSERT_DOUBLE_EQ(b/Mass::KILOGRAM , 2) << "empty+full";
	
	// vol + vol
	Mass d = 3 * Mass::KILOGRAM;
	d += c;
 	ASSERT_DOUBLE_EQ(d/Mass::KILOGRAM , 5) << "full+full"; 
}

TEST(Mass, SubtractAssignMass) { 			//operator-=
	// leeg - leeg
	Mass a;
	Mass b;
	a -= b;
	ASSERT_DOUBLE_EQ(a/Mass::KILOGRAM , 0) << "empty-empty";
	
	// leeg - vol
	Mass c = 2  * Mass::KILOGRAM;
	b -= c;
	ASSERT_DOUBLE_EQ(b/Mass::KILOGRAM , -2) << "empty-full";
	
	// vol - leeg
	c -= a;
	ASSERT_DOUBLE_EQ(c/Mass::KILOGRAM , 2) << "full-empty";
	
	// vol - vol
	Mass d = 1 * Mass::KILOGRAM;
	d -= c;
 	ASSERT_DOUBLE_EQ(d/Mass::KILOGRAM , -1) << "full-full neg";
	Mass e = 5 * Mass::KILOGRAM;
	Mass f = 3 * Mass::KILOGRAM;
	e -= f;
	ASSERT_DOUBLE_EQ(e/Mass::KILOGRAM , 2) << "full-full";
}	

TEST(Mass, GreaterThan) { 				//operator>
	Mass a(2 * Mass::KILOGRAM);
	Mass b(1 * Mass::KILOGRAM);
	ASSERT_TRUE(a > b) << "greater than";
	ASSERT_FALSE(b > a) << "less than";
}

TEST(Mass, LessThan) { 					//operator>
	Mass a(1 * Mass::KILOGRAM);
	Mass b(2 * Mass::KILOGRAM);
	ASSERT_TRUE(a < b) << "greater than";
	ASSERT_FALSE(b < a) << "less than";
}

TEST(Mass, WriteTo) {
	std::stringstream stream{};
	Mass w = 5 * Mass::KILOGRAM;
	stream << w << std::endl;
	std::string output;
	std::getline(stream, output);
	EXPECT_EQ("5Kg", output);
	EXPECT_EQ(&stream, &(stream << w))<< "Wrong stream is returned.";
}

TEST(Mass, ReadFrom){
	std::stringstream stream{};
	Mass w;
	stream << "20Kg";
	stream >> w;
	ASSERT_DOUBLE_EQ(20,w/Mass::KILOGRAM);
}