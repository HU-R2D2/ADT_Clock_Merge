// ++--++
// Roborescue
// @file <Mass.cpp>
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
#include "../include/Mass.hpp"
#include <stdexcept>

namespace r2d2{
//constants
const Mass Mass::KILOGRAM(1);
const Mass Mass::GRAM(1/1000);

Mass::Mass(double value):ADT_Base<Mass>(value){

}

Mass::Mass():Mass(0.0){

}

std::ostream& operator<< (std:: ostream& os, const Mass& rhs){
    os << rhs.value << "Kg";
    return os;
}

std::istream& operator>>(std::istream& is, Mass& rhs){
    double value;
    std::string suffix;
    is >> value >> std::ws;
    if (!is) {
        throw std::invalid_argument{"Lenght: Reached end of stream before \
        fully reading a length."};
    }
    while(1) {
        char temp;
        if (is >> temp) {
            if (isalpha(temp)) {
                suffix += temp;
            } else {
                is.putback(temp);
                break;
            }
        } else {
            break;
        }
    }
    const struct {std::string suffix; 
     const Mass & factor;} possible_suffixes[] = {
        {"Kg", Mass::KILOGRAM}
    };
    for (const auto & possibility : possible_suffixes) {
        if (suffix == possibility.suffix) {
            rhs = value * possibility.factor;
            return is;
        }
    }
    throw std::invalid_argument{"Length: Either stream ended, or none of the \
    known extensions match the specified one."};
}
}