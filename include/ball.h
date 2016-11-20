/**
 @file ball.h
 */

#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "Vector2D.h"
#include "CirclePhys.h"
#include "body.h"

/*! \class Ball
 \brief A Ball class which creates a circle and draws it
 */

class Ball : public sf::Drawable
{
protected:
    CirclePhys circleShape; //!< Holds the properties of the circle
    sf::Color colour; //!< Colour of the particle for drawing
public:
    Body body;  //!< Circle body
    Ball(); //!< Default contructor, set everything to 0
    Ball(const Vector2D& pos /*!< initial position */, const Vector2D& kVel /*!< initial velocity */, const Vector2D& kAccel /*!< initial acceleration */,const float kfRadiusIn/*!< initial radius */); //!< Constructor which takes position, velocity and acceleration
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //!< Draw the circle
    sf::Color getColour() const; //!< Returns the colour of the circle
    void setColour(const sf::Color& col /*!< new colour */); //!< Sets the colour of the circle
};

#endif
