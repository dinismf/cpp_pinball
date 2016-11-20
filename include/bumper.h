/**
 @file bumper.h
 */

#ifndef BUMPER_H
#define BUMPER_H

#include "ball.h"
#include "obb.h"

/*!< Enumerator that holds the type of bumper*/
enum bumperType{
    roundBumper,
    rectangleBumper
};

/*! \class Bumper
 \brief A Bumper class which hold the type and points value of a bumper
 */
class Bumper
{
protected:
    bumperType type;	/*!< Type of bumper*/
    int iPoints;	/*!< Points value */
    
public:
    Bumper();	//!< Default constructor
    Bumper(bumperType typeIn, int iPointsIn);	//!< Constructor that takes in type of bumper and points value
    void setType(bumperType typeIn); //!< Set the type of bumper
    bumperType getType(); //!< Return the type of bumper
    void setPoints(int pointsIn); //!< Sets the points value of the bumper
    int getPoints(); //!< Returns the points value    
};
#endif
