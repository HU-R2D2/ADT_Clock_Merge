////
//  ██████╗  ██████╗ ██████╗  ██████╗ ██████╗ ███████╗███████╗ ██████╗██╗   ██╗███████╗
//  ██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██║   ██║██╔════╝
//  ██████╔╝██║   ██║██████╔╝██║   ██║██████╔╝█████╗  ███████╗██║     ██║   ██║█████╗  
//  ██╔══██╗██║   ██║██╔══██╗██║   ██║██╔══██╗██╔══╝  ╚════██║██║     ██║   ██║██╔══╝  
//  ██║  ██║╚██████╔╝██████╔╝╚██████╔╝██║  ██║███████╗███████║╚██████╗╚██████╔╝███████╗
//  ╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝
//                                                                                                                                          
//
// @file BoxTest.cpp
// @date Created: 14-03-2016
// @version 1.0
//
// @author Stephan Vivie
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

#include "../source/include/Box.hpp"
#include "gtest/gtest.h"
#include <iostream>

using namespace r2d2;

TEST(Box, Constructor)
{
    Coordinate bl = Coordinate::origin;
    Coordinate tr = Coordinate::origin;
    Box box;

    // get bottomLeft
    ASSERT_DOUBLE_EQ(bl.get_x() / Length::METER, 
        box.get_bottom_left().get_x() / Length::METER);

    ASSERT_DOUBLE_EQ(bl.get_y() / Length::METER, 
        box.get_bottom_left().get_y() / Length::METER);

    ASSERT_DOUBLE_EQ(bl.get_z() / Length::METER, 
        box.get_bottom_left().get_z() / Length::METER);

    // get topRight
    ASSERT_DOUBLE_EQ(tr.get_x() / Length::METER, 
        box.get_top_right().get_x() / Length::METER);

    ASSERT_DOUBLE_EQ(tr.get_y() / Length::METER, 
        box.get_top_right().get_y() / Length::METER);

    ASSERT_DOUBLE_EQ(tr.get_z() / Length::METER, 
        box.get_top_right().get_z() / Length::METER);

}

TEST (Box, Coordinates) {
    // construct Box object with 2 Coordinates
    Coordinate bl = Coordinate::origin;

    Coordinate tr = Coordinate(
        50.0  * Length::METER, 
        50.0  * Length::METER, 
        50.0  * Length::METER
    );

    Box box (bl, tr);

    // get bottomLeft
    ASSERT_DOUBLE_EQ(bl.get_x() / Length::METER, 
        box.get_bottom_left().get_x() / Length::METER);

    ASSERT_DOUBLE_EQ(bl.get_y() / Length::METER, 
        box.get_bottom_left().get_y() / Length::METER);

    ASSERT_DOUBLE_EQ(bl.get_z() / Length::METER, 
        box.get_bottom_left().get_z() / Length::METER);


    // get topRight
    ASSERT_DOUBLE_EQ(tr.get_x() / Length::METER, 
        box.get_top_right().get_x() / Length::METER);

    ASSERT_DOUBLE_EQ(tr.get_y() / Length::METER, 
        box.get_top_right().get_y() / Length::METER);

    ASSERT_DOUBLE_EQ(tr.get_z() / Length::METER, 
        box.get_top_right().get_z() / Length::METER);


}

TEST (Box, CoordinateTranslation) {
    // construct Box object with Coordinate and Translation
    Translation evenTranslation (
        50.0  * Length::METER,
        50.0  * Length::METER,
        50.0  * Length::METER
    );

    Coordinate origin = Coordinate::origin;

    
    Box rectangleBox (origin, evenTranslation);
    ASSERT_DOUBLE_EQ(
        rectangleBox.get_top_right().get_x() / Length::METER,
        50.0
    );

    ASSERT_DOUBLE_EQ(
        rectangleBox.get_top_right().get_y() / Length::METER,
        50.0
    );

    ASSERT_DOUBLE_EQ(
        rectangleBox.get_top_right().get_z() / Length::METER, 
        50.0
    );

    Translation unevenTranslation (
        25.0  * Length::METER,
        0.0  * Length::METER,
        50.0  * Length::METER
    );

    Box noRectangleBox (origin, unevenTranslation);
    
    ASSERT_DOUBLE_EQ(
        noRectangleBox.get_top_right().get_x() / Length::METER, 
        25.0
    );

    ASSERT_DOUBLE_EQ(
        noRectangleBox.get_top_right().get_y() / Length::METER, 
        0.0
    );

    ASSERT_DOUBLE_EQ(
        noRectangleBox.get_top_right().get_z() / Length::METER, 
        50.0
    );

}


