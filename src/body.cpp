/**
 @file body.h
 */

#define _USE_MATH_DEFINES
#include <cmath>
#include "body.h"
#include "config.h"

Body::Body()//!< Default constructor
{
    setPosition(0);
    setVelocity(0);
    setAcceleration(0);
    setMass(1);
    setRestitution(0);
    setAngularVelocity(0);
    setAngleRad(0);
    setInertia(0);
}

Body::Body(const Vector2D& kPos/*!< new position */, const Vector2D& kVel/*!< new velocity*/, const Vector2D& kAcc/*!< new acceleration */, const float kfRest/*!< new restitution */) //!< Main body constructor
{
    position = kPos;
    velocity = kVel;
    acceleration = kAcc;
    fRestitution = kfRest;
    setMass(1);
    setAngularVelocity(0);
    setAngleRad(0);
    setInertia(0);
}

void Body::update(float fTimestep)//!< Updates position of body using improved euler
{
    /*!< Intergrating using improved euler */
	Vector2D newPrimeVelocity(velocity + (acceleration * fTimestep));
    position += ((getVelocity() + newPrimeVelocity) / 2) * fTimestep;
    velocity = newPrimeVelocity;

	/*!< Intergrating angular velocity */
	float newAngle = fAngle + (fAngularVelocity * fTimestep);
    setAngleRad(newAngle);

	/*!< Cap the velocity at a specified limit*/
	if(velocity.x() > MAX_VELOCITY_X) {
		velocity.setX(MAX_VELOCITY_X);

	} else if(velocity.y() > MAX_VELOCITY_Y) {
		velocity.setY(MAX_VELOCITY_Y);
	}
	
}

void Body::setRestitution(float fRestIn) //!< Sets the restitution
{
    fRestitution  = fRestIn;
}

void Body::setMass(const float kfMassIn) //!< Set the mass and inverse mass
{
	/* Checking to see if mass is 0 and preventing division by 0 */
    fMass = kfMassIn;
	if (kfMassIn == 0.0f) {
        fInverseMass = 0.0f;
	} else {
		fInverseMass = 1.0f /kfMassIn;
	}

	printf("InvMass: %f \n", fInverseMass);
}

float Body::getRestitution() const  //!< Gets the restitution
{
    return fRestitution;
}

float Body::getInverseMass() const  //!< Gets the inverse mass
{
    return fInverseMass;
}

float Body::getInverseInertia() const   //!< Gets the inverse inertia
{
    return fInverseInertia;
}

float Body::getAngularVelocity() const  //!< Gets the angular velocity
{
    return fAngularVelocity;
}

void Body::setInertia(const float kInertiaIn) //!< Sets the inertia and inverse inertia
{
    /* Checking to see if inertia is 0 and preventing division by 0 */
    fInertia = kInertiaIn;
    if (fInertia == 0.0f)
        fInverseInertia = 0.0f;
    else
		fInverseInertia = 1.0f / fInertia;
}

void Body::setAngularVelocity(const float kfAngularVelIn)
{
    fAngularVelocity = kfAngularVelIn;
}

void Body::applyAngularImpulse(const float kfAngularImpulseIn)
{
    fAngularVelocity += kfAngularImpulseIn;
}

float Body::getAngleRad() const
{
    return fAngle;
}

float Body::getAngleDeg() const
{
    return fAngle*(180/M_PI);
}

void Body::setAngleRad(const float kfAngleIn)
{
    const float fFullRotation = 2 * M_PI;
    float fNewAngle = kfAngleIn;
    while (std::abs(fNewAngle) > fFullRotation) {
        if (fNewAngle > 0)
            fNewAngle -= fFullRotation;
        else
            fNewAngle += fFullRotation;
    }
    fAngle = fNewAngle;
}

void Body::setAcceleration(const Vector2D& kAcc) //!< Sets the acceleration of the body
{
	acceleration = kAcc;
}

void Body::setPosition(const Vector2D& kPos) //!< Sets the position of the body
{
	position = kPos;
}

void Body::setVelocity(const Vector2D& kVel) //!< Sets the velocity of the body
{
	velocity = kVel;
}



Vector2D Body::getAcceleration() const//!< Returns the acceleration of the body
{
    return acceleration;
}

Vector2D Body::getPosition() const //!< Returns the position of the body
{
    return position;
}

Vector2D Body::getVelocity() const//!< Returns the velocity of the body
{
    return velocity;
}

void Body::applyImpulse(const Vector2D impulseIn, const Vector2D contactIn)
{
    velocity += impulseIn * getInverseMass();
    fAngularVelocity += contactIn.crossProduct(impulseIn) * getInverseInertia();
}
