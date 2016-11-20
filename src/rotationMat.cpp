//
//  rotationMat.cpp
//  Pinball
//
//  Created by Dinis Marques Firmino on 11/02/2015.
//  Copyright (c) 2015 DYN. All rights reserved.
//

#include "rotationMat.h"
#include <cmath>

RotationMat::RotationMat() {
    fData[0] = 0;
    fData[1] = 0;
    fData[2] = 0;
    fData[3] = 0;
}

RotationMat::RotationMat(const float f_Rads) {
    setAngleRadians(f_Rads);
}

void RotationMat::setAngleRadians(const float f_Rads) {
    float fCos = cosf(f_Rads);
    float fSin = sinf(f_Rads);
    fData[0] = fCos;
	fData[1] = -fSin;
	fData[2] = fSin;
    fData[3] = fCos;
}

Vector2D RotationMat::rotateVector(const Vector2D& kVec) const {
    Vector2D row1 = Vector2D(fData[0], fData[1]);
    Vector2D row2 = Vector2D(fData[2], fData[3]);
    return Vector2D(kVec.dotProduct(row1), kVec.dotProduct(row2));
}

Vector2D RotationMat::inverseRotateVector(const Vector2D& kVec) const {
    Vector2D column1 = Vector2D(fData[0], fData[2]);
    Vector2D column2 = Vector2D(fData[1], fData[3]);
    return Vector2D(kVec.dotProduct(column1), kVec.dotProduct(column2));
}