TEST (Box, Assign) {

    Box boxOne (
        Coordinate::origin, 
        Coordinate(
            25.0  * Length::METER,
            25.0  * Length::METER, 
            25.0  * Length::METER
        )
    );
    Box boxTwo (
        Coordinate::origin + 

        Translation{
            50.0  * Length::METER,
            50.0  * Length::METER,
            50.0  * Length::METER
        }, 

        Coordinate::origin + 
        
        Translation{
            100.0  * Length::METER,
            100.0  * Length::METER,
            100.0  * Length::METER}
        );

    // assign boxTwo to boxOne
    boxOne = boxTwo;

    ASSERT_DOUBLE_EQ(
        boxOne.get_bottom_left().get_x() / Length::METER,
        50.0
    );

    ASSERT_DOUBLE_EQ(
        boxOne.get_bottom_left().get_y() / Length::METER, 
        50.0
    );

    ASSERT_DOUBLE_EQ(
        boxOne.get_bottom_left().get_z() / Length::METER, 
        50.0
    );

    ASSERT_DOUBLE_EQ(
        boxOne.get_top_right().get_x() / Length::METER, 
        100.0
    );

    ASSERT_DOUBLE_EQ(
        boxOne.get_top_right().get_y() / Length::METER, 
        100.0
    );

    ASSERT_DOUBLE_EQ(
        boxOne.get_top_right().get_z() / Length::METER, 
        100.0
    );
}

TEST (Box, Ostream) {
    Coordinate bl = Coordinate::origin + Translation{};
    Coordinate tr = Coordinate::origin + Translation{
        50.0  * Length::METER, 
        50.0  * Length::METER, 
        50.0  * Length::METER
    };

    Box box (bl, tr);

    std::stringstream stream{};
    stream << box << std::endl;
    std::string output;
    std::getline(stream, output);

    EXPECT_EQ(
        "box (coordinate (0m, 0m, 0m), coordinate (50m, 50m, 50m))", 
        output
    );
}

TEST(Box, Istream) {
    std::stringstream stream{};
    Box box;

    // Check whether the coordinate is read in correct form from the stream.
    stream << "box ( coordinate ( 0m, 0m, 0m )" <<
        " coordinate ( 100m, 100m, 100m ) )";

    stream >> box;

    ASSERT_DOUBLE_EQ(
        box.get_bottom_left().get_x() / Length::METER, 
        0.0
    );
    ASSERT_DOUBLE_EQ(
        box.get_bottom_left().get_y() / Length::METER, 
        0.0
    );
    ASSERT_DOUBLE_EQ(
        box.get_bottom_left().get_z() / Length::METER, 
        0.0
    );

    ASSERT_DOUBLE_EQ(
        box.get_top_right().get_x() / Length::METER, 
        100.0
    );
    ASSERT_DOUBLE_EQ(
        box.get_top_right().get_y() / Length::METER, 
        100.0
    );
    ASSERT_DOUBLE_EQ(
        box.get_top_right().get_z() / Length::METER, 
        100.0
    );
    
}


