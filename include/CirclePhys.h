/**
 @file CirclePhys.h
 */

#ifndef CIRCLEPHYS_H
#define CIRCLEPHYS_H

#include "PhysicsShape.h"

/*! \class CirclePhys
 \brief A Circle physics shape class that stores geometric data for a circle
 */
class CirclePhys : public PhysicsShape {
private:
    float fRadius;	/*!< Holds the radius */
public:
    CirclePhys() {shapeType = circle; /*!< Set the shape type*/};	//!< Default constructor
	CirclePhys(const float kfRadiusIn) {shapeType = circle;/*!< Set the shape type*/ fRadius = kfRadiusIn; /*!< Set the radius*/};	//!< Constructor that takes in a radius
	void setRadius(const float kfRadiusIn /*!< new radius*/) {fRadius = kfRadiusIn;/*!< Set the radius*/};	//!< Sets the radius
    float getRadius() const {return fRadius;}; //!< Returns the radius 
};

#endif
