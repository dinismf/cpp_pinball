/**
 @file paddle.cpp
 */

//  Created by Dinis Marques Firmino on 22/02/2015.
//  Copyright (c) 2015 DYN. All rights reserved.
//

#include "paddle.h"
#include "config.h"

Paddle::Paddle()
{
}

Paddle::Paddle(const Vector2D& kPosIn/*!< new paddle position*/, const Vector2D& kHalfExtents/*!< new paddle half extents*/, float kAngleIn/*!< new paddle angle*/, bool bIsLeftIn/*!< paddle direction*/, const sf::Color kColourIn/*!< new paddle colour*/)
{
	body = Body();
	body.setPosition(kPosIn);
    body.setAcceleration(0);
    body.setVelocity(0);
    body.setMass(0);
    body.setInertia(0);
    body.setRestitution(0.2);
    bIsLeft = bIsLeftIn;

    if (bIsLeft == true){
		body.setAngleRad(kAngleIn);
    } else{
		body.setAngleRad(-kAngleIn);
    }

	obbShape = ObbPhys(kPosIn, kHalfExtents);
    body.physicsShape = (PhysicsShape*)&obbShape;
    
	colour = kColourIn;
}


void Paddle::flip(std::string direction)
{
	if (direction == "up") {
		if (bIsLeft == true){
			body.applyAngularImpulse(PADDLE_SPEED);
		} else{
			body.applyAngularImpulse(-PADDLE_SPEED);    
		}
	} else if (direction == "down"){
		if (bIsLeft == true) {
			body.applyAngularImpulse(-PADDLE_SPEED);
		} else{
			body.applyAngularImpulse(PADDLE_SPEED);
		}
	}
}

void Paddle::clampPaddle()
{
    
    if (bIsLeft == true) {
        
        if (body.getAngleRad() > PADDLE_MAX_ANGLE) {

            body.setAngleRad(PADDLE_MAX_ANGLE);
            body.setAngularVelocity(0);
        }
        
        if (body.getAngleRad() < PADDLE_MIN_ANGLE){

            body.setAngleRad(PADDLE_MIN_ANGLE);
            body.setAngularVelocity(0);
        }
        
    } else {
        if (body.getAngleRad() < -PADDLE_MAX_ANGLE) {

            body.setAngleRad(-PADDLE_MAX_ANGLE);
            body.setAngularVelocity(0);
        }
        
        if (body.getAngleRad() > -PADDLE_MIN_ANGLE){

            body.setAngleRad(-PADDLE_MIN_ANGLE);
            body.setAngularVelocity(0);
        }
    }

}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const	//!< Draws the OBB
{
    const Vector2D size = obbShape.getHalfExtent()*(PIXELTOMETER*2);
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(size.x(), size.y()));
    rectangle.setOrigin(size.x()/2, size.y()/2);
    rectangle.setPosition(body.getPosition().x()*PIXELTOMETER, body.getPosition().y()*PIXELTOMETER);
    rectangle.setRotation(body.getAngleDeg());
	rectangle.setFillColor(colour);
    target.draw(rectangle);
} 