TEST (Box, ContainsCoordinate) {
    Coordinate bl = Coordinate::origin + Translation{};
    Coordinate tr = Coordinate::origin + Translation{
        50.0  * Length::METER, 
        50.0  * Length::METER, 
        50.0  * Length::METER
    };

    Box box (bl, tr);

    // test coordinate thats inside box
    Coordinate inside = Coordinate::origin + Translation{
        25.0  * Length::METER,
        25.0  * Length::METER,
        25.0  * Length::METER
    };

    ASSERT_EQ(box.contains(inside), true);

    // test coordinate thats outside box
    Coordinate outside = Coordinate::origin + Translation{
        75.0  * Length::METER,
        75.0  * Length::METER,
        75.0  * Length::METER
    };

    ASSERT_EQ(box.contains(outside), false);

    Box negativeBox(
        Coordinate::origin + Translation{
            -25.0  * Length::METER,
            -25.0  * Length::METER,
            -25.0  * Length::METER
        },
        Coordinate::origin + Translation{
            -75.0  * Length::METER,
            -75.0  * Length::METER,
            -75.0  * Length::METER
        }
    );

    // test coordinate thats inside negative box
    Coordinate insideNegative = Coordinate::origin + Translation{
        -50.0  * Length::METER,
        -50.0  * Length::METER,
        -50.0  * Length::METER
    };

    ASSERT_EQ(negativeBox.contains(insideNegative), true);

    // test coordinate thats outside negative box
    Coordinate outsideNegative = Coordinate::origin + Translation{
        -150.0  * Length::METER,
        -150.0  * Length::METER,
        -150.0  * Length::METER
    };

    ASSERT_EQ(negativeBox.contains(outsideNegative), false);
    ASSERT_EQ(negativeBox.contains(outside), false);
}

TEST (Box, ContainsBox) {
    Box box(Coordinate::origin + Translation(), 
        Coordinate(
            100.0  * Length::METER,
            100.0  * Length::METER,
            100.0  * Length::METER
        )
    );
    
    // test box thats inside box
    Box insideBigBox(
        Coordinate(
            50.0  * Length::METER,
            50.0  * Length::METER,
            50.0  * Length::METER
        ), 
        Coordinate(
            75.0  * Length::METER,
            75.0  * Length::METER,
            75.0  * Length::METER
        )
    );

    ASSERT_EQ(box.contains(insideBigBox),true);

    // test box thats outside box
    Box outsideBigBox(
        Coordinate(
            150.0 * Length::METER,
            150.0 * Length::METER,
            150.0 * Length::METER), 
        Coordinate(
            200.0 * Length::METER,
            200.0 * Length::METER,
            200.0 * Length::METER));

    ASSERT_EQ(box.contains(outsideBigBox), false);

    // test boxes that collide 
    // (shouldn't return true as it isn't fully inside the box)
    Box collidesWithBigBox(
        Coordinate(
            50.0 * Length::METER,
            50.0 * Length::METER,
            50.0 * Length::METER), 
        Coordinate(
            200.0 * Length::METER,
            200.0 * Length::METER,
            200.0 * Length::METER)
    );

    ASSERT_EQ(box.contains(collidesWithBigBox), false);
    
    Box negativeBox(
        Coordinate(
            -50.0 * Length::METER,
            -50.0 * Length::METER,
            -50.0 * Length::METER), 
        Coordinate(
            -100.0 * Length::METER,
            -100.0 * Length::METER,
            -100.0 * Length::METER)
    );
    
    // test negative box that is inside the box 
    Box negativeBoxInside(
        Coordinate(
            -60.0 * Length::METER,
            -60.0 * Length::METER,
            -60.0 * Length::METER), 
        Coordinate(
            -70.0 * Length::METER,
            -70.0 * Length::METER,
            -70.0 * Length::METER)
    );

    ASSERT_EQ(negativeBox.contains(negativeBoxInside), true);

    // test negative box that intersects but isnt fully inside the box
    Box negativeBoxIntersects(
        Coordinate(
            -75.0 * Length::METER,
            -75.0 * Length::METER,
            -75.0 * Length::METER), 
        Coordinate(
            -125.0 * Length::METER,
            -125.0 * Length::METER,
            -125.0 * Length::METER)
    );

    ASSERT_EQ(negativeBox.contains(negativeBoxIntersects), false);

    // test negative box that doesnt intersect at all
    Box negativeBoxOutside(
        Coordinate(
            -175.0 * Length::METER,
            -175.0 * Length::METER,
            -175.0 * Length::METER), 
        Coordinate(
            -125.0 * Length::METER,
            -125.0 * Length::METER,
            -125.0 * Length::METER)
    );

    ASSERT_EQ(negativeBox.contains(negativeBoxOutside), false); 
}

