/**
 @file obb.cpp
 */

#include "obb.h"
#include <SFML/Graphics.hpp>
#include "config.h"

OBB::OBB()
{
    body = Body();
    obbShape = ObbPhys();
    body.physicsShape = (PhysicsShape*)&obbShape;
    body.setAcceleration(0);
    body.setVelocity(0);
    body.setMass(0);
    body.setInertia(0);
	body.setRestitution(0.5);
    colour = sf::Color::Black;
}

OBB::OBB(const Vector2D kOrigin/*!< new origin*/, const Vector2D kHalfExtents/*!< new half extents*/, const float kfAngleIn/*!< new angle*/, const sf::Color kColourIn/*!< new colour */)//!< Constructor which takes origin, half extents, angle and colour
{
    body = Body();
	body.setPosition(kOrigin);
    body.setAcceleration(0);
    body.setVelocity(0);
    body.setMass(0);
    body.setInertia(0);
	body.setRestitution(0.5);
	body.setAngleRad(kfAngleIn);
	obbShape = ObbPhys(kOrigin, kHalfExtents);
    body.physicsShape = (PhysicsShape*)&obbShape;
	colour = kColourIn;
}

void OBB::draw(sf::RenderTarget& target, sf::RenderStates states) const	//!< Draws the OBB
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

sf::Color OBB::getColour() const	//!< Returns the colour of the OBB
{
    return colour;
}

void OBB::setColour(const sf::Color& kCol/*!< new colour*/) //!< Set colour of the obb
{
	colour = kCol;
}
