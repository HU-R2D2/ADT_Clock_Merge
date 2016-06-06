//!	Roborescue
//! @file <Translation.hpp>
//! @date Created: <5-3-16>
//! @version <1.0.1>
//!
//! @author <Remco Nijkamp>
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

#ifndef  _Translation_HPP
#define _Translation_HPP
 
#include "Length.hpp"
#include <iostream>
#include <math.h>

namespace r2d2{
class Coordinate;

//! @brief      Translation is a 3-vector with an x, y and z value.
//!             A Translation can be described as the difference
//!             between two Coordinates.
class Translation {
    friend class Coordinate;
    friend class Box;
    public:
        //! @fn     Translation::Translation()
        //!
        //! @brief  Default constructor of a Translation
        Translation();

        //! @fn     Translation::Translation(Length x, Length y, Length z)
        //! 
        //! @brief  Constructor of a Translation
        //!  
        //! @param  x       The X coordinate of the Translation
        //! @param  y	    The Y coordinate of the Translation
        //! @param  z	    The Z coordinate of the Translation
        Translation(Length x, Length y, Length z);
		
        public:
            
        //! @fn     Length Translation::get_x()
        //!
        //! @brief  Gets the x Length value of the Translation and returns it
        //!
        //! @return	Length	The x Length of the Translation
                 
        Length get_x() const;
		
        //! @fn     Length Translation::get_y()
        //!
        //! @brief  Gets the y Length value of the Translation and returns it
        //!
        //! @return	Length  The y Length of the Translation
                 
        Length get_y() const;
		
        //! @fn     Length Translation::get_z()
        //!
        //! @brief  Gets the z Length value of the Translation and returns it
        //!
        //! @return	Length  The z Length of the Translation
                 
        Length get_z() const;
	
        //! @fn     Length Translation::get_length()
        //!
        //! @brief  Gets calculated Length of the Translation and returns it
        //!
        //! @return	Length  The absolute Length of the Translation
                 
        Length get_length() const;
		
        //! @fn     Translation& Translation::operator=(const Translation& rhs)
        //!
        //! @brief  Assignment operator of a Translation
        //!
        //! @param  rhs     The right hand sight Translation, this one is 
        //!                 being assigned to another Translation
        //! @return	Translation& Reference to the Translation on which the 
        //!                      assignment operator was called
                 
        Translation& operator= (const Translation& rhs);
		
        //! @fn Translation Translation::operator+(const Translation& rhs) const
        //!
        //! @brief  Add operator of a Translation
        //!
        //! @param  rhs     The right hand sight Translation, this one is being
        //!                 added to another Translation
        //! @return	Translation	The Translation on which the add operator
        //!                     was called
                 
        Translation operator+ (const Translation& rhs) const;
		
        //! @fn Translation Translation::operator-(const Translation& rhs) const
        //!
        //! @brief  Substract operator of a Translation
        //!
        //! @param  rhs     The right hand sight Translation, this one is being
        //!                 substracted from another Translation
        //! @return	Translation	The Translation on which the substract operator
        //!                     was called
                 
        Translation operator- (const Translation& rhs) const;
		
        //! @fn     Translation Translation::operator * (double number) const
        //!
        //! @brief  Multiply operator of a Translation
        //!
        //! @param  number  The number by which the Translation is being
        //!                 multiplied
        //! @return	Translation	The Translation on which the multiply 
        //!                     operator was called
                 
        Translation operator * (double number) const;
		
        //! @fn     Translation Translation::operator* (double number
        //!         const Translation& rhs)
        //!
        //! @brief  Multiply operator of a Translation
        //!
        //! @param  number  The number by which the Translation is
        //!                 being multiplied
        //! @return	Translation	The Translation on which the multiply operator
        //!                     was called
                
        friend Translation operator* (double number, const Translation& rhs);
                
        //! @fn     Translation Translation::operator/ (double number,
        //!         const Translation& rhs)
        //!
        //! @brief  Division operator of a Translation
        //!
        //! @param  number  The number by which the Translation is being divided
        //! @return	Translation	The Translation on which the division 
        //!                     operator was called
                 
        friend Translation operator/ (double number, const Translation& rhs);
		
        //! @fn     Translation Translation::operator/ (double number) const
        //!
        //! @brief  Division operator of a Translation
        //!
        //! @param  number The number by which the Translation is being divided
        //! @return	Translation	The Translation on which the division 
        //!                     operator was called
                 
        Translation operator/ (double number) const;
                
        //! @fn    Translation& Translation::operator+=(const Translation& rhs)
        //!
        //! @brief  AddAssign operator of a Translation
        //!
        //! @param  rhs     The right hand sight Translation, this one is being
        //!                 added to another Translation
        //! @return	Translation& Reference to the Translation on which the
        //!                      addAssignment operator was called
                    
        Translation& operator+= (const Translation& rhs);
		
        //! @fn    Translation& Translation::operator-=(const Translation& rhs)
        //!
        //! @brief  SubstractAssign operator of a Translation
        //!
        //! @param  rhs	    The right hand sight Translation, this one is being
        //!                 substracted from another Translation
        //! @return	Translation& Reference to the Translation on which the
        //!                      substractAssignment operator was called
                    
        Translation& operator-= (const Translation& rhs);
                
        //! @fn     bool Translation::operator> (const Translation& rhs) const
        //!
        //! @brief  GreaterThan operator of a Translation
        //!
        //! @param  rhs     The right hand sight Translation, this one will be
        //!                 compared to another Translation
        //! @return	bool    True if length is greater, False if not
                 
        bool operator> (const Translation& rhs) const;
		
        //! @fn     bool Translation::operator< (const Translation& rhs) const
        //!
        //! @brief  LessThan operator of a Translation
        //!
        //! @param  rhs     The right hand sight Translation, this one will be
        //!                 compared to another Translation
        //! @return	bool    True if length is smaller, False if not
                 
        bool operator< (const Translation& rhs) const;
                
        //! @fn     std::ostream& Translation::operator<< (std::ostream& lhs,
        //!                       const Translation& rhs) const
        //!
        //! @brief  Output operator of a Translation
        //!
        //! @param  lhs     The left hand sight ostream, to this ostream the
        //!                 Translation will be added
        //! @param  rhs     The right hand sight Translation, this one will
        //!                 be added to the lhs ostream
        //! @return	ostream& Reference to the tweaked lhs ostream
                 
        friend std::ostream& operator<< (std::ostream& lhs, Translation& rhs);

        //! @fn     Translation&    Translation::operator>>(std::istream& lhs,
        //!                         Translation& rhs)
        //!
        //! @brief  Input operator of a Translation
        //!
        //! @param  lhs     The istream, from this istream the Translation
        //!                 will be adapted
        //! @param  rhs     The right hand sight Translation, this one will
        //!                 be adapted by the lhs istream
        //! @return	Translation& Reference to rhs Translation which is adapted
        //!                      by information from the lhs
               
        friend std::istream& operator>>(std::istream& lhs, Translation& rhs);
                
    private:
            Length x,y,z;
};
}
#endif