TEST (Box, IntersectsBox) {
    Box box(
        Coordinate::origin + Translation(), 
        Coordinate(
            100.0 * Length::METER,
            100.0 * Length::METER,
            100.0 * Length::METER)
    );

    // test box that is inside
    Box insideBox(
        Coordinate(
            25.0 * Length::METER,
            25.0 * Length::METER,
            25.0 * Length::METER), 
        Coordinate(
            75.0 * Length::METER,
            75.0 * Length::METER,
            75.0 * Length::METER));
    ASSERT_EQ(box.intersects(insideBox), true);

    // test box that intersects but isn't completely inside
    Box intersectBox(
        Coordinate(
            50.0 * Length::METER,
            50.0 * Length::METER,
            50.0 * Length::METER), 
        Coordinate(
            150.0 * Length::METER,
            150.0 * Length::METER,
            150.0 * Length::METER));
    ASSERT_EQ(box.intersects(intersectBox), true);

    // test box that doesn't intersect at all
    Box outsideBox(
        Coordinate(
            200.0 * Length::METER,
            200.0 * Length::METER,
            200.0 * Length::METER), 
        Coordinate(
            500.0 * Length::METER,
            500.0 * Length::METER,
            500.0 * Length::METER));
    ASSERT_EQ(box.intersects(outsideBox), false);

    // test box that doesn't have coordinates inside of eachother 
    // (Collision between box.topleftfront 
    // and noCoordinateBox.bottomrightback corner)
    Box newBox(
        Coordinate(
            0.0  * Length::METER,
            0.0  * Length::METER,
            0.0  * Length::METER), 
        Coordinate(
            100.0  * Length::METER,
            100.0  * Length::METER,
            100.0 * Length::METER));
    Box noCoordinateBox(
        Coordinate(
            -50.0 * Length::METER,
            50.0 * Length::METER,
            0.0 * Length::METER), 
        Coordinate(
            50.0 * Length::METER,
            150.0 * Length::METER,
            100.0 * Length::METER
        )
    );

    ASSERT_EQ(true, newBox.intersects(noCoordinateBox));


    // test box that is bigger than the box it will check
    Box biggerBox(
        Coordinate(
            -50.0  * Length::METER,
            -50.0  * Length::METER, 
            -50.0  * Length::METER), 
        Coordinate(
            200.0 * Length::METER,
            200.0 * Length::METER,
            200.0 * Length::METER));

    ASSERT_EQ(true, box.intersects(biggerBox));
    
    Box negativeBox(
        Coordinate(
            -50.0 * Length::METER,
            -50.0 * Length::METER,
            -50.0 * Length::METER), 
        Coordinate(
            -100.0 * Length::METER,
            -100.0 * Length::METER,
            -100.0 * Length::METER));
    
    // test negative box that is inside
    Box negativeBoxInside(
        Coordinate(
            -60.0 * Length::METER,
            -60.0 * Length::METER,
            -60.0 * Length::METER), 
        Coordinate(
            -70.0 * Length::METER,
            -70.0 * Length::METER,
            -70.0 * Length::METER));

    ASSERT_EQ(negativeBox.intersects(negativeBoxInside), true);

    // test negative box that intersects
    Box negativeBoxIntersects(
        Coordinate(
            -75.0 * Length::METER,
            -75.0 * Length::METER,
            -75.0 * Length::METER), 
        Coordinate(
            -125.0 * Length::METER,
            -125.0 * Length::METER,
            -125.0 * Length::METER));
    ASSERT_EQ(negativeBox.intersects(negativeBoxIntersects), true);

    // test negative box that doesn't intersect
    Box negativeBoxOutside(
        Coordinate(
            -175.0 * Length::METER,
            -175.0 * Length::METER,
            -175.0 * Length::METER
        ), 
        Coordinate(
            -125.0 * Length::METER,
            -125.0 * Length::METER,
            -125.0 * Length::METER
        )
    );
    ASSERT_EQ(negativeBox.intersects(negativeBoxOutside), false);
}


