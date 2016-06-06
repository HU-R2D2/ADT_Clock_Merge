// ++--++
// @file <ADT_Base.hpp>
// @date Created: <5-3-16>
// @version <0.0.1>
//
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
//! @date 		05-04-16
//! @version 	0.1
//! @brief		Base class for standard ADT classes with one value
//!

#ifndef _ADT_BASE_HPP
#define _ADT_BASE_HPP


namespace r2d2{
template <class T> class ADT_Base
{
protected:
    double value;
    //! @fn     ADT_Base::ADT_Base(double)
    //! 
    //! @brief  Constructor of a Weight
    //!
    //! @param  value the value to assign
    ADT_Base(double value):value{value}{}
public:
    //! @fn      ADT_Base::ADT_Base()
    //!
    //! @brief   Default constructor
    ADT_Base():value{0.0}{}

    //! @fn     T& ADT_Base::operator=(cost T& rhs)
    //! 
    //! @brief  Assignment operator for a T
    //!
    //! @param  T the T that is assigned to the other
    T& operator= (const T& rhs){
        value = rhs.value;
        return *static_cast<T*>(this);
    }

    //! @fn		ADT_Base::operator+(const T& rhs) const
    //!
    //! @brief	Add operator of a T
    //!
    //! @param	number the number to add to the T
    T operator+ (const T& rhs) const{
        return T{value + rhs.value};
    } 

    //! @fn	    ADT_Base::operator+=(const T& rhs)
    //!
    //! @brief	Add assign operator of a T
    //!
    //! @param	number the number to add to the T 
    T& operator+= (const T& rhs){
        value += rhs.value;
        return *static_cast<T*>(this);
    }

    //! @fn		ADT_Base::operator-(const T& rhs) const
    //!
    //! @brief	substract operator of a T
    //!
    //! @param	number the number to subtrackt from the T
    T operator- (const T& rhs) const{
        return T{value - rhs.value};
    }

    //! @fn		ADT_Base::operator-=(const T& rhs)
    //!
    //! @brief	subtract assign operator of a T
    //!
    //! @param	number 		the number to subtract from the T
    T& operator-= ( const T& rhs){
        value -= rhs.value;
        return *static_cast<T*>(this);
    }

    //! @fn		ADT_Base::operator*(double number)
    //!
    //! @brief	multiply operator of a T
    //!
    //! @param	number the number to multyply the T by
    T operator* (double number) const{
        return T{value * number};
    }

    //! @fn		ADT_Base::operator*=(double number)
    //!
    //! @brief	multiply operator of a T
    //!
    //! @param	number the number to multyply the T by
    T operator*= (double number){
        value *= number;
        return *static_cast<T*>(this);
    }

    //! @fn 	ADT_Base::operator/(double number)
    //!
    //! @brief	division operator of a T
    //!
    //! @param	number the number to devide the T by
    T operator/ (double number) const{
        if(number != 0){
        return T{value / number};
        }
        return T{value};
    }

    //! @fn 	ADT_Base::operator/=(const T& rhs)
    //!
    //! @brief	division operator of a T
    //!
    //! @param	number the number to devide the T by
    T operator/= (double number){
        if(number != 0){
            value /= number;
        } 
        return *static_cast<T*>(this);
    }

    //! @fn 	ADT_Base::operator/(const T& rhs)
    //!
    //! @brief	division operator of a T
    //!
    //! @param	number the number to devide the T by
    double operator/ (const T & rhs) const{
        if(rhs.value != 0){
            return value / rhs.value;
        }
        return value;
    }

    //! @fn     T operator *(double n, const T& rhs)
    //!
    //! @brief  Multiplies a T by a double
    //!
    //! @param n a double.
    //! @param rhs a T.
    //! @return the calculated T.
    friend T operator * (double n, const T & rhs){
        return T{n * rhs.value};
    }


    //! @fn		T::T(const T& rhs)
    //!
    //! @brief	greater then operator of a T
    //!
    //! @param	rhs 		the right hand side to compare 
    bool operator> (const T& rhs) const{
        return value > rhs.value;
    }

    //! @fn		T::T(const T& rhs)
    //!
    //! @brief	smaller then operator of a T
    //!
    //! @param	rhs 		the right hand side to compare 
    bool operator< (const T& rhs) const{
        return value < rhs.value;
    }

};
}
#endif