/**
 @file obbPhys.h
 */

#ifndef OBBPHYS_H
#define OBBPHYS_H

#include "PhysicsShape.h"
#include "Vector2D.h"

/*! \class ObbPhys
 \brief A OBB physics shape class that stores geometric data for an oriented bounding box
 */
class ObbPhys : public PhysicsShape
{
private:
    Vector2D halfExtent;	/*!< Holds half extents of the obb */
public:
    ObbPhys();	//!< Default constructor 
    ObbPhys(const Vector2D& kOriginIn, const Vector2D& kHalfExtentsIn);	//!< Constructor that takes in an origin and the half extents
    float getWidth() const; //!< Returns the width of the obb
    float getHeight()const;	//!< Returns the height of the obb
    Vector2D getMin() const;//!< Returns the min of the obb
    Vector2D getMax() const;//!< Returns the max of the obb
    void setHalfExtent(const Vector2D kHalfExtentIn);//!< Sets the half extents
    Vector2D getHalfExtent() const;	//!< Returns the half extents
    
};

#endif