TEST (Box, get_bottom_left) {
    // test if it returns the right bottom left coordinate
    Coordinate bl = Coordinate::origin;
    Coordinate tr = Coordinate::origin + 
        Translation(
            50.0 * Length::METER, 
            50.0 * Length::METER, 
            50.0 * Length::METER
        );

    Coordinate bl2 = Coordinate(
        25.0 * Length::METER,
        26.0 * Length::METER,
        27.0 * Length::METER
    );

    Box box (bl, tr);
    ASSERT_DOUBLE_EQ(
        box.get_bottom_left().get_x() / Length::METER, 
        0.0
    );
    ASSERT_DOUBLE_EQ(
        box.get_bottom_left().get_y() / Length::METER, 
        0.0
    );
    ASSERT_DOUBLE_EQ(
        box.get_bottom_left().get_z() / Length::METER, 
        0.0
    );

    Box box2(bl2, tr);
    ASSERT_DOUBLE_EQ(
        box2.get_bottom_left().get_x() / Length::METER, 
        25.0
    );
    ASSERT_DOUBLE_EQ(
        box2.get_bottom_left().get_y() / Length::METER, 
        26.0
    );
    ASSERT_DOUBLE_EQ(
        box2.get_bottom_left().get_z() / Length::METER, 
        27.0
    );

    Box negative(
        Coordinate(
            -10.0 * Length::METER,
            -10.0 * Length::METER,
            -10.0 * Length::METER
        ), 
        Coordinate(
            -50.0 * Length::METER,
            -50.0 * Length::METER,
            -50.0 * Length::METER
        )
    );

    ASSERT_DOUBLE_EQ(
        negative.get_bottom_left().get_x() / Length::METER, 
        -50.0
    );
    ASSERT_DOUBLE_EQ(
        negative.get_bottom_left().get_y() / Length::METER, 
        -50.0
    );
    ASSERT_DOUBLE_EQ(
        negative.get_bottom_left().get_z() / Length::METER, 
        -50.0
    );
}

TEST (Box, get_top_right) {
    // test if it returns the right top right coordinate
    Coordinate bl = Coordinate::origin + Translation();
    Coordinate tr = Coordinate(
        50.0 * Length::METER, 
        50.0 * Length::METER, 
        50.0 * Length::METER
    );

    Coordinate tr2 = Coordinate(
        25.0 * Length::METER,
        25.0 * Length::METER,
        25.0 * Length::METER
    );

    Box box (bl, tr);
    ASSERT_DOUBLE_EQ(
        box.get_top_right().get_x() / Length::METER,
        50.0
    );

    ASSERT_DOUBLE_EQ(
        box.get_top_right().get_y() / Length::METER, 
        50.0
    );

    ASSERT_DOUBLE_EQ(
        box.get_top_right().get_z() / Length::METER, 
        50.0
    );

    Box box2(bl, tr2);

    ASSERT_DOUBLE_EQ(
        box2.get_top_right().get_x() / Length::METER, 
        25.0
    );

    ASSERT_DOUBLE_EQ(
        box2.get_top_right().get_y() / Length::METER, 
        25.0
    );

    ASSERT_DOUBLE_EQ(
        box2.get_top_right().get_z() / Length::METER, 
        25.0
    );

    Box negative(
        Coordinate(
            -10.0 * Length::METER,
            -10.0 * Length::METER,
            -10.0 * Length::METER
        ), 
        Coordinate(
            -50.0 * Length::METER,
            -50.0* Length::METER,
            -50.0 * Length::METER
        )
    );

    ASSERT_DOUBLE_EQ(
        negative.get_top_right().get_x() / Length::METER, 
        -10.0
    );

    ASSERT_DOUBLE_EQ(
        negative.get_top_right().get_y() / Length::METER, 
        -10.0
    );

    ASSERT_DOUBLE_EQ(
        negative.get_top_right().get_z() / Length::METER, 
        -10.0
    );
}


