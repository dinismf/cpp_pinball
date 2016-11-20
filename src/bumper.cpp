/**
 @file bumper.cpp
 */

#include "bumper.h"

Bumper::Bumper()
{
    
}

Bumper::Bumper(bumperType typeIn, int iPointsIn)
{
    type = typeIn;
	iPoints = iPointsIn;
}

void Bumper::setType(bumperType typeIn) //!< Set the type of bumper
{
    type = typeIn;
}

bumperType Bumper::getType() //!< Return the type of bumper
{
    return type;
}

void Bumper::setPoints(int iPointsIn) //!< Sets the points value of the bumper
{
	iPoints = iPointsIn;
}

int Bumper::getPoints() //!< Returns the points value
{
	return iPoints;
}