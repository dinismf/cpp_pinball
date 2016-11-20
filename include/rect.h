/**
 @file rect.h
 */

#ifndef RECT_H
#define RECT_H

#include "Vector2D.h"
#include <SFML/Graphics.hpp>
#include "body.h"
#include "rectPhys.h"

/*! \class Rect
 \brief A Rect class which creates a rectangle and draws it
 */
class Rect : public sf::Drawable
{
protected:
    RectPhys rectShape;	/*!< Stores the geometric data for the rectangle*/
    sf::Color colour;	/*!< Stores the shape colour*/
public:
    Body body;	/*!< Holds the physics body*/
    Rect();	//!< Default constructor
    Rect(const Vector2D kOrigin/*!< new origin*/, const Vector2D kHalfExtents/*!< new half extents*/, const sf::Color kColourIn/*!< new colour*/); //!< Constructor which takes position, half extents and colour
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< Draw the rectangle
    sf::Color getColour() const; //!< Returns the colour of the rectangle
    void setColour(const sf::Color& kCol /*!< new colour */); //!< Sets the colour of the rectangle
};

#endif
