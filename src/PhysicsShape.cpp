/**
 @file PhysicsShape.cpp
 */

//  Created by Dinis Marques Firmino on 02/02/2015.
//  Copyright (c) 2015 DYN. All rights reserved.
//

#include "PhysicsShape.h"

PhysicsShape::PhysicsShape()
{
}

void PhysicsShape::setType(type shapeTypeIn)
{
    shapeType = shapeTypeIn;
}

type PhysicsShape::getType()
{
    return shapeType;
}