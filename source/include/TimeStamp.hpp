// @file <filename>
// @date Created: <5-3-16>
// @version <0.0.0>
//
// @author <full name>
//
// @section LICENSE
// License: newBSD
//
// Copyright � 2016, HU University of Applied Sciences Utrecht.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with
// or without modification, are permitted provided
// that the following conditions are met:
// - Redistributions of source code must retain the above
// copyright notice, this list of conditions and the following disclaimer.
// - Redistributions in binary form must reproduce the
// above copyright notice, this list of conditions and the
// following disclaimer in the documentation and/or
// other materials provided with the distribution.
// - Neither the name of the HU University of
// Applied Sciences Utrecht nor the names of its contributors
// may be used to endorse or promote products derived
// from this software without specific prior written permission.
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
#ifndef _TIMESTAMP_HPP
#define _TIMESTAMP_HPP


#include "../../../adt/source/include/ADT_Base.hpp"
#include "../../../adt/source/include/Duration.hpp"
#include <assert.h> 
#include <iostream>
#include <stdlib.h> 
#include <math.h>
#include <stdint.h>
#include <stdexcept>
using namespace std;

//! @author Ferdi Stoeltie 1665045
//! @brief Created specifically for the TimeStamp class, 
//!        it is meant as it's exception.
//! @date 05-04-2016

namespace r2d2{
class TimeStampException : public invalid_argument {
public:
    TimeStampException(string error) : invalid_argument{error} {}
    virtual const char* what() const throw() {
        return invalid_argument::what();
    }
};
    
class Duration;
//!    @author      Ferdi Stoeltie 1665045
//!    @date         05-04-2016
//!    @version     1.0.0
//!    @brief            This class provides a timestamp of a TimeStamp in time. 
//!                        Due to its use in R2D2 (as of yet), 
//!                        a TimeStamp object can only be created by the Clock.
class TimeStamp : public ADT_Base<TimeStamp>{
friend ADT_Base<TimeStamp>;
friend class Clock;
public:
    
    //!    @brief Public default constructor with time 0
    //!    A filled TimeStamp can be obtained by the Clock
    TimeStamp(); // Public default ctor

    /// assignment operator for a TimeStamp
    //!    @brief Assigns a given TimeStamp and its values, to the current TimeStamp
    //!    @param [in] refTimeStamp Uses this TimeStamp and its values
    //!    @return Current TimeStamp with values from given TimeStamp
    TimeStamp& operator= (const TimeStamp& refTimeStamp);

    // adds a duration to a TimeStamp and results in a TimeStamp
    //!    @brief Adds a Duration to the current TimeStamp and returns new TimeStamp
    //!    @param [in] refDuration uses this Duration to add
    //!    @return new TimeStamp by adding Duration and current TimeStamp
    TimeStamp operator+ ( const Duration& refDuration ) const;

    // Subtracts a duration to a TimeStamp and results in a TimeStamp
    
    //!    @brief Subtracts a Duration from the current TimeStamp
    //!    @param [in] refDuration uses this Duration to subtract
    //!    @return new TimeStamp by adding Duration and current TimeStamp
    TimeStamp operator- ( const Duration& refDuration ) const;

    // Subtracts a TimeStamp from a TimeStamp and results in a duration
    //!    @brief Subtracts a given TimeStamp from the current TimeStamp a duration
    //!    @param [in] a given TimeStamp
    //!    @return new Duration that is the result,
    //!    of subtracting a given TimeStamp from current TimeStamp
    //!    @warning Only accepts Durations with positive values
    Duration operator- (const TimeStamp& refTimeStamp) const;

    // adds a duration to a TimeStamp and returns this TimeStamp
    //!    @brief Adds a Duration to the current TimeStamp,
    //!        and returns the current TimeStamp with added result
    //!    @param [in] Duration const reference
    //!    @return Same TimeStamp with added duration
    TimeStamp& operator+= (const Duration& refDuration);

    /// substracts a duration from a TimeStamp and returns this TimeStamp
    //!    @brief Subtracts a Duration to the current TimeStamp,
    //!        and returns the current TimeStamp with added result
    //!    @param [in] Duration const reference
    //!    @return Same TimeStamp with subtracted duration
    //!    @warning Only accepts Durations with positive values
    TimeStamp& operator-= (const Duration& refDuration);
    
    //!    @brief Reads TimeStamp into given ostream
    //!    @param [in] lhs The ostream to which should be written
    //!    @param [in] The TimeStamp that contains the data
    //!    @return Same ostream for chaining
    friend ostream& operator<< (ostream& lhs, const TimeStamp& refDuration);
    
    //!    @brief Reads from stream data into TimeStamp, format: double
    //!    @param [in] lhs The istream from which should be read
    //!    @param [in] The TimeStamp that will contain the data
    //!    @return Same istream for chaining
    //! @exception <TimeStampException> Thrown when the stream,
    //!    format is wrong or a double is given < 0
    friend istream& operator>> (istream& lhs, TimeStamp& refDuration);
    
    //! @brief Returns current TimeStamp in time as a double
    //! @return Current time held by this TimeStamp as a double
    double get_time() const;
    
    //The following operators are deleted because they serve no purpose.
    //They were orignally declared in ATD_Base
    TimeStamp operator* (double number) const = delete;
    TimeStamp operator*= (double number) = delete;
    TimeStamp operator/ (double number) const = delete;
    TimeStamp operator/= (double number) = delete;
    double operator/ (const TimeStamp & rhs) const = delete;
    friend TimeStamp operator * (double n, const TimeStamp & rhs) = delete;
    
private:
    //!    @brief Creates a TimeStamp by its given parameter
    //!    @param time Time that will be stored within TimeStamp
    //! @exception <TimeStampException> Thrown when a time is given < 0
    TimeStamp(double time) throw (TimeStampException); // must be private
};
}
#endif 