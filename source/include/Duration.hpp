//! @file <Duration.hpp>
//! @date Created: <5-3-16>
//! @version <1.0.0>
//!
//! @author <Casper Wolf & Job Verhaar>
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


//! @author Casper Wolf & Job Verhaar
//! @date 14-03-16
//! @version 0.1
//!
//! @brief A length of time (interval between two TimeStamps).
//! Duration is a ratio scale: addition and subtraction of differences 
//! are meaningful (and yield durations), and so are multiplication 
//! and division by a scalar (also yield a duration).

#ifndef  _DURATION_HPP
#define _DURATION_HPP

#include <iostream>
#include "TimeStamp.hpp"
#include "ADT_Base.hpp"
namespace r2d2{
class Speed;
class Length;
class Acceleration;


class Duration : public ADT_Base<Duration>{
    protected:
        //! @fn     Duration(double value)
        //!
        //! @brief  Constructor of a Duration
        //!
        //! @param  l The Duration value
        explicit Duration(double value);
		
    public:
        friend Speed;  
        friend ADT_Base<Duration>;
        
        //! @fn     Duration::Duration()
        //!
        //! @brief  Defaut constructor of Duration
        Duration();
        
        //! @fn     double Duration::get_seconds() const
        //!
        //! @brief  Gets the seconds value of the Duration and returns it
        //!
        //! @return	Length	The seconds value of the Duration
        double get_seconds() const;

        //! @fn     Duration operator* ( double n, const Duration & rhs)
        //!
        //! @brief  multiplies a number by a Duration and returns a Duration
        //!
        //! @param	n       The number that will be multiplied by the Duration
        //!	@param	rhs     The Duration by which the number will be multiplied
        //! @return	Duration The result of the multiplication
        friend Duration operator* (double n, const Duration & rhs);
        
        //! @fn     Speed operator/ (const Length & l, const Duration & d)
        //!
        //! @brief  divides a Length by a Duration and returns a Speed
        //!
        //! @param	lhs     The Length that will be divided by the Duration
        //!	@param	d       The Duration by which the Length will be divided
        //! @return	Length  The result of the division
        friend Speed operator/ (const Length & l, const Duration & d);
        
        //! @fn     Length operator*(const Duration & lhs, const Speed & rhs)
        //!
        //! @brief  multiplies a Duration by a Speed and returns a Length
        //!
        //! @param	lhs     The Duration by which the Speed will be multiplied
        //!	@param	rhs     The Speed that will be multiplied by the Duration
        //! @return	Length  The result of the multiplication
        friend Length operator*(const Duration & lhs, const Speed & rhs);     
        
        //! @fn    std::istream& Duration::operator>>(std::istream& is,
        //!        Duration& rhs)
        //!
        //! @brief  adds an istream to a Duration
        //!
        //! @param	is      The stream from which to read data
        //! @param	rhs     Reference to an uninitialized Duration to overwrite
        //! @return	istream Reference to the stream passed in by is
        friend std::istream& operator>>(std::istream& is, Duration& rhs);	

        //! @fn	std::ostream& Duration::operator<<(std::ostream& os, 
        //!     const Duration& rhs)
        //!
        //! @brief  appends a Duration to an ostream and returns an ostream
        //!
        //! @param  os The stream to which to write the string representation
        //!         of the Duration
        //! @param  rhs Reference to the object to write to the outputstream
        //! @return	ostream Reference to the stream pas
        friend std::ostream& operator<<(std::ostream& os, const Duration &rhs);
        
        static const Duration SECOND;
        static const Duration MILLISECOND;
        static const Duration MINUTE;
};
}
#endif

