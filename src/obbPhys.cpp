/**
 @file obbPhys.cpp
 */

//  Created by Dinis Marques Firmino on 11/02/2015.
//  Copyright (c) 2015 DYN. All rights reserved.
//

#include "obbPhys.h"
#include <cmath>

ObbPhys::ObbPhys()
{
    shapeType = obb;
}

ObbPhys::ObbPhys(const Vector2D& kOriginIn, const Vector2D& kHalfExtentsIn)
{
    shapeType = obb;
	halfExtent = kHalfExtentsIn;
}

void ObbPhys::setHalfExtent(const Vector2D kHalfExtentsIn)
{
	halfExtent = kHalfExtentsIn;
}

Vector2D ObbPhys::getHalfExtent() const
{
    return halfExtent;
}

float ObbPhys::getWidth() const
{
    return getMax().x() - getMin().x();
}

float ObbPhys::getHeight() const
{
    return getMax().y() - getMin().y();
}

Vector2D ObbPhys::getMin() const
{
    return -halfExtent;
}

Vector2D ObbPhys::getMax() const
{
    return halfExtent;
}

