/**
 @file obb.h
 */

#ifndef OBB_H
#define OBB_H

#include "Vector2D.h"
#include <SFML/Graphics.hpp>
#include "body.h"
#include "obbPhys.h"

/*! \class OBB
 \brief A obb class which creates a oriented bounding box and draws it
 */
class OBB : public sf::Drawable
{
protected:
    ObbPhys obbShape;	//!< Holds the geometric data for the shape
    sf::Color colour;	//!< Colour value
public:
    Body body;  //!< Physics body

    OBB();  //!< Default constructor
    OBB(const Vector2D kOrigin/*!< new origin*/, const Vector2D kHalfExtents/*!< new half extents*/, const float kfAngleIn/*!< new angle*/, const sf::Color kColourIn/*!< new colour */); //!< Constructor which takes origin, half extents, angle and colour
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< Draw the OBB
    sf::Color getColour() const; //!< Returns the colour of the OBB
    void setColour(const sf::Color& kCol /*!< new colour */); //!< Sets the colour of the OBB
	//void rotate();	//!< Rotates the obb
	Vector2D getContact();//!< Returns the contact point for rotatating
	Vector2D getRotationForce();	//!< Returns the rotation impulse to apply

};
#endif
