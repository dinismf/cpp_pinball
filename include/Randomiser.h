/**
 @file randomiser.h
 */

#ifndef RANDOMISER_H
#define RANDOMISER_H

/*! \class Randomiser
 \brief Simple class to generate random numbers
 */

#include <ctime>
#include <cstdlib>

class Randomiser
{
public:
    Randomiser(); //!< Default constructor
    int getRandBetween(int lower /*! Lower bound */, int upper /*! Upper bound */); //!< Returns a random number between the lower and upper bounds
    float getRandBetween(float lower /*! Lower bound */, float upper /*! Upper bound */); //!< Returns a random number between the lower and upper bounds
    double getRandBetween(double lower /*! Lower bound */, double upper /*! Upper bound */); //!< Returns a random number between the lower and upper bounds
};

#endif
