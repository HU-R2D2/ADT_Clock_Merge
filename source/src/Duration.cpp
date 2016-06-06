//! @file <Duration.cpp>
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

#include "../include/Duration.hpp"
#include <stdexcept>

namespace r2d2{
const Duration Duration::SECOND(1.0);
const Duration Duration::MILLISECOND(1.0/1000.0);
const Duration Duration::MINUTE(60.0);

Duration::Duration():
    ADT_Base<Duration>(0.0)
{}

Duration::Duration(double value): 
    ADT_Base<Duration>(value) 
{}

std::ostream& operator<<(std::ostream& lhs, const Duration& rhs) {
    lhs<< rhs.value << "s";
    return lhs;
}

std::istream & operator>>(std::istream & lhs, Duration & rhs) {
    std::string prefix;
    double seconds;
    lhs >> std::ws >> prefix;
    if (prefix != "Duration") {
        throw std::invalid_argument{
            "Expecting prefix \"duration\", got something else."};
    }
    lhs >> seconds;
    if (!lhs) {
        throw std::invalid_argument{
            "Duration wasn't read in its entirety when end of stream was reached."};
    }
    rhs.value = seconds;
    return lhs;
}

double Duration::get_seconds() const {
    return value;
}
}