/**
 @file body.h
 */

#ifndef BODY_H
#define BODY_H

#include <SFML/Graphics.hpp>
#include "Vector2D.h"
#include "PhysicsShape.h"

/*! \class Body
 \brief A Body class which holds physics properties of a shape
 */
class Body {
protected:
    float fMass; /*!< Holds mass of body */
    float fInverseMass;/*!< Holds the inverse mass */
    float fRestitution;/*!< Holds the restitution */
    float fInertia;/*!< Holds the inertia*/
    float fInverseInertia;/*!< Holds the inverse inertia*/
    float fAngularVelocity;/*!< Holds the angular velocity*/
    float fAngle;   /*!< Holds the angle in radians*/
public:
    PhysicsShape* physicsShape; /*!< Pointer to type of physics shape */
    Vector2D position;  /*!< Position of body */
    Vector2D velocity;  /*!< Velocity of body */
    Vector2D acceleration;  /*!< Acceleration of body */
    Body(); //!< Default constructor
    Body(const Vector2D& kPos/*!< new position */, const Vector2D& kVel/*!< new velocity*/, const Vector2D& kAcc/*!< new acceleration */, const float kfRest/*!< new restitution */); //!< Main body constructor

    void update(float fTimestep/*! Timestep value*/); //!< Updates position of body using improved euler
    void setRestitution(const float restIn/*!< New restitution */);  //!< Sets restitution
    void setMass(const float fmassIn/*!< New mass */);    //!< Sets mass and inverse mass
    void setPosition(const Vector2D& kPos /*!< new position */); //!< Sets the position of the body
    void setVelocity(const Vector2D& KVel /*!< new velocity */); //!< Sets the velocity of the body
    void setAcceleration(const Vector2D& kAcc /*!< new acceleration */); //!< Sets the acceleration of the body
    float getRestitution() const;//!< Returns restitution
    float getMass() const;//!< Returns mass
    float getInverseMass() const;//!< Returns inverse mass
    Vector2D getAcceleration() const; //!< Returns the acceleration of the body
    Vector2D getPosition() const; //!< Returns the position of the body
    Vector2D getVelocity() const; //!< Returns the velocity of the body
    void setInertia(const float inertiaIn/*!< new inertia*/); //!< Sets the inertia and inverse inertia
    void setAngularVelocity(const float kfAngularVelIn/*!< new angular velocity*/);    //!< Sets the angular velocity
    float getInverseInertia()const;  //!< Returns the inverse inertia
    float getAngularVelocity() const;   //!< Returns the angular velocity
    float getAngleDeg() const;	//!< Returns the angle in degrees
    float getAngleRad() const;	//!< Returns the angle in radians
    void setAngleRad(const float kfAngleIn);	//!< Sets the angle in radians
    void applyImpulse(const Vector2D kImpulseIn /*!< Amount of impulse to apply*/, const Vector2D kContactIn/*!< Contact to apply the impulse*/); //!< applies rotational impulse to body
    void applyAngularImpulse(const float kfAngularImpulseIn/*!< angular impulse to apply*/); //!< Applies rotational impulse to the body

};

#endif