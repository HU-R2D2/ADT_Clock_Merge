// ++--++
// Roborescue
// @file Speed.cpp
// @date Created: 15-03-16
// @version 0.1
//
// @author Job Verhaar
//
// @section LICENSE
// License: newBSD
//
// Copyright 2016, HU University of Applied Sciences Utrecht.
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
#include "../include/Speed.hpp"
// Constructors
namespace r2d2{
Speed::Speed(double value): ADT_Base<Speed>(value){}

// Operators
Speed operator/ ( const Length & l, const Duration & d){
    if (d.value != 0){
        return Speed{l/Length::METER / (d/Duration::SECOND)}; 
    }
    return Speed{0};
}

Length Speed::operator*(const Duration & rhs) const{
    Length l = value * rhs.value * Length::METER;
    return l;
}

Length operator*(const Duration & lhs, const Speed & rhs){
    Length l = lhs.value * rhs.value * Length::METER;
    return l;
}


std::ostream& operator<<(std::ostream & os, const Speed &rhs){
    os << rhs.value << "m/s";
    return os;
}

std::istream& operator>>(std::istream & is, Speed & rhs){
    Length distance;
    char per;
    std::string time_span;
    // TODO: make sure any characters beyond timespan are not considered.
    is >> distance >> std::ws >> per >> std::ws >> time_span;
    if (per != '/') {
        throw std::invalid_argument{"Speed: Missing character \'/\'."};
    }
    const struct {std::string suffix; 
      const Duration & factor;} possible_suffixes[] = {
        {"s", Duration::SECOND},
        {"ms", Duration::MILLISECOND}
    };
    for (const auto & possibility : possible_suffixes) {
        if (time_span == possibility.suffix) {
            rhs = distance / possibility.factor;
            return is;      
        }
    }
    throw std::invalid_argument{"Speed: Either stream ended, or none of the \
    known extensions match the specified one."};
}
}