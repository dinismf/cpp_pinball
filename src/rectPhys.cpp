/**
 @file RectPhys.cpp
 */

//  Created by Dinis Marques Firmino on 04/02/2015.
//  Copyright (c) 2015 DYN. All rights reserved.
//

#include "rectPhys.h"

RectPhys::RectPhys()
{
    shapeType = aabb;
}

RectPhys::RectPhys(const Vector2D& kOriginIn /*!< New origin*/, const Vector2D& kHalfExtentsIn/*!< New half extents*/)	// Main rectangle physics shape constructor
{
	halfExtent = kHalfExtentsIn;
    shapeType = aabb;
}

void RectPhys::setHalfExtent(const Vector2D kHalfExtents)
{
    halfExtent = kHalfExtents;
}

Vector2D RectPhys::getHalfExtent() const
{
    return halfExtent;
}

float RectPhys::getWidth() const
{
    return getMax().x() - getMin().x();
}

float RectPhys::getHeight() const
{
    return getMax().y() - getMin().y();
}

Vector2D RectPhys::getMin() const
{
    return -halfExtent;
}

Vector2D RectPhys::getMax() const
{
    return halfExtent;
}
