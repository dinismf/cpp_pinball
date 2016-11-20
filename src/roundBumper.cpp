/**
 @file roundBumper.cpp
 */

//  Created by Dinis Marques Firmino on 24/02/2015.
//  Copyright (c) 2015 DYN. All rights reserved.
//

#include "roundBumper.h"

RoundBumper::RoundBumper()
{
    body = Body();
    body.setPosition(0);
    body.setRestitution(0.9);
    body.setMass(0);
    circleShape = CirclePhys(0);
    body.physicsShape = (PhysicsShape*)&circleShape;
    setColour(sf::Color::Black);
    
    setType(roundBumper);
    setPoints(0);
}

RoundBumper::RoundBumper(const Vector2D kPosIn /*!< New position */, const float kfRadiusIn/*!< New radius */, const int kiPointsIn/*!< New points value */, const sf::Color kColourIn/*!< New colour */) //!< Main constructor
{
    body = Body();
	body.setPosition(kPosIn);
    body.setRestitution(0.9);
    body.setMass(0);
	circleShape = CirclePhys(kfRadiusIn);
    body.physicsShape = (PhysicsShape*)&circleShape;
	setColour(kColourIn);
    
    setType(roundBumper);
	setPoints(kiPointsIn);
    
}