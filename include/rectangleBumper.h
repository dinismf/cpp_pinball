/**
 @file rectangleBumper.h
 */

#ifndef RECTANGLEBUMPER_H
#define RECTANGLEBUMPER_H

#include "bumper.h"
#include <SFML/Graphics.hpp>

/*! \class RectangleBumper
 \brief A Rectangle bumper class which creates a rectangular bumper
 */
class RectangleBumper : public Bumper, public OBB
{
public:
    RectangleBumper();	//!< Default constructor 
    RectangleBumper(const Vector2D kPosIn /*!< New position*/, const Vector2D kHalfExtentsIn/*!< New half extents*/, const float kfAngleIn/*!< new angle */, const int kiPointsIn /*!< New points*/, const sf::Color kColourIn/*!< New colour*/); //!< Rectangle bumper main constructor
};


#endif
