/**
 @file manifold.h
 */

#ifndef MANIFOLD_H
#define MANIFOLD_H

#include "Vector2D.h"
#include "ball.h"
#include "rect.h"
#include "obb.h"

/*! \class Manifold
 \brief A Manifold class that generates a collision manifold
 */
class Manifold
{
protected:
    Body* bodyA; /*!< Pointer to a physics body*/
    Body* bodyB; /*!< Pointer to a physics body*/
private:
    float fPenetration; /*!< Stores the penetration depth*/
    Vector2D normal; /*!< Stores the collision normal */
    Vector2D contact; /*!< Point of collision contact */
public:
    Manifold(); //!< Default constructor
    Manifold(Body* first /*!< First rigid body*/, Body* second/*!< Second rigid body*/); //!< Constructor that takes in two bodies to generate the collision manifold
    bool CircleVsCircle();  //!< Bool to determine whether a circle has collided with another circle
    bool CircleVsRect(); //!< Bool to determine whether a circle has collided with a aabb
    bool CircleVsOBB(); //!< Bool to determine whether a circle has collided with an obb
    Vector2D getNormal() const {return normal;/*!< normal to return*/}; //!< Returns collision normal
    float getPenetration() const {return fPenetration;}; //!< Returns penetration depth
    void applyRotationalImpulse(); //!< Applies rotational impulse
    void correctPosition();	//!< Applies position correction 
    Vector2D Clamp(const Vector2D& kRectExtents/*! Rectangle extents*/, const Vector2D& kCirclePos/*! Circle position*/); //!< Determining closest point to closest edge of AABB
}; 
#endif
