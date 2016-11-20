/**
 @file roundBumper.h
 */

#ifndef ROUNDBUMPER_H
#define ROUNDBUMPER_H

#include "bumper.h"
#include <SFML/Graphics.hpp>

/*! \class RoundBumper
 \brief A Round bumper class which creates a round bumper
 */
class RoundBumper : public Bumper, public Ball
{
public:
    RoundBumper();	//!< Default constructor
    RoundBumper(const Vector2D kPosIn /*!< New position */, const float kfRadiusIn/*!< New radius */, const int kiPointsIn/*!< New points value */, const sf::Color kColourIn/*!< New colour */);	//!< Main constructor
};

#endif
