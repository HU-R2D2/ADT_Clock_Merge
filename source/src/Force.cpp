// ++--++
// Roborescue
// @file <Force.cpp>
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
#include "../include/Force.hpp"

namespace r2d2{
const Force Force::NEWTON(1);
Force::Force(double value):ADT_Base<Force>(value){
}

Force::Force():ADT_Base<Force>(0.0){}

std::ostream& operator<<(std::ostream & os, const Force &rhs){
  os <<  rhs.value << "N";
  return os;
}

std::istream& operator>>(std::istream & is, Force & rhs){
  double value;
   std::string suffix;
   // Read the value, and remove any trailing whitespace.
   is >> value >> std::ws;
   if (!is) {
      throw std::invalid_argument{"Force: Reached end of stream before fully \
      reading a Force."};
   }
   // Construct the metric suffix.
   while(1) {
      char temp;
      // The end of the stream might coincidence with the end of 
      //the metric specifier.
      // As such do not throw an exception but test the current stream.
      if (is >> temp) {
         // A suffix for metric values only consist out of alphabetic 
          //characters;
         // anything else could indicate the end of this suffix
         // and should be put back.
         if (isalpha(temp)) {
            suffix += temp;
         } else {
            // That character is not supposed to be used by this stream;
            // put it back, as some other stream might rely on it.
            is.putback(temp);
            break;
         }
      } else {
         // No point in reading from an empty or corrupt stream.
         break;
      }
   }
   // Specifies all available suffixes, and which value corresponds to it.
   const struct {std::string suffix; 
     const Force & factor;} possible_suffixes[] = {
         {"N", Force::NEWTON}
   };
   for (const auto & possibility : possible_suffixes) {
      if (suffix == possibility.suffix) {
         rhs = value * possibility.factor;
         return is;
      }
   }
   throw std::invalid_argument{"Force: Either stream ended, or none of the \
   known extensions match the specified one."};
}

Force operator* ( const Mass & lhs, const Acceleration & rhs){
  double w = lhs/Mass::KILOGRAM;
  Speed one = 1 * Length::METER/Duration::SECOND;
  Acceleration ac = one/Duration::SECOND;
  double a = rhs/ac;
  return Force{w * a};
}
}