TEST (Box, get_union_box) {
    // test if method returns right result

    Box box (
        Coordinate::origin + Translation(), 
        Coordinate(
            100.0 * Length::METER,
            100.0 * Length::METER,
            100.0 * Length::METER
        )
    );

    Box biggerBox(
        Coordinate(
            -25.0 * Length::METER,
            -35.0 * Length::METER,
            -45.0 * Length::METER
        ), 
        Coordinate(
            120.0 * Length::METER,
            120.0 * Length::METER,
            120.0 * Length::METER
        )
    );
    
    Box unionBox(
        Coordinate::origin + Translation(), 
        Coordinate::origin + Translation()
    );
    
    unionBox = box.get_union_box(biggerBox);

    ASSERT_DOUBLE_EQ(
        unionBox.get_bottom_left().get_x() / Length::METER,
        -25.0
    );

    ASSERT_DOUBLE_EQ(
        unionBox.get_bottom_left().get_y() / Length::METER, 
        -35.0
    );
    ASSERT_DOUBLE_EQ(
        unionBox.get_bottom_left().get_z() / Length::METER, 
        -45.0
    );

    ASSERT_DOUBLE_EQ(
        unionBox.get_top_right().get_x() / Length::METER, 
        120.0
    );
    ASSERT_DOUBLE_EQ(
        unionBox.get_top_right().get_y() / Length::METER, 
        120.0
    );

    ASSERT_DOUBLE_EQ(
        unionBox.get_top_right().get_z() / Length::METER, 
        120.0
    );

    // test if method returns the right result when using negative boxes

    Box negativeBox(
        Coordinate(
            -75.0 * Length::METER,
            -75.0 * Length::METER,
            -75.0 * Length::METER
        ), 
        Coordinate(
            -25.0 * Length::METER,
            -25.0 * Length::METER,
            -25.0 * Length::METER
        )
    );
    Box negativeBox2(
        Coordinate(
            -125.0 * Length::METER,
            -125.0 * Length::METER,
            -125.0 * Length::METER
        ), 
        Coordinate(
            -75.0 * Length::METER,
            -75.0 * Length::METER,
            -75.0 * Length::METER
        )
    );

    unionBox = negativeBox.get_union_box(negativeBox2);

    ASSERT_DOUBLE_EQ(
        unionBox.get_bottom_left().get_x() / Length::METER, 
        -125.0
    );

    ASSERT_DOUBLE_EQ(
        unionBox.get_bottom_left().get_y() / Length::METER, 
        -125.0
    );

    ASSERT_DOUBLE_EQ(
        unionBox.get_bottom_left().get_z() / Length::METER, 
        -125.0
    );

    ASSERT_DOUBLE_EQ(
        unionBox.get_top_right().get_x() / Length::METER, 
        -25.0
    );

    ASSERT_DOUBLE_EQ(
        unionBox.get_top_right().get_y() / Length::METER, 
        -25.0
    );

    ASSERT_DOUBLE_EQ(
        unionBox.get_top_right().get_z() / Length::METER, 
        -25.0
    );
}

