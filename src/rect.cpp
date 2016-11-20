/**
 @file rect.cpp
 */

#include <SFML/Graphics.hpp>
#include "rect.h"
#include "Vector2D.h"
#include "config.h"

Rect::Rect()
{
    body = Body();
    rectShape = RectPhys();
    body.physicsShape = (PhysicsShape*)&rectShape;
    body.setMass(0);
    body.setRestitution(0);
    colour = sf::Color::Black;
}

Rect::Rect(const Vector2D kOrigin/*!< new origin*/, const Vector2D kHalfExtents/*!< new half extents*/, const sf::Color kColourIn/*!< new colour*/) //!< Constructor which takes position, half extents and colour
{
    body = Body();
	body.setPosition(kOrigin);
    body.setAcceleration(0);
    body.setVelocity(0);
    body.setMass(0);
    body.setRestitution(0.5);
	rectShape = RectPhys(kOrigin, kHalfExtents);
    body.physicsShape = (PhysicsShape*)&rectShape;
	colour = kColourIn;
}

void Rect::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    const Vector2D size = rectShape.getHalfExtent()*40;
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(size.x(), size.y()));
    rectangle.setOrigin(size.x()/2, size.y()/2);
    rectangle.setPosition(body.getPosition().x()*PIXELTOMETER, body.getPosition().y()*PIXELTOMETER);
    rectangle.setFillColor(colour);
    target.draw(rectangle);
}

sf::Color Rect::getColour() const
{
    return colour;
}

void Rect::setColour(const sf::Color& kCol)
{
	colour = kCol;
}

