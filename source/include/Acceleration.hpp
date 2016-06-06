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
// @date Created: 28-03-2016
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

//! @class Acceleration
//! @brief Acceleration data type stored in meters per second.

#ifndef _ACCELERATION_HPP
#define _ACCELERATION_HPP

#include "Duration.hpp"
#include "ADT_Base.hpp"
#include "Speed.hpp"

#include <iostream>

namespace r2d2{
class Force;
class Acceleration : public ADT_Base<Acceleration> {
protected: 
    //! @brief Constructor that sets the value to whichever value. 
    //! value should be in meter per second.
    //!
    //! @param val Raw acceleration value in meter per second per second
    Acceleration(double val);
public:
    friend ADT_Base<Acceleration>;
    friend Force;
    //! @brief The default constructor of and acceleration
    Acceleration();

    //! @brief  input operator for an acceleration
    //! 
    //! @param lhs              the istream, from this istream the 
    //! acceleration will be adapted
    //! @param rhs              the acceleration that will be adapted by 
    //! the lhs istream
    //! @return std::istream    the inputstream
    friend std::istream &operator>>(std::istream & lhs, Acceleration & rhs);

    //! @brief appends an accelration to an std::ostream and returns the ostream
    //! The format of the accelration will be "acceleration( 1.5 m/sec )"
    //!
    //! @param os               the std::ostream to append to
    //! @param rhs              Object to append
    //! @return std::ostream    the ostream
    friend std::ostream &operator<<(std::ostream & lhs, 
        const Acceleration & rhs);

    //! @brief Divides a speed with a duration and returns Acceleration
    //!
    //! @param s the speed to divide
    //! @param d the duration
    //! @return Acceleration the acceleration
    friend Acceleration operator/ (const Speed & s, const Duration &d);

};
Acceleration operator/( const Speed & s, const Duration &d);
}
#endif

