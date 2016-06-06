// Roborescue
//
// @file Speed.hpp
// @date Created: 15-03-16
// @version 0.1
//
// @author Job Verhaar
//
// @section LICENSE
// License: newBSD
//
// Copyright ï¿½ 2016, HU University of Applied Sciences Utrecht.
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

#ifndef  _SPEED_HPP
#define _SPEED_HPP
#include <iostream>
#include "Duration.hpp"
#include "Length.hpp"
#include "ADT_Base.hpp"
namespace r2d2{
class Acceleration;

class Speed : public ADT_Base<Speed>{
protected:
    //! @fn 	Speed::Speed(double value)
    //!
    //! @brief	Constuctor of a Speed
    //!
    //! @param	value the speed value in m\s
    Speed(double value);
public:
    friend ADT_Base<Speed>;
    //! @fn 	Speed::Speed()
    //!
    //! @brief	Default constructor of Speed
    Speed();

    //! @fn 	Speed operator* (double n, const Speed& rhs)
    //!
    //! @brief 	Multiplies a double by a Speed and returns a Speed
    //! 
    //! @param	n 		a double
    //! @param	rhs 	the Speed that needs to be multiplied
    //! @return Speed 	the result of the multiplication
    friend Speed operator* ( double n, const Speed & rhs );

    //! @fn 	std::ostream operator<<(std::ostream& os, const Speed& rhs)
    //! 
    //! @brief	appends a Speed to an ostream and returns an ostream
    //!
    //! @param	os 		the outputstream
    //! @param 	rhs 	the Speed that needs to be added to the outputstream
    //! @return ostream the ostream with the appended Speed
    friend std::ostream& operator<<(std::ostream & os, const Speed &rhs);

    //! @fn 	std::istream operator>>(std::istream& is, Speed & rhs)
    //!
    //! @brief	Reads a speed from an inputstream
    //! 
    //! @param	is 		the inputstream where the Speed is read from
    //! @param	rhs 	the Speed where the readed value is stored in
    //! @return istream the istream without the readed Speed    
    friend std::istream& operator>>(std::istream & is, Speed & rhs);

    //! @fn 	Speed operator/(const Length & l, const Duration & d)
    //!
    //!	@brief	Divides a length by a duration and returns the calculated Speed
    //!
    //! @param	l 		the Length that is divided by a Duration
    //! @param	d 		the Duration that divides the Length
    //! @return Speed 	the calculated Speed in m/s
    friend Speed operator/ ( const Length & l, const Duration & d);

    //! @fn 	Length Speed::operator*(const Duration & d)
    //!
    //!	@brief	Multiplies a Speed by a duration and returns the calculated Length
    //!
    //! @param	rhs		the Duration that is multiplied by a Speed
    //! @return Length 	the calculated Length in m
    Length operator*(const Duration & rhs) const;

    //! @fn 	Length operator*(const Duration & lhs, const Speed & rhs)
    //!
    //!	@brief	Multiplies a Speed by a duration and returns the calculated Length
    //!
    //! @param	lhs		the Duration that is multiplied by a Speed
    //! @param 	rhs 	the Speed that is multiplied by a Duration
    //! @return Length 	the calculated Length in m
    friend Length operator*(const Duration & lhs, const Speed & rhs);
};

Speed operator/ ( const Length & l, const Duration & d);
}
#endif
