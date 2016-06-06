// ++--++
// Roborescue
// @file <Moment.hpp>
// @date Created: <5-3-16>
// @version <1.0.0>
//
// @author <Ferdi Stoeltie 1665045>
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
#ifndef _MOMENT_HPP
#define _MOMENT_HPP


#include "ADT_Base.hpp"
#include "Duration.hpp"
#include <assert.h> 
#include <iostream>
#include <stdlib.h> 
#include <math.h>
#include <stdint.h>
#include <stdexcept>
using namespace std;

//! @author Ferdi Stoeltie 1665045
//! @brief Created specifically for the Moment class, 
//!      it is meant as it's exception.
//! @date 05-04-2016
namespace r2d2{
class MomentException : public invalid_argument
{
public:
   MomentException(string error) : invalid_argument{error} {
   }
   virtual const char* what() const throw()
   {
      return invalid_argument::what();
   }
};
class Duration;
//!   @author     Ferdi Stoeltie 1665045
//!   @date       05-04-2016
//!   @version    1.0.0
//!   @brief         This class provides a timestamp of a moment in time. 
//!                  Due to its use in R2D2 (as of yet), 
//!                  a Moment object can only be created by the Clock.
class Moment : public ADT_Base<Moment>{
friend ADT_Base<Moment>;
friend class Clock;
// Testing only! remove when moment is merged with clock.
friend class test_Clock; 
public:
   
   //!   @brief Public default constructor with time 0
   //!   A filled Moment can be obtained by the Clock
   Moment(); // Public default ctor

   /// assignment operator for a moment
   //!   @brief Assigns a given Moment and its values, to the current Moment
   //!   @param [in] refMoment Uses this Moment and its values
   //!   @return Current Moment with values from given Moment
   Moment& operator= (const Moment& refMoment);

   // adds a duration to a moment and results in a moment
   //!   @brief Adds a Duration to the current Moment and returns new Moment
   //!   @param [in] refDuration uses this Duration to add
   //!   @return new Moment by adding Duration and current Moment
   Moment operator+ ( const Duration& refDuration ) const;

   // Subtracts a duration to a moment and results in a moment
   
   //!   @brief Subtracts a Duration from the current Moment
   //!   @param [in] refDuration uses this Duration to subtract
   //!   @return new Moment by adding Duration and current Moment
   Moment operator- ( const Duration& refDuration ) const;

   // Subtracts a moment from a moment and results in a duration
   //!   @brief Subtracts a given Moment from the current Moment a duration
   //!   @param [in] a given Moment
   //!   @return new Duration that is the result,
   //!   of subtracting a given Moment from current Moment
   //!   @warning Only accepts Durations with positive values
   Duration operator- (const Moment& refMoment) const;

   // adds a duration to a moment and returns this moment
   //!   @brief Adds a Duration to the current moment,
   //!      and returns the current moment with added result
   //!   @param [in] Duration const reference
   //!   @return Same Moment with added duration
   Moment& operator+= (const Duration& refDuration);

   /// substracts a duration from a moment and returns this moment
   //!   @brief Subtracts a Duration to the current moment,
   //!      and returns the current moment with added result
   //!   @param [in] Duration const reference
   //!   @return Same Moment with subtracted duration
   //!   @warning Only accepts Durations with positive values
   Moment& operator-= (const Duration& refDuration);
   
   //!   @brief Reads Moment into given ostream
   //!   @param [in] lhs The ostream to which should be written
   //!   @param [in] The Moment that contains the data
   //!   @return Same ostream for chaining
   friend ostream& operator<< (ostream& lhs, const Moment& refDuration);
   
   //!   @brief Reads from stream data into Moment, format: double
   //!   @param [in] lhs The istream from which should be read
   //!   @param [in] The Moment that will contain the data
   //!   @return Same istream for chaining
   //! @exception <MomentException> Thrown when the stream,
   //!   format is wrong or a double is given < 0
   friend istream& operator>> (istream& lhs, Moment& refDuration);
   
   //! @brief Returns current moment in time as a double
   //! @return Current time held by this moment as a double
   double get_time() const;
private:
   //!   @brief Creates a Moment by its given parameter
   //!   @param time Time that will be stored within moment
   //! @exception <MomentException> Thrown when a time is given < 0
   Moment(double time) throw (MomentException); // must be private
};
}
#endif 