TEST (Box, get_intersection_box) {
    // test if 2 boxes that are intersecting returns the right box
    Box box (
        Coordinate::origin + Translation(),
        Coordinate(
            100.0 * Length::METER,
            100.0 * Length::METER,
            100.0 * Length::METER
        )
    );

    Box collidingBox (
        Coordinate(
            75.0 * Length::METER,
            75.0 * Length::METER,
            75.0 * Length::METER
        ), 
        Coordinate(
            125.0 * Length::METER,
            125.0 * Length::METER,
            125.0 * Length::METER
        )
    );

    Box collidedBox(
        Coordinate::origin + Translation(), 
        Coordinate::origin + Translation()
    );

    collidedBox = box.get_intersection_box(collidingBox);

    ASSERT_DOUBLE_EQ(
        collidedBox.get_bottom_left().get_x() / Length::METER, 
        75
    );

    ASSERT_DOUBLE_EQ(
        collidedBox.get_bottom_left().get_y() / Length::METER, 
        75.0
    );

    ASSERT_DOUBLE_EQ(
        collidedBox.get_bottom_left().get_z() / Length::METER, 
        75.0
    );

    ASSERT_DOUBLE_EQ(
        collidedBox.get_top_right().get_x() / Length::METER, 
        100.0
    );
    ASSERT_DOUBLE_EQ(
        collidedBox.get_top_right().get_y() / Length::METER, 
        100.0
    );
    ASSERT_DOUBLE_EQ(
        collidedBox.get_top_right().get_z() / Length::METER, 
        100.0
    );

    // test 2 boxes that aren't intersecting
    Box notCollidingBox (
        Coordinate(
            125.0  * Length::METER,
            125.0  * Length::METER,
            125.0  * Length::METER
        ), 
        Coordinate(
            150.0  * Length::METER,
            150.0  * Length::METER,
            150.0  * Length::METER
        )
    );

    Box notCollidedBox(
        Coordinate::origin + Translation(), 
        Coordinate::origin + Translation()
    );

    ASSERT_DOUBLE_EQ(
        notCollidedBox.get_bottom_left().get_x() / Length::METER, 
        0.0
    );
    ASSERT_DOUBLE_EQ(
        notCollidedBox.get_bottom_left().get_y() / Length::METER, 
        0.0
    );
    ASSERT_DOUBLE_EQ(
        notCollidedBox.get_bottom_left().get_z() / Length::METER, 
        0.0
    );

    ASSERT_DOUBLE_EQ(
        notCollidedBox.get_top_right().get_x() / Length::METER, 
        0.0
    );
    ASSERT_DOUBLE_EQ(
        notCollidedBox.get_top_right().get_y() / Length::METER, 
        0.0
    );
    ASSERT_DOUBLE_EQ(
        notCollidedBox.get_top_right().get_z() / Length::METER, 
        0.0
    );

    // test 2 negative boxes that are intersecting
    Box negativeBox(
        Coordinate(
            -75.0  * Length::METER,
            -75.0  * Length::METER,
            -75.0  * Length::METER
        ), 
        Coordinate(
            -25.0  * Length::METER,
            -25.0  * Length::METER,
            -25.0  * Length::METER
        )
    );

    Box negativeBoxIntersecting(
        Coordinate(
            -125.0  * Length::METER,
            -125.0  * Length::METER,
            -125.0  * Length::METER
        ), 
        Coordinate(
            -50.0  * Length::METER,
            -50.0  * Length::METER,
            -50.0  * Length::METER
        )
    );

    collidedBox = negativeBox.get_intersection_box(negativeBoxIntersecting);

    ASSERT_DOUBLE_EQ(
        -75.0,
        collidedBox.get_bottom_left().get_x() / Length::METER 
    );

    ASSERT_DOUBLE_EQ(
        -75.0,
        collidedBox.get_bottom_left().get_y() / Length::METER 
    );

    ASSERT_DOUBLE_EQ(
        -75.0,
        collidedBox.get_bottom_left().get_z() / Length::METER 
    );


    ASSERT_DOUBLE_EQ(
        -50.0,
        collidedBox.get_top_right().get_x() / Length::METER 
    );
    ASSERT_DOUBLE_EQ(
        -50.0,
        collidedBox.get_top_right().get_y() / Length::METER 
    );
    ASSERT_DOUBLE_EQ(
        -50.0,
        collidedBox.get_top_right().get_z() / Length::METER 
        
    );

    // test 2 negative boxes that aren't intersecting
    Box negativeBoxNotIntersecting(
        Coordinate(
            -80.0  * Length::METER,
            -80.0  * Length::METER,
            -80.0  * Length::METER
        ), 
        Coordinate(
            -125.0  * Length::METER,
            -125.0  * Length::METER,
            -125.0  * Length::METER
        )
    );

    notCollidedBox = negativeBox.get_intersection_box(
        negativeBoxNotIntersecting
    );

    ASSERT_DOUBLE_EQ(
        0.0,
        notCollidedBox.get_bottom_left().get_x() / Length::METER 
        
    );
    ASSERT_DOUBLE_EQ(
        0.0,
        notCollidedBox.get_bottom_left().get_y() / Length::METER
        
    );
    ASSERT_DOUBLE_EQ(
        0.0,
        notCollidedBox.get_bottom_left().get_z() / Length::METER
    );

    ASSERT_DOUBLE_EQ(
        0.0,
        notCollidedBox.get_top_right().get_x() / Length::METER
    );
    ASSERT_DOUBLE_EQ(
        0.0,
        notCollidedBox.get_top_right().get_y() / Length::METER 
    );

    ASSERT_DOUBLE_EQ( 
        0.0,
        notCollidedBox.get_top_right().get_z() / Length::METER
    );
}
