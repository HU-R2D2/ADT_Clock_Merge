// ++--++
// Roborescue
// @file <Mass.hpp>
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
//!
//! @author		Job Verhaar
//! @date 		04-04-16
//! @version 	0.1
//! @brief		Mass is a abstract data type to represent the KG.
//!

#ifndef _Mass_HPP
#define _Mass_HPP

#include "ADT_Base.hpp"

#include <iostream> 
 
namespace r2d2{
class Mass : public ADT_Base<Mass>{
protected:
    //! @fn     Mass::Mass(double l)
    //!
    //! @brief  Constructor of a Mass
    //!
    //! @param	value the Mass in KG
    Mass(double value);

public:
    friend ADT_Base<Mass>;
    //! @fn 	Mass::Mass()
    //!
    //! @brief 	Defaut constructor of Mass
    Mass();

    //! @fn     std::ostream operator<<(std::ostream& os, const Mass& rhs)
    //!
    //! @brief Appends a Mass to an std::ostream and returns the ostream
    //!
    //! @param os the std::ostream to append to
    //! @param rhs Object to append
    //! @return std::ostream
    friend std::ostream& operator<< (std:: ostream& os, const Mass& rhs);

    //! @fn    std::istream operator>>(std::istream& is, Mass& rhs)
    //!
    //! @brief Reads a Mass from an std::istream and returns the istream
    //!
    //! @param os the std::istream to read it from;
    //! @param rhs Object to read
    //! @return std::istream
    friend std::istream& operator>>(std::istream& is, Mass& rhs);

    //! @fn		Mass operator*(double n, const Mass & rhs)
    //!
    //! @brief	multiply a Mass bu a double and returns a Mass
    //!
    //! @param  n a double
    //! @param  rhs the Mass that is multiplied
    //! @return The calcukated Mass
    friend Mass operator* (double n, const Mass& rhs);

    //! Statics for forcing using the right SI-value
    static const Mass KILOGRAM;
    static const Mass GRAM;
};
}
#endif