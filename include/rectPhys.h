/**
 @file RectPhys.h
 */

#ifndef RECTPHYS_H
#define RECTPHYS_H

#include "PhysicsShape.h"
#include "Vector2D.h"

/*! \class RectPhys
 \brief A Rectangle physics shape class that stores geometric data
 */
class RectPhys : public PhysicsShape
{
private:
    Vector2D halfExtent; /*!< Stores the half extents*/
public:
    RectPhys();	//!< Default constructor
    RectPhys(const Vector2D& kOriginIn /*!< New origin*/, const Vector2D& kHalfExtentsIn/*!< New half extents*/);	//!< Main rectangle physics shape constructor
    float getWidth() const;	//!< Return the width of the shape
    float getHeight()const;	//!< Returns the height of the shape
    Vector2D getMin() const;	//!< Returns the min of the shape
    Vector2D getMax() const;//!< Returns the max of the shape
    void setHalfExtent(const Vector2D kHalfExtentIn/*!< New half extents*/);	//!< Sets the half extents
    Vector2D getHalfExtent() const;	//!< Returns the half extents
    
};
#endif
