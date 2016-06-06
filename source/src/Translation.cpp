//!	Roborescue
//! @file <Translation.cpp>
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
#include "../include/Translation.hpp"
namespace r2d2{
Translation::Translation():
    x(0),
    y(0),
    z(0)
{}

Translation::Translation(Length x, Length y, Length z) :
    x(x),
    y(y),
    z(z)
{}

Length Translation::get_x() const {
    return x;
}

Length Translation::get_y() const {
    return y;
}

Length Translation::get_z() const {
    return z;
}

Length Translation::get_length() const {
    Length length;
    double tempx = x / Length::METER;
    double tempy = y / Length::METER;
    double tempz = z / Length::METER;
    length = sqrt((tempx * tempx)+(tempy * tempy)+(tempz * tempz)) * Length::METER;
    return length;
}

Translation& Translation::operator= (const Translation& rhs){
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

Translation Translation::operator+ (const Translation& rhs) const {
    Translation temp(*this);
    temp.x += rhs.x;
    temp.y += rhs.y;
    temp.z += rhs.z;
    return temp;
}

Translation Translation::operator- (const Translation& rhs) const{
    Translation temp(*this);
    temp.x -= rhs.x;
    temp.y -= rhs.y;
    temp.z -= rhs.z;
    return temp;
}

Translation Translation::operator* (double number) const{
    Translation temp(*this);
    temp.x = temp.x * number;
    temp.y = temp.y * number;
    temp.z = temp.z * number;
    return temp;
}

Translation operator* (double number, const Translation& rhs) {
    Translation temp(rhs);
    temp.x = number * temp.x;
    temp.y = number * temp.y;
    temp.z = number * temp.z;
    return temp;
}
		
Translation Translation::operator/ (double number) const{
    Translation temp(*this);
    if(number == 0){
        return temp;
    }
    temp.x = temp.x / number;
    temp.y = temp.y / number;
    temp.z = temp.z / number;
    return temp;
}

Translation operator/ (double number, const Translation& rhs) {
    Translation temp(rhs);
    double tx = temp.x / Length::METER;
    double ty = temp.y / Length::METER;
    double tz = temp.z / Length::METER;
    if((tx != 0) && (ty != 0) && (tz != 0)){
        temp.x = number * Length::METER / tx;
        temp.y = number * Length::METER / ty;
        temp.z = number * Length::METER / tz;
    }
    return temp;
}
	
Translation& Translation::operator+= (const Translation& rhs){
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
    return *this;
}
	
Translation& Translation::operator-= (const Translation& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}
		
bool Translation::operator> (const Translation& rhs) const {
    return get_length() > rhs.get_length();
}
		
bool Translation::operator< (const Translation& rhs) const {
    return get_length() < rhs.get_length();
}
		
std::ostream& operator<< (std::ostream& lhs, Translation& rhs) {
    lhs << "(" << rhs.get_x() << ", " << rhs.get_y() << ", " << rhs.get_z() << ")";
    return lhs;
}

std::istream & operator >>(std::istream & lhs, Translation & rhs) {
   std::string prefix;
   lhs >> std::ws >> prefix;
   if (prefix != "Translation") {
      throw std::invalid_argument{
          "Expecting prefix\"Translation\",got something else(" + prefix + ")."
          };
   }
   char temp;
   lhs >> std::ws >> temp;
   if (temp != '(') {
      throw std::invalid_argument{"No opening brace encountered"};
   }

   Length x, y, z;

   auto ReadComponent = [](std::istream & lhs, char expectedSeperator) {
      Length value;
      char separator;
      lhs >> value >> separator;
      if(separator != expectedSeperator){
         throw std::invalid_argument{"Wrong or missing seperator."};
      }
      return value;
   };
   x = ReadComponent(lhs, ',');
   y = ReadComponent(lhs, ',');
   z = ReadComponent(lhs, ')');

   if (!lhs) {
      throw std::invalid_argument {
          "Translation wasn't read in its entirety when end of stream was reached."
          };
   }
   rhs.x = x;
   rhs.y = y;
   rhs.z = z;
   return lhs;
}
}