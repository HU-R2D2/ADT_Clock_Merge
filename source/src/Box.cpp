////
//  ██████╗  ██████╗ ██████╗  ██████╗ ██████╗ ███████╗███████╗ ██████╗██╗   ██╗███████╗
//  ██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██║   ██║██╔════╝
//  ██████╔╝██║   ██║██████╔╝██║   ██║██████╔╝█████╗  ███████╗██║     ██║   ██║█████╗  
//  ██╔══██╗██║   ██║██╔══██╗██║   ██║██╔══██╗██╔══╝  ╚════██║██║     ██║   ██║██╔══╝  
//  ██║  ██║╚██████╔╝██████╔╝╚██████╔╝██║  ██║███████╗███████║╚██████╗╚██████╔╝███████╗
//  ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝
//                                                                                                                                          
//
// @file Box.cpp
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

#include "../include/Box.hpp"

namespace r2d2{
Box::Box(Coordinate lhs, Coordinate rhs) {
    if(lhs.x < rhs.x){
        bottomLeft.x = lhs.x;
        topRight.x = rhs.x;
    }
    else{
        bottomLeft.x = rhs.x;
        topRight.x = lhs.x;
    }
    if(lhs.y < rhs.y){
        bottomLeft.y = lhs.y;
        topRight.y = rhs.y;
    }
    else{
        bottomLeft.y = rhs.y;
        topRight.y = lhs.y;
    }
    if(lhs.z < rhs.z){
        bottomLeft.z = lhs.z;
        topRight.z = rhs.z;
    }
    else{
        bottomLeft.z = rhs.z;
        topRight.z = lhs.z;
    }
}

Box::Box(Coordinate origin, Translation dist):
    Box(origin, origin + dist)
{}

Box::Box():
    Box(Coordinate::origin, Coordinate::origin)
{}


bool Box::contains(const Coordinate & coord) const {
    //! Check if coordinate  is within bottomLeft attribute and
    //! topRight attribute
    if (coord.x > bottomLeft.x &&
        coord.y > bottomLeft.y &&
        coord.z > bottomLeft.z)
    {

        if (coord.x < topRight.x &&
        coord.y < topRight.y &&
        coord.z < topRight.z)
        {
            return true;
        }

    }

    if (coord.x < bottomLeft.x &&
        coord.y < bottomLeft.y &&
        coord.z < bottomLeft.z
        )
    {
        if(coord.x > topRight.x &&
            coord.y > topRight.y &&
            coord.z > topRight.z)
        {
            return true;    
        }
    }       
    return false;
}

bool Box::contains(const Box & box) const {
    //! Check if both coordinates of the box attribute are within current box 
    //! bottomLeft and topRight
    if (this->contains(box.bottomLeft) && this->contains(box.topRight))
    {
        return true;
    } 
    return false;
}

bool Box::intersects(const Box & box) const {
    // Check if there is an intersection between two boxes
    // Uses AABB collision detection (Angle Aligned Bounding Box)
    if (topRight.x > box.bottomLeft.x && 
    bottomLeft.x < box.topRight.x &&
    topRight.y > box.bottomLeft.y &&
    bottomLeft.y < box.topRight.y &&
    topRight.z > box.bottomLeft.z &&
    bottomLeft.z < box.topRight.z) {
        return true;
    }

    return false;
}

Coordinate Box::get_bottom_left() const {
    return bottomLeft;
}

Coordinate Box::get_top_right() const {
    return topRight;
}

Box Box::get_union_box(const Box & box) const {
    Coordinate newBottomLeft;
    Coordinate newTopRight;

    (bottomLeft.x < box.bottomLeft.x) ?
        newBottomLeft.x = bottomLeft.x : newBottomLeft.x = box.bottomLeft.x;
    
    
    (bottomLeft.y < box.bottomLeft.y) ?
        newBottomLeft.y = bottomLeft.y : newBottomLeft.y = box.bottomLeft.y;

    (bottomLeft.z < box.bottomLeft.z) ? 
        newBottomLeft.z = bottomLeft.z : newBottomLeft.z = box.bottomLeft.z;
    
    (topRight.x > box.topRight.x) ?
        newTopRight.x = topRight.x : newTopRight.x = box.topRight.x;

    (topRight.y > box.topRight.y) ?
        newTopRight.y = topRight.y : newTopRight.y = box.topRight.y;

    (topRight.z > box.topRight.z) ?
        newTopRight.z = topRight.z : newTopRight.z = box.topRight.z;

    return Box(newBottomLeft, newTopRight);
}

Box Box::get_intersection_box(const Box & box) const {
    if(this->intersects(box)) {
        // return intersection box
        if(this->contains(box.bottomLeft)) {
            // intersectionBox bottomLeft
            return Box(box.get_bottom_left(), topRight);
        } else {
            return Box(bottomLeft, box.get_top_right());
        }
    } else {
        // no intersection box
        return Box(Coordinate(), Coordinate());
    }   
}

Translation Box::get_axis_size() const {
	Translation dist;
	dist.x = (topRight.x - bottomLeft.x);
	dist.y = (topRight.y - bottomLeft.y);
	dist.z = (topRight.z - bottomLeft.z);
	return dist;
}

Box & Box::operator=(const Box & rhs) { 
    bottomLeft = rhs.bottomLeft;
    topRight = rhs.topRight;
    return *this;
}

std::ostream & operator <<(std::ostream & lhs, const Box & rhs) {
    lhs << "box (" << rhs.bottomLeft << ", " << rhs.topRight << ")";
    return lhs;
}

std::istream & operator >>(std::istream & lhs, Box & rhs ) {
    // Make sure the data that is being decoded is a Box.
    std::string prefix;

    lhs >> std::ws >> prefix;

    if (prefix != "box") {
        throw std::invalid_argument{"Expecting prefix \"box\","
            " got something else."};
    }
    char temp;
    lhs >> std::ws >> temp;
    if (temp != '(') {
        throw std::invalid_argument{"No opening brace encountered"};
     }
     
    Coordinate bottomLeft;
    Coordinate topRight;
   
    lhs >> bottomLeft;
    lhs >> topRight;

    if (!lhs) {
        throw std::invalid_argument{"Coordinate wasn't read in its entirety when"
            " end of stream was reached. "};
    }

    rhs.bottomLeft = bottomLeft;
    rhs.topRight = topRight;
    return lhs;
}
}