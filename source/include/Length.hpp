//! Roborescue
//! @file <Length.hpp>
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

//! @author     Remco Nijkamp & Koen de Groot
//! @date       15-03-16
//! @version    1.0
//! @brief      Length is a Length is a measurement of a size that is being
//!             represented by a single value. 
//!             Length stands on its own, this means it has no such thing as
//!             a zero point or a direction.
//!             The only attribute Length has, is the Length itself
//!             To create a length, not only a double must be given,
//!             but also the unit of it (METER or CENTIMETER).
//!
//!             For example:
//!             Length l(5 * Length::METER)
//!             This gives a Length of 5m.
//!             To get a double again, simply divide by the unit.

#ifndef _LENGTH_HPP
#define _LENGTH_HPP
#include "Acceleration.hpp"
#include "Duration.hpp"
#include "ADT_Base.hpp"
#include <iostream> 

namespace r2d2{
class Speed;
class Translation;

class Length: public ADT_Base<Length>{
    friend class Translation;
    friend class Acceleration;
    friend class Speed;

    protected:
        //! @fn     Length::Length(double l)
        //!
        //! @brief  Constructor of a Length
        //!
        //! @param  l The length value
        Length(double length);
	
    public:
        friend ADT_Base<Length>;
        //! @fn     Length::Length()
        //!
        //! @brief  Defaut constructor of length
        Length();

        //! @fn	std::ostream& Length::operator<< (std:: ostream& os, 
        //!const Length& rhs)
        //!
        //! @brief  appends a Length to an ostream and returns an ostream
        //!
        //! @param  os  The stream to which to write the string representation
        //!             of the length
        //! @param  rhs Reference to the object to write to the outputstream
        //! @return	ostream Reference to the stream passed in by os
        friend std::ostream& operator<< (std:: ostream& os, const Length& rhs);

        //! @fn  std::istream& Length::operator>>(std::istream& is,Length& rhs)
        //!
        //! @brief  adds an istream to a Length
        //!
        //! @param	is      The stream from which to read data
        //! @param	rhs     Reference to an uninitialized length to overwrite
        //! @return	istream Reference to the stream passed in by is
        friend std::istream& operator>>(std::istream& is, Length& rhs);

        //! @fn     Length Length::operator* (double n, const Length& rhs)
        //!
        //! @brief  multiply a Length by another Length and returns a Length
        //!
        //! @param	n       The number by which the length will be multiplied
        //!	@param	rhs     The length that will be multiplied by a number
        //! @return	Length  The result of the multiplication
        friend Length operator* (double n, const Length& rhs);

        //! @fn     Speed Length::operator/ (const Length & length, 
        //!         const Duration & d)
        //!
        //! @brief  divide length by duration and return the speed
        //!
        //! @param  length      The length that will be divided by a duration
        //!	@param  d           The duration that the length will be divided by
        //! @return Speed       The result of the division
        friend Speed operator/ (const Length & length, const Duration & d);

        static const Length METER;
        static const Length CENTIMETER;
};
}
#endif