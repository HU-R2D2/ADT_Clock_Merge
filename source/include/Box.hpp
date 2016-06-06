////
//  ██████╗  ██████╗ ██████╗  ██████╗ ██████╗ ███████╗███████╗ ██████╗██╗   ██╗███████╗
//  ██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██║   ██║██╔════╝
//  ██████╔╝██║   ██║██████╔╝██║   ██║██████╔╝█████╗  ███████╗██║     ██║   ██║█████╗  
//  ██╔══██╗██║   ██║██╔══██╗██║   ██║██╔══██╗██╔══╝  ╚════██║██║     ██║   ██║██╔══╝  
//  ██║  ██║╚██████╔╝██████╔╝╚██████╔╝██║  ██║███████╗███████║╚██████╗╚██████╔╝███████╗
//  ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝
//                                                                                                                                          
//
// @file Box.hpp
// @date Created: 15-03-2016
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

#ifndef _BOX_HPP
#define _BOX_HPP

#include "Coordinate.hpp"
#include "Translation.hpp"
#include <iostream>

namespace r2d2{
//! @class Box
//! @brief          A 3D rectangular box in space, which is aligned to 3 axises.
class Box final {
public:
    Box();
    //! @brief Constructs a box with 2 coordinates, bottom left and top right 
    //! of the 3D ractangle
    //!
    //! @param bottomLeft
    //! @param topRight 
    Box (Coordinate bottomLeft, Coordinate topRight);

    //! @brief Constructs a box with one coordinate and a Translation, bottom 
    //! left coordinate and the Translation of the axises.
    //!
    //! @param origin bottom left coordinate of the rectangle
    //! @param dist the size of one edge (axis) 
    Box (Coordinate origin, Translation dist);

    //! @brief Checks whether box contains coordinate
    //!
    //! @param coord The coordinate to check
    //! @return boolean State if parameter is inside of this object 
    bool contains (const Coordinate & coord) const;

    //! @brief Check whether box contains another box
    //!
    //! @param box 
    //! @return boolean State if parameter is inside of this object 
    bool contains (const Box & box) const;

    //! @brief Check whether box intersects with another box, returns boolean
    //!
    //! @param 
    //! @return     
    bool intersects (const Box & box) const;

    //! @brief return bottom left coordinate
    //!
    //! @return bottomLeft coordinate
    Coordinate get_bottom_left() const;

    //! @brief return the top right coordinate
    //!
    //! @return topright coordinate
    Coordinate get_top_right() const;

    //! @brief Returns the smallest possible box that contains both boxes
    //!
    //! @param box the box to create an union box with
    //! @return Box the union box
    Box get_union_box(const Box & box) const;

    //! @brief Returns box that contains the shared space (intersection area) 
    //! between two boxes
    //! @note If there is no intersection between the boxes, 
    //! a empty box will be returned
    //!
    //! @param box the box to create an shared space with
    //! @return Box The box that contains the shared space. When there is 
    //! no overlapse in the two boxes a box with (0.0,0.0,0.0) is returned.
    Box get_intersection_box(const Box & box) const;

    //! @brief Returns the size of the axis
    //!
    //! @return Translation of the axis
    Translation get_axis_size() const;

    //! @brief assignment operator for a box
    //!
    //! @param box the box to assign
    //! @return the object
    Box & operator= ( const Box & );

    //! @brief appends a box to an std::ostream and returns the ostream
    //!
    //! @param os the std::ostream to append to
    //! @param rhs Object to append
    //! @return std::ostream
    friend std::ostream & operator<< (std::ostream & os, const Box & rhs);

    //! @brief read a box from std::istream and return the istream
    //!
    //! @param lhs the istream to read from
    //! @param rhs the coordinate to write the values to
    //! @return std::istream the istream
    friend std::istream &operator>>(std::istream &lhs, Box & rhs);

private:
    Coordinate bottomLeft;
    Coordinate topRight;
    friend class Translation;
};
}
#endif  // _BOX_HPP

