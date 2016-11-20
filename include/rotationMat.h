/**
 @file rotationMat.h
 */
#ifndef ROTATIONMAT_H
#define ROTATIONMAT_H

#include "Vector2D.h"

/*! \class RotationMat
 \brief A class that creates a rotation matrix
 */
class RotationMat
{
protected:
    float fData[4];  /*!< Stores matrix data */
public:
    RotationMat(); //!< Default constructor
    RotationMat(const float f_Rads); //!< Constructor that takes in angle in radians
    void setAngleRadians(const float f_Rads/*!< New radians*/); //!< Sets the angle of the rotation matrix
    Vector2D rotateVector(const Vector2D& kVec/*!< Vector to rotate*/) const;   //!< Rotates a given vector
    Vector2D inverseRotateVector(const Vector2D& kVec /*!< Vector to inverse rotate*/) const; //!< Inverse rotates a given vector
};


#endif
