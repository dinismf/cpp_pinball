//
//  Randomiser.cpp
//  Pinball
//
//  Created by Dinis Marques Firmino on 28/01/2015.
//  Copyright (c) 2015 DYN. All rights reserved.
//

/**
 @file randomiser.cpp
 */

#include "Randomiser.h"

Randomiser::Randomiser() //!< Default constructor
{
    srand( static_cast<unsigned int>(time(NULL)));
}

int Randomiser::getRandBetween(int lower /* Lower bound */, int upper /* Upper bound */) //!< Returns a random number between the lower and upper bounds
{
    double delta = upper - lower;
    double randomScalar = (double)rand() / (double)RAND_MAX;
    double randomDelta = delta * randomScalar;
    return lower + (int)randomDelta;
}

float Randomiser::getRandBetween(float lower /* Lower bound */, float upper /* Upper bound */)//!< Returns a random number between the lower and upper bounds
{
    double delta = upper - lower;
    double randomScalar = (double)rand() / (double)RAND_MAX;
    double randomDelta = delta * randomScalar;
    return lower + (float)randomDelta;
}

double Randomiser::getRandBetween(double lower /* Lower bound */, double upper /* Upper bound */) //!< Returns a random number between the lower and upper bounds
{
    double delta = upper - lower;
    double randomScalar = (double)rand() / (double)RAND_MAX;
    double randomDelta = delta * randomScalar;
    return lower + randomDelta;
}