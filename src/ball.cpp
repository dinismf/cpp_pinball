/**
 @file ball.cpp
 */

//  Created by Dinis Marques Firmino on 27/01/2015.
//  Copyright (c) 2015 DYN. All rights reserved.
//

#include "ball.h"
#include <SFML/Graphics.hpp>
#include "config.h"

Ball::Ball()
{
    body = Body();
    body.setPosition(0);
    body.setAcceleration(0);
    body.setVelocity(0);
    body.setRestitution(1);
    body.setInertia(0);
	body.setMass(1);
    circleShape = CirclePhys(0);
    body.physicsShape = (PhysicsShape*)&circleShape;
    colour = sf::Color::Black;
}

Ball::Ball(const Vector2D& kPos /*!< initial position */, const Vector2D& kVel /*!< initial velocity */, const Vector2D& kAccel /*!< initial acceleration */,const float kfRadiusIn/*!< initial radius */)
{
    body = Body();
    body.setPosition(kPos);
	body.setAcceleration(kAccel);
    body.setVelocity(kVel);
    body.setRestitution(1);
    body.setInertia(0);
	body.setMass(1);
	circleShape = CirclePhys(kfRadiusIn);
    body.physicsShape = (PhysicsShape*)&circleShape;
    colour = sf::Color::Black;
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const//!< Draw the ball
{
    sf::CircleShape ball = sf::CircleShape(circleShape.getRadius()*PIXELTOMETER, 15);
    ball.setFillColor(getColour());
    ball.setOrigin(circleShape.getRadius()*PIXELTOMETER, circleShape.getRadius()*PIXELTOMETER);
    ball.setPosition(body.getPosition().x()*PIXELTOMETER, body.getPosition().y()*PIXELTOMETER);
    target.draw(ball);
}

sf::Color Ball::getColour() const//!< Returns the colour of the ball
{
    return colour;
}

void Ball::setColour(const sf::Color& col) //!< Sets the colour of the ball
{
    colour = col;
}
