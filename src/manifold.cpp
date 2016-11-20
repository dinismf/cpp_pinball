//
//  manifold.cpp
//  Pinball
//
//  Created by Dinis Marques Firmino on 30/01/2015.
//  Copyright (c) 2015 DYN. All rights reserved.
//

#include "manifold.h"
#include "rotationMat.h"
#include <cmath>

Manifold::Manifold()//!< Default constructor
{
    
}

Manifold::Manifold(Body* first/*!< First rigid body*/, Body* second/*!< Second rigid body*/)//!< Constructor that takes in two bodies to generate the collision manifold
{
    bodyA = first;
    bodyB = second;
}

bool Manifold::CircleVsCircle()
{
	/*!< Setting up pointers to two circles*/
    CirclePhys* circleA = (CirclePhys*)bodyA->physicsShape;
    CirclePhys* circleB = (CirclePhys*)bodyB->physicsShape;

    /*!< Calculating vector between the two bodies */
    Vector2D difference = bodyB->getPosition() - bodyA->getPosition();

	/*!< Sum of both radiuses */
    float fRadiusSum =  circleA->getRadius() + circleB->getRadius();
    
    float fMag = difference.dotProduct(difference);
    
	/*!< */
    if ((fRadiusSum*fRadiusSum) < fMag)
        return false;
    
    
    fMag = std::sqrtf(fMag);
    // If distance between circles is not 0
    if (fMag != 0)
    {
        fPenetration = fMag - fRadiusSum; // Penetration distance
        normal = difference/fMag; //
        contact = bodyB->getPosition() - (normal * circleB->getRadius());
    }
    else
    {
        fPenetration = circleA->getRadius();
        normal = Vector2D(1,0);
        contact = bodyA->getPosition();
    }
    return true;
}

bool Manifold::CircleVsRect()
{
    /*!< Setting up pointers to a rectangle and a circle */
    RectPhys* rect = (RectPhys*)bodyA->physicsShape;
    CirclePhys* circle = (CirclePhys*)bodyB->physicsShape;
    
    // Vector between A and B
    Vector2D difference = bodyB->getPosition() - bodyA->getPosition();
    
    /*!< Clamping closest point to nearest edge */
    Vector2D closest = Clamp(rect->getHalfExtent(), difference);
    
    bool bInside = false;
    
    // Clamp circle to the closest edge
    if (difference == closest){
		bInside = true;
        
        // Find closest axis
        if (std::abs(difference.x()) > std::abs(difference.y())){
            
            // Clamp to closest extent
            if (closest.x() > 0){
                closest.setX(rect->getHalfExtent().x());
            } else{
                closest.setX(-rect->getHalfExtent().x());
            }
        }   else{
            if (closest.y() > 0){
                closest.setY(rect->getHalfExtent().y());
            }else{
                closest.setY(-rect->getHalfExtent().y());
            }
        }

    }
    
	Vector2D n = difference - closest;
    float fDistance = n.dotProduct(n);
    float fRadius = circle->getRadius();
    
    // if circle isn't inside AABB
	if (fDistance > fRadius * fRadius && !bInside){
        return false;
    }
    
    fDistance = std::sqrtf(fDistance);
    n = n/fDistance;
    
    // if circle is inside AABB
	if (bInside){
        normal = -n;
        contact = bodyB->getPosition() - (normal * circle->getRadius());
		fPenetration = fDistance - fRadius;
    }else{
        normal = n;
        contact = bodyB->getPosition() - (normal * circle->getRadius());
		fPenetration = fDistance - fRadius;
    }
    return true;
}

