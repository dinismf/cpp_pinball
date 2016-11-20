/**
 @file paddle.h
 */

#ifndef PADDLE_H
#define PADDLE_H

#include "obb.h"
#include "Vector2D.h"

/*! \class Paddle
 \brief A Paddle class that draws a paddle
 */
class Paddle : public sf::Drawable
{
protected:
    bool bIsLeft;	/*!< Bool to check whether paddle is left or right*/
    ObbPhys obbShape;	/*!< Holds the geometric data for the shape */
	sf::Color colour; /*!< Holds the colour of the paddle */
public:
    Body body;  //!< Physics body
    Paddle();	//!< Default constructor
    Paddle(const Vector2D& kPosIn/*!< new paddle position*/, const Vector2D& kHalfExtents/*!< new paddle half extents*/, float kAngleIn/*!< new paddle angle*/, bool bIsLeftIn/*!< paddle direction*/, const sf::Color kColourIn/*!< new paddle colour*/);	//!< Main paddle constructor
    void flip(std::string directionIn /*!< Direction in which to flip the paddle*/);	//!< Flips the paddle
    void clampPaddle();	//!< Clamps the paddle between two angles

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< Draw the OBB
};

#endif
