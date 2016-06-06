//! Roborescue
//! @file Coordinate.hpp
//! @date Created: 14-03-16
//! @version 1.0.0
//!
//! @author Matthijs Mud
//!
//! @section LICENSE
//! License: newBSD
//!
//! Copyright © 2016, HU University of Applied Sciences Utrecht.
//! All rights reserved.
//!
//! Redistribution and use in source and binary forms, with or without
//! modification, are permitted provided that the following conditions are met:
//! - Redistributions of source code must retain the above copyright notice,
//!   this list of conditions and the following disclaimer.
//! - Redistributions in binary form must reproduce the above copyright notice,
//!   this list of conditions and the following disclaimer in the documentation
//!   and/or other materials provided with the distribution.
//! - Neither the name of the HU University of Applied Sciences Utrecht
//!   nor the names of its contributors may be used to endorse or promote products
//!   derived from this software without specific prior written permission.
//!
//! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//! "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//! THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//! ARE DISCLAIMED. IN NO EVENT SHALL THE HU UNIVERSITY OF APPLIED SCIENCES UTRECHT
//! BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//! CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
//! GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
//! HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
//! LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
//! OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef ADT_COORDINATETEST_H
#define ADT_COORDINATETEST_H

#include <limits.h>
#include "gtest/gtest.h"
#include "../source/include/Coordinate.hpp"
#include "../source/include/Translation.hpp"
#include <string>
#include <sstream>

using namespace r2d2;

TEST(Coordinate, Constructor) {
    Coordinate c1 = Coordinate::origin;
    EXPECT_DOUBLE_EQ(0, c1.get_x() / Length::METER);
    EXPECT_DOUBLE_EQ(0, c1.get_y() / Length::METER);
    EXPECT_DOUBLE_EQ(0, c1.get_z() / Length::METER);

    Coordinate c2 = Coordinate{20 * Length::METER, 3.5 * Length::METER,
                               4 * Length::METER};
    EXPECT_DOUBLE_EQ(20, c2.get_x() / Length::METER);
    EXPECT_DOUBLE_EQ(3.5, c2.get_y() / Length::METER);
    EXPECT_DOUBLE_EQ(4, c2.get_z() / Length::METER);

    Coordinate c3 = Coordinate{-20 * Length::METER, -3.5 * Length::METER,
                               -4 * Length::METER};
    EXPECT_DOUBLE_EQ(-20, c3.get_x() / Length::METER);
    EXPECT_DOUBLE_EQ(-3.5, c3.get_y() / Length::METER);
    EXPECT_DOUBLE_EQ(-4, c3.get_z() / Length::METER);
}

TEST(Coordinate, Assignment) {
    Coordinate c1 = Coordinate::origin;
    Coordinate c2 = Coordinate::origin +
                    Translation{1 * Length::METER, 2 * Length::METER,
                                3 * Length::METER};
    c1 = c2;
    EXPECT_DOUBLE_EQ(1, c1.get_x() / Length::METER);
    EXPECT_DOUBLE_EQ(2, c1.get_y() / Length::METER);
    EXPECT_DOUBLE_EQ(3, c1.get_z() / Length::METER);

    Coordinate c3 = Coordinate::origin +
                    Translation{-1 * Length::METER, -2 * Length::METER,
                                -3 * Length::METER};
    c1 = c3;
    EXPECT_DOUBLE_EQ(-1, c1.get_x() / Length::METER);
    EXPECT_DOUBLE_EQ(-2, c1.get_y() / Length::METER);
    EXPECT_DOUBLE_EQ(-3, c1.get_z() / Length::METER);
}

TEST(Coordinate, Addition) {
    Coordinate c1 = Coordinate::origin +
                    Translation{2 * Length::METER, 4 * Length::METER,
                                8 * Length::METER};
    EXPECT_DOUBLE_EQ(2, c1.get_x() / Length::METER);
    EXPECT_DOUBLE_EQ(4, c1.get_y() / Length::METER);
    EXPECT_DOUBLE_EQ(8, c1.get_z() / Length::METER);

    Coordinate c2 = Coordinate::origin +
                    Translation{-2 * Length::METER, -4 * Length::METER,
                                -8 * Length::METER};
    EXPECT_DOUBLE_EQ(-2, c2.get_x() / Length::METER);
    EXPECT_DOUBLE_EQ(-4, c2.get_y() / Length::METER);
    EXPECT_DOUBLE_EQ(-8, c2.get_z() / Length::METER);

    Coordinate c3 = c2 + Translation{4 * Length::METER, 6 * Length::METER,
                                     0 * Length::METER};
    EXPECT_DOUBLE_EQ(2, c3.get_x() / Length::METER);
    EXPECT_DOUBLE_EQ(2, c3.get_y() / Length::METER);
    EXPECT_DOUBLE_EQ(-8, c3.get_z() / Length::METER);
    Translation d{3 * Length::METER, -7 * Length::METER, 13 * Length::METER};

    const Coordinate *const coordPointer = &c3;
    ASSERT_EQ(coordPointer, &(c3 += d)) << "Wrong reference returned.";
    EXPECT_DOUBLE_EQ(5, c3.get_x() / Length::METER);
    EXPECT_DOUBLE_EQ(-5, c3.get_y() / Length::METER);
    EXPECT_DOUBLE_EQ(5, c3.get_z() / Length::METER);
}

