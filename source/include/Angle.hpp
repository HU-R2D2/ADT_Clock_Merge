////
//  ██████╗  ██████╗ ██████╗  ██████╗ ██████╗ ███████╗███████╗ ██████╗██╗   ██╗███████╗
//  ██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██║   ██║██╔════╝
//  ██████╔╝██║   ██║██████╔╝██║   ██║██████╔╝█████╗  ███████╗██║     ██║   ██║█████╗
//  ██╔══██╗██║   ██║██╔══██╗██║   ██║██╔══██╗██╔══╝  ╚════██║██║     ██║   ██║██╔══╝
//  ██║  ██║╚██████╔╝██████╔╝╚██████╔╝██║  ██║███████╗███████║╚██████╗╚██████╔╝███████╗
//  ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝
//
//
// @file Angle.hpp
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
#ifndef Angle_HPP
#define Angle_HPP
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

namespace r2d2{

    class Angle {
    private:

        double angle_radians;

        //!@brief Creates an Angle from a double
        //!@brief Anything larger than one circle (2pi) is modulo'd with 2pi
        //!@brief Note the constructor being private; refer to the deg and rad
        //!@brief constants to create a new Angle object from a double value
        //!@param angle_radians The Angle in radians
        Angle(double angle_radians);

        //!@brief value in Radians of one full circle
        static const double full_circle;

    public:

        Angle();

        //!@brief Copies the righthand value into this and returns a reference to this
        //!@param rhs Value to be copied into this
        Angle &operator=(const Angle &rhs);

        //!@brief Add the angle_radians value on the right hand to this
        //!@brief and returns the resulting Angle
        //!@param rhs Angle of which the angle_radians value has to be added to this
        Angle &operator+=(const Angle &rhs);

        //!@brief Subtracts the angle_radians value on the right hand from this and
        //!@brief returns the resulting Angle
        //!@param rhs Angle of which the angle_radians value has to be substracted
        //!@brief from this
        Angle &operator-=(const Angle &rhs);

        //!@brief Multplies the righthand Double with this' angle_radians value
        //!@param rhs Double to multiply this with
        Angle &operator*=(const double &rhs);

        //!@brief Divides this by the righthand Double
        //!@param rhs The Angle to divide this with
        Angle &operator/=(const double &rhs);

        //!@brief compares two Angles to each other and return a boolean
        //!@brief (true if 1st greater than 2nd)
        //!@param rhs The Angle that is being compared to the other Angle
        bool operator<(const Angle &rhs) const;

        //!@brief compares two Angles to each other and return a boolean
        //!@brief (true if 1st smaller  than 2nd)
        //!@param rhs The Angle that is being compared to the other Angle
        bool operator>(const Angle &rhs) const;

        //!@brief add the Angle in Radians value on the right hand to this
        //!@brief and returns an Angle
        //!@param rhs Angle of which the angle_radians value has to be added to this
        Angle operator+(const Angle &rhs) const;

        //!@brief subtracts the angle_radians value on the right hand from this and
        //!@brief returns the Angle
        //!@param rhs Angle of which the angle_radians value has to be
        //!@brief substracted from this
        Angle operator-(const Angle &rhs) const;

        //!@brief multiplies the Angle by a number and returns an Angle
        //!@param rhs The number by which the Angle will be multiplied
        Angle operator*(const double &rhs) const;

        //!@brief divides the Angle by a number and return an Angle
        //!@param rhs The number by which the Angle will be divided
        friend Angle operator*(const double &lhs, const Angle &rhs);

        //!@brief divides the Angle by a number and return an Angle
        //!@param rhs The number by which the Angle will be divided
        Angle operator/(const double &rhs) const;

        //!@brief divide an Angle by an Angle, returning a double
        //!@param Angle to divide this by
        double operator/(const Angle &rhs) const;

        //!@brief Output operator of an Angle
        //!@param lhs The ostream that will be appended
        //!@param rhs The Angle that will be added to the ostream
        friend std::ostream &operator<<(std::ostream &lhs, const Angle &rhs);

        //!@brief Getter for Angle, returns a double containing the angle value in
        //!@brief radians
        double get_angle();

        //!@brief A radian and a degree constant to convert a double in radians
        //!@brief respectively degrees to an Angle object in radians
        //!@brief Example usages:
        //!@brief create an Angle of 180 degrees:
        //!@brief Angle 180_degrees = 180.0 * Angle::deg
        //!@brief create an Angle of PI radians:
        //!@brief Angle pi_radians = PI * Angle::rad
        static const Angle rad;
        static const Angle deg;
    };

}

#endif