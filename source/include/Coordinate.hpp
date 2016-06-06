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

#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include <iostream>
#include <stdexcept>
#include "Length.hpp"

// Forward declaration.
namespace r2d2{
class Translation;

class Box;


//! @class Coordinate
//! @brief A location in space, specified as an offset to an arbitrary origin.
//!
//! The offset to the origin is given in Lengths.
class Coordinate final {

    // Box consists out of multiple coordinates, and might change some aspects
    // or create new ones. This could require access to private fields / functions.
    friend class Box;

private:
    Length x;
    Length y;
    Length z;

public:
    //! @brief Constructs a coordinate with the given offsets from the origin on
    //! the X,Y and Z axis.
    //!
    //! @param x Translation between the origin's X, and this coordinate's.
    //! @param y Translation between the origin's Y, and this coordinate's.
    //! @param z Translation between the origin's Z, and this coordinate's.
    Coordinate(const Length &x, const Length &y, const Length &z);

    //! @brief Reserves space for a coordinate to later be assigned.
    //!
    //! While this might result in the same value as Coordinate::origin,
    //! no guarantee is given. Therefor if it is intended to be created as origin,
    //! use Coordinate::origin instead.
    Coordinate() = default;

    //! @brief Copies the fields from the right hand side into this,
    //! and returns a reference to this.
    //!
    //! @param rhs Object from which to copy the values.
    //! @return Reference to the left hand side of the operator.
    Coordinate &operator=(const Coordinate &rhs);

    //! @brief Adds the Translation to this coordinate,
    //! and returns a reference to it.
    //!
    //! @param rhs Translation to add to this coordinate.
    //! @return Reference to this coordinate.
    Coordinate &operator+=(const Translation &rhs);

    //! @brief Substracts the given Translation from this coordinate,
    //! and returns a reference to it.
    //!
    //! @param rhs Translation to subtract from this coordinate.
    //! @return Reference to this coordinate.
    Coordinate &operator-=(const Translation &rhs);

    //! @brief Gets the coordinate at the given Translation from this coordinate.
    //!
    //! @param rhs Translation to add to this coordinate.
    //! @return The coordinate at the given Translation from this coordinate.
    Coordinate operator+(const Translation &rhs) const;

    //! @brief Gets the coordinate at the given Translation from this coordinate.
    //!
    //! @param rhs Translation to subtract from this coordinate.
    //! @return The coordinate at the given Translation from this coordinate.
    Coordinate operator-(const Translation &rhs) const;

    //! @brief Gets the Translation the other coordinate is away from this coordinate.
    //!
    //! @param rhs Other coordinate which is used to determine the Translation.
    //! @return Translation from this coordinate to the other.
    Translation operator-(const Coordinate &rhs) const;

    //! @brief The arbitrary origin to be used.
    static const Coordinate origin;

    //! @brief Writes the specified coordinate to the std::ostream,
    //! returning that stream.
    //!
    //! The output is given in the format somewhat similar to "coordinate(x, y, z)",
    //! where the 'x', 'y' and 'z' are replaced by the offsets to the origin.
    //! The suffixes could vary based on the magnitude of the lengths.
    //! @param lhs Stream to which to write the string representation of the coordinate.
    //! @param rhs Reference to the object to write to the outputstream.
    //! @return Reference to the stream passed in by lhs.
    //! @see operator>>(std::istream, coordinate &)
    //! @see operator<<(std::ostream, const coordinate &)
    friend std::ostream &operator<<(std::ostream &lhs, const Coordinate &rhs);

    //! @brief Reads a coordinate from the given input stream, returning said stream.
    //!
    //! The input should be given in the format "coordinate(z, y, z)",
    //! ignoring the quotes.
    //! The values 'x', 'y' and 'z' should be replaced with floating point values.
    //! Any excess whitespace is ignored.
    //! The supported suffixes are the same as Length's.
    //! @param lhs Stream from which to read data
    //! @param rhs Reference to an uninitialized coordinate to overwrite.
    //! @return Reference to the stream passed in by lhs.
    //! @throw std::invalid_argument Indicates a Coordinate could not be read
    //! from the given input stream due to it being in an incorrect format.
    //! The values in the supplied coordinate are not modified when an exception is thrown.
    //! @see operator<<(std::ostream &, coordinate &)
    //! @see operator>>(std::istream &, coordinate &)
    friend std::istream &operator>>(std::istream &lhs, Coordinate &rhs);

    //! @brief Gets a reference to this coordinate's X-offset to that of the origin.
    //!
    //! @return Reference to the difference between this and the origin's X-position.
    const Length &get_x() const;

    //! @brief Gets a reference to this coordinate's Y-offset to that of the origin.
    //!
    //! @return Reference to the difference between this and the origin's Y-position.
    const Length &get_y() const;

    //! @brief Gets a reference to this coordinate's Z-offset to that of the origin.
    //!
    //! @return Reference to the difference between this and the origin's Z-position.
    const Length &get_z() const;
};
}
#endif // COORDINATE_HPP
