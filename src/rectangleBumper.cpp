/**
 @file rectangleBumper.cpp
 */

//  Created by Dinis Marques Firmino on 24/02/2015.
//  Copyright (c) 2015 DYN. All rights reserved.
//

#include "rectangleBumper.h"

RectangleBumper::RectangleBumper()
{
    body = Body();
    body.setPosition(0);
    body.setRestitution(0);
    body.setMass(0);
    obbShape = ObbPhys();
    body.physicsShape = (PhysicsShape*)&obbShape;
    setColour(sf::Color::Black);
    
    setType(rectangleBumper);
    setPoints(0);
}

RectangleBumper::RectangleBumper(const Vector2D kPosIn /*!< New position*/, const Vector2D kHalfExtentsIn/*!< New half extents*/, const float kfAngleIn/*!< new angle */, const int kiPointsIn /*!< New points*/, const sf::Color kColourIn/*!< New colour*/) //!< Rectangle bumper main constructor
{
    body = Body();
	body.setPosition(kPosIn);
    body.setRestitution(0.5);
    body.setMass(0);
	body.setAngleRad(kfAngleIn);
	obbShape = ObbPhys(kPosIn, kHalfExtentsIn);
    body.physicsShape = (PhysicsShape*)&obbShape;
	setColour(kColourIn);
    
    setType(roundBumper);
	setPoints(kiPointsIn);
    
}