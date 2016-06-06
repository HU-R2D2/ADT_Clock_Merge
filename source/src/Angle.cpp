////
//  ██████╗  ██████╗ ██████╗  ██████╗ ██████╗ ███████╗███████╗ ██████╗██╗   ██╗███████╗
//  ██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██║   ██║██╔════╝
//  ██████╔╝██║   ██║██████╔╝██║   ██║██████╔╝█████╗  ███████╗██║     ██║   ██║█████╗
//  ██╔══██╗██║   ██║██╔══██╗██║   ██║██╔══██╗██╔══╝  ╚════██║██║     ██║   ██║██╔══╝
//  ██║  ██║╚██████╔╝██████╔╝╚██████╔╝██║  ██║███████╗███████║╚██████╗╚██████╔╝███████╗
//  ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝
//
//
// @file Angle.cpp
// @date Created: 29-03-16
// @version 2.1.0
//
// @author Casper Wolf
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
////

#include "../include/Angle.hpp"

namespace r2d2{

    const double Angle::full_circle = M_PI * 2.0;
    const Angle Angle::rad{1.0};
    const Angle Angle::deg{M_PI / 180.0};

    Angle::Angle() : angle_radians{0.0} { }

    Angle::Angle(double angle_radians) : angle_radians{
        fmod(angle_radians, full_circle) } {}

    Angle &Angle::operator=(const Angle &rhs) {
        angle_radians = rhs.angle_radians;
        return *this;
    }

    Angle &Angle::operator+=(const Angle &rhs) {
        angle_radians += rhs.angle_radians;
        return *this;
    }

    Angle &Angle::operator-=(const Angle &rhs) {
        angle_radians -= rhs.angle_radians;
        return *this;
    }

    Angle &Angle::operator*=(const double &rhs) {
        angle_radians *= rhs;
        return *this;
    }

    Angle &Angle::operator/=(const double &rhs) {
        angle_radians /= rhs;
        return *this;
    }

    bool Angle::operator<(const Angle &rhs) const {
        return angle_radians < rhs.angle_radians;
    }

    bool Angle::operator>(const Angle &rhs) const {
        return angle_radians > rhs.angle_radians;
    }

    Angle Angle::operator+(const Angle &rhs) const {
        Angle result{*this};
        result += rhs;
        return result;
    }

    Angle Angle::operator-(const Angle &rhs) const {
        Angle result{*this};
        result -= rhs;
        return result;
    }

    Angle Angle::operator*(const double &rhs) const {
        Angle result{*this};
        result *= rhs;
        return result;
    }

    Angle Angle::operator/(const double &rhs) const {
        Angle result{*this};
        result /= rhs;
        return result;
    }

    double Angle::operator/(const Angle &rhs) const {
        return angle_radians / rhs.angle_radians;
    }

    std::ostream &operator<<(std::ostream &lhs, const Angle &rhs) {
        return (lhs << rhs.angle_radians << " rad");
    }

    double Angle::get_angle() {
        return angle_radians;
    }

    Angle operator*(const double &lhs, const Angle &rhs) {
        return Angle{rhs} *= lhs;
    }

}