bool Manifold::CircleVsOBB()
{
    ObbPhys* obb = (ObbPhys*)bodyA->physicsShape;
    CirclePhys* circle = (CirclePhys*)bodyB->physicsShape;
    
    // Vector between A and B
    Vector2D difference = bodyB->getPosition() - bodyA->getPosition();
    
    RotationMat matrix = RotationMat(bodyA->getAngleRad());
    
    Vector2D transform = matrix.inverseRotateVector(difference);

    // Closest point on A to B
    Vector2D closest = Clamp(obb->getHalfExtent(), transform);
    
    bool bInside = false;
    
    // Clamp circle to the closest edge
    if (transform == closest){
        bInside = true;
        if (std::abs(transform.x()) >= std::abs(transform.y())){
            if (closest.x() > 0){
                closest.setX(obb->getHalfExtent().x());
            } else{
                closest.setX(-obb->getHalfExtent().x());
            }
        }   else{
            if (closest.y() > 0){
                closest.setY(obb->getHalfExtent().y());
            }else{
                closest.setY(-obb->getHalfExtent().y());
            }
        }
    }
    
    Vector2D n = transform - closest;
    float fDistance = n.dotProduct(n);
    float fRadius = circle->getRadius();
    
    if (fDistance > fRadius * fRadius && !bInside){
        return false;
    }
    
    fDistance = std::sqrtf(fDistance);
    n = n/fDistance;
    
    // if circle is inside AABB
    if (bInside){
        normal = -n;
        contact = bodyB->getPosition() - matrix.rotateVector(normal * circle->getRadius());
        fPenetration = fDistance - fRadius;
    }else {
        normal = n;
        contact = bodyB->getPosition() - matrix.rotateVector(normal * circle->getRadius());
        fPenetration = fDistance - fRadius;
    }
    return true;
}

void Manifold::correctPosition() //!< Applies position correction 
{
    const float kfPercent = 0.2;
    const float kfSlop =  0.01;
	const float kfInvMassSum = bodyA->getInverseMass() + bodyB->getInverseMass();
	const float kFScalarNum = std::max(std::abs(fPenetration) - kfSlop, 0.0f) / kfInvMassSum;
	Vector2D correction = normal * kFScalarNum * kfPercent;
	bodyA->position -= correction * bodyA->getInverseMass();
	bodyB->position += correction * bodyB->getInverseMass();
}

void Manifold::applyRotationalImpulse()
{
	/*!< Calculating contact points*/
    const Vector2D kBodyAContact(contact - bodyA->getPosition());
    const Vector2D kBodyBContact(contact - bodyB->getPosition());
    
	/*!< Calculate the relative velocity */
    Vector2D rv = (bodyB->getVelocity() + kBodyBContact.vectorCrossScalar(-bodyB->getAngularVelocity())) - (bodyA->getVelocity() + kBodyAContact.vectorCrossScalar(-bodyA->getAngularVelocity()));
    
	/*!< Calculate relative velocity along the normal*/
    float fVelAlongNormal = rv.dotProduct(normal);
    
	/*!< Do not apply impulse if velocities are separating*/
	if (fVelAlongNormal > 0){
         return;
    }
    
    /*!< Calculate restitution */
    float fRestitution = std::min(bodyA->getRestitution(), bodyB->getRestitution());
    
    const float kfContactACrossNormal = kBodyAContact.crossProduct(normal);
    const float kfContactBCrossNormal = kBodyBContact.crossProduct(normal);
    
    /*!< Calculate impulse scalar */
	float fImpulseScalar = -(1 + fRestitution) * fVelAlongNormal;
    fImpulseScalar /= bodyA->getInverseMass() + bodyB->getInverseMass() + (kfContactACrossNormal * kfContactACrossNormal) * bodyA->getInverseInertia() + (kfContactBCrossNormal * kfContactBCrossNormal) * bodyB->getInverseInertia();
    
    /*!< Apply rotational impulse */
    Vector2D impulse = normal * fImpulseScalar;
	bodyA->applyImpulse(-impulse, kBodyAContact);
    bodyB->applyImpulse(impulse, kBodyBContact);
}

Vector2D Manifold::Clamp(const Vector2D& rectExtents, const Vector2D& circlePos) { //!< Determining closest point to closest edge of AABB
    
    Vector2D clamp = Vector2D();
    if (circlePos.x() >= 0) {
        clamp.setX(std::min(circlePos.x(), rectExtents.x()));
   } else {
        clamp.setX(std::max(circlePos.x(), -rectExtents.x()));
   }
    
    if (circlePos.y() >= 0) {
        clamp.setY(std::min(circlePos.y(), rectExtents.y()));
    } else {
        clamp.setY(std::max(circlePos.y(), -rectExtents.y()));
    }
    return clamp;
}