TEST(Coordinate, Subtraction) {
    Coordinate c1 = Coordinate::origin -
                    Translation{2 * Length::METER, 4 * Length::METER,
                                8 * Length::METER};
    EXPECT_DOUBLE_EQ(-2, c1.get_x() / Length::METER);
    EXPECT_DOUBLE_EQ(-4, c1.get_y() / Length::METER);
    EXPECT_DOUBLE_EQ(-8, c1.get_z() / Length::METER);

    Coordinate c2 = Coordinate::origin -
                    Translation{-2 * Length::METER, -4 * Length::METER,
                                -8 * Length::METER};
    EXPECT_DOUBLE_EQ(2, c2.get_x() / Length::METER);
    EXPECT_DOUBLE_EQ(4, c2.get_y() / Length::METER);
    EXPECT_DOUBLE_EQ(8, c2.get_z() / Length::METER);

    Coordinate c3 = c2 - Translation{4 * Length::METER, 6 * Length::METER,
                                     0 * Length::METER};
    EXPECT_DOUBLE_EQ(-2, c3.get_x() / Length::METER);
    EXPECT_DOUBLE_EQ(-2, c3.get_y() / Length::METER);
    EXPECT_DOUBLE_EQ(8, c3.get_z() / Length::METER);
    Translation d{3 * Length::METER, -7 * Length::METER, 13 * Length::METER};

    const Coordinate *const coordPointer = &c3;
    ASSERT_EQ(coordPointer, &(c3 -= d)) << "Wrong reference returned.";
    EXPECT_DOUBLE_EQ(-5, c3.get_x() / Length::METER);
    EXPECT_DOUBLE_EQ(5, c3.get_y() / Length::METER);
    EXPECT_DOUBLE_EQ(-5, c3.get_z() / Length::METER);
}

TEST(Coordinate, WriteTo) {
    std::stringstream stream{};
    stream << Coordinate::origin << std::endl;
    std::string output;
    std::getline(stream, output);
    EXPECT_EQ("coordinate (0m, 0m, 0m)", output);
    EXPECT_EQ(&stream,
              &(stream << Coordinate::origin)) << "Wrong stream is returned.";
}

TEST(Coordinate, ReadFrom) {
    std::stringstream stream{};
    Coordinate coord = Coordinate::origin;
    const Coordinate *const originalPointer = &coord;

    // Check whether the coordinate is read in correct form from the stream.
    stream << "coordinate (15m, 7.5m, 3.75m)";
    try { stream >> coord; } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    ASSERT_DOUBLE_EQ(15, coord.get_x() / Length::METER);
    ASSERT_DOUBLE_EQ(7.5, coord.get_y() / Length::METER);
    ASSERT_DOUBLE_EQ(3.75, coord.get_z() / Length::METER);
    ASSERT_EQ(originalPointer, &coord) << "A wrong reference is returned.";

    // A list of strings which should NOT be parsed.
    // In comments is listed what is wrong with the string.
    auto failures = {
            "coordinate(0m,0m,0m)",     // Space between "coordinate" and opening brace is missing.
            "coordinate (0m; 0m; 0m)",  // Incorrect separator(s).
            "coordinate (0m; 0m, 0m)",  // Same as above.
            "coordinate (0m, 0m; 0m)",  // Same as above.
            "coordinate (0m, 0m, 0m]",  // Wrong closing brace.
            "coordinate [0m, 0m, 0m)",  // Wrong opening brace.
            "coordinate [0m, 0m, 0m]",  // Wrong opening and closing brace.
            "coord (0m, 0m, 0m)"        // Incomplete indication of type; should be "coordinate".
    };
    for (auto failure : failures) {
        try {
            std::stringstream stream{failure};
            stream >> coord;
            FAIL() << "Parsing \"" << failure <<
                   "\" to a coordinate should not be possible." << std::endl;
        } catch (std::invalid_argument &e) {
            // Behaves as expected.
            ASSERT_DOUBLE_EQ(15, coord.get_x() /
                                 Length::METER) << "X value was modified despite the promise";
            ASSERT_DOUBLE_EQ(7.5, coord.get_y() /
                                  Length::METER) << "Y value was modified despite the promise";
            ASSERT_DOUBLE_EQ(3.75, coord.get_z() /
                                   Length::METER) << "Z value was modified despite the promise";
        } catch (...) {
            FAIL() << "Wrong exception; was expecting [CoordinateException]";
        }
    }
}

#endif //ADT_COORDINATETEST_H
