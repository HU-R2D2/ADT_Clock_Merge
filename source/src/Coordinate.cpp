//! Roborescue
//!
//! @file Coordinate.cpp
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
//! Redistribution and use in source and binary forms, with or without modification,
//! are permitted provided that the following conditions are met:
//! - Redistributions of source code must retain the above copyright notice,
//!   this list of conditions and the following disclaimer.
//! - Redistributions in binary form must reproduce the above copyright notice,
//!   this list of conditions and the following disclaimer in the documentation
//!   and/or other materials provided with the distribution.
//! - Neither the name of the HU University of Applied Sciences Utrecht
//!   nor the names of its contributors may be used to endorse or promote
//!   products derived from this software without specific prior written permission.
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

#include "../include/Coordinate.hpp"
#include "../include/Translation.hpp"
#include <string>
#include <stdexcept>
namespace r2d2{
const Coordinate Coordinate::origin(
        0.0 * Length::METER, 0.0 * Length::METER, 0.0 * Length::METER);

Coordinate::Coordinate(const Length &x, const Length &y, const Length &z)
        : x{x}, y{y}, z{z} {
    // The initializer list is all that is needed.
}

Coordinate &Coordinate::operator=(const Coordinate &rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

Coordinate &Coordinate::operator+=(const Translation &rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
    return *this;
}

Coordinate &Coordinate::operator-=(const Translation &rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;
    return *this;
}

Coordinate Coordinate::operator+(const Translation &rhs) const {
    Coordinate output{*this};
    output += rhs;
    return output;
}

Coordinate Coordinate::operator-(const Translation &rhs) const {
    Coordinate output{*this};
    output -= rhs;
    return output;
}

Translation Coordinate::operator-(const Coordinate &rhs) const {
    return Translation{this->x - rhs.x, this->y - rhs.y, this->z - rhs.z};
}

std::ostream &operator<<(std::ostream &lhs, const Coordinate &rhs) {
    lhs << "coordinate (" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return lhs;
}

std::istream &operator>>(std::istream &lhs, Coordinate &rhs) {
    // Make sure the data that is being decoded is a coordinate.
    std::string prefix;
    lhs >> std::ws >> prefix;
    if (prefix != "coordinate") {
        throw std::invalid_argument{
                "Expecting prefix \"coordinate\", got something else (" +
                prefix + ")."};
    }
    char temp;
    lhs >> std::ws >> temp;
    if (temp != '(') {
        throw std::invalid_argument{"No opening brace encountered"};
    }

    // To guarantee the coordinate remains unchanged when an error occurs,
    // a temporary storage is needed for the values.
    // If not, throw an exception or something along those lines.
    Length x, y, z;

    // The different values are separated by certain characters.
    // As they require multiple similar steps, this small lambda is defined.
    auto ReadComponent = [](std::istream &lhs, char expectedSeperator) {
        Length value;
        char separator;
        lhs >> value >> separator;
        if (separator != expectedSeperator) {
            throw std::invalid_argument{"Wrong or missing seperator."};
        }
        return value;
    };
    x = ReadComponent(lhs, ',');
    y = ReadComponent(lhs, ',');
    z = ReadComponent(lhs, ')');

    if (!lhs) {
        throw std::invalid_argument{
                "Coordinate wasn't read in its entirety when end of stream was reached."};
    }

    rhs.x = x;
    rhs.y = y;
    rhs.z = z;

    return lhs;
}

const Length &Coordinate::get_x() const {
    return x;
}

const Length &Coordinate::get_y() const {
    return y;
}

const Length &Coordinate::get_z() const {
    return z;
}
}