//
//  Vector2D.cpp
//  Pinball
//
//  Created by Dinis Marques Firmino on 23/01/2015.
//  Copyright (c) 2015 Dinis Marques Firmino. All rights reserved.
//

#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D()
{
	fData[0] = 0.0f;
	fData[1] = 0.0f;
}

Vector2D::Vector2D(const float fAllValues)
{
	fData[0] = fAllValues;
    fData[1] = fAllValues;
}

Vector2D::Vector2D(const float fXIn, const float fYIn)
{
    fData[0] = fXIn;
    fData[1] = fYIn;
}

void Vector2D::set(const float fXIn, const float fYIn)
{
    fData[0] = fXIn;
    fData[1] = fYIn;
}

void Vector2D::setX(const float fXIn)
{
    fData[0] = fXIn;
}

void Vector2D::setY(const float fYIn)
{
    fData[1] = fYIn;
}

Vector2D Vector2D::unitVector() const
{
    float fMag = magnitude();
	return Vector2D(x()/fMag,y()/fMag);
}

float Vector2D::dotProduct(const Vector2D &kOther) const
{
    float dp = (x() * kOther.x()) + (y() * kOther.y());
    return dp;
}

float Vector2D::crossProduct(const Vector2D& kOther) const
{
    return (x() * kOther.y()) - (y() * kOther.x());
}

Vector2D Vector2D::scalarCrossVector(const float kfScalar) const
{
    return Vector2D(-kfScalar * y(), kfScalar * x());
}

Vector2D Vector2D::vectorCrossScalar(const float kfScalar) const
{
    return Vector2D(y() * kfScalar, -kfScalar * x());
}

float Vector2D::angle(const Vector2D &kOther) const
{
    float magV1 = magnitude();
    float magV2 = kOther.magnitude();
    
    float angle = (x() * kOther.x() + y() * kOther.y()) / (magV1 * magV2);
    return angle;
}

float Vector2D::x() const
{
	return fData[0];
}

float Vector2D::y() const
{
    return fData[1];
    
}

float Vector2D::magnitude() const
{
    return std::sqrtf( fData[0]*fData[0] + fData[1]*fData[1] );
}


Vector2D Vector2D::operator*(const float kfScalar) const
{
    return Vector2D(x()*kfScalar, y()*kfScalar);
}

Vector2D Vector2D::operator+(const Vector2D& kOther) const
{
    return Vector2D(x() + kOther.x(), y() + kOther.y());
}

Vector2D Vector2D::operator-(const Vector2D& kOther) const
{
    return Vector2D(x() - kOther.x(), y() - kOther.y());
}

Vector2D Vector2D::operator*(const Vector2D& kOther) const
{
    return Vector2D(x() * kOther.x(), y() * kOther.y());
}

Vector2D& Vector2D::operator+=(const Vector2D& kOther)
{
    set(x()+kOther.x(), y()+kOther.y());
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& kOther)
{
    set(x()-kOther.x(), y()-kOther.y());
    return *this;
}

Vector2D Vector2D::operator/(const Vector2D& kOther) const
{
    return Vector2D(x() / kOther.x(), y() / kOther.y());
}

Vector2D& Vector2D::operator= (const Vector2D& kOther)
{
    set(kOther.x(), kOther.y());
    return *this;
}

bool Vector2D::operator==(const Vector2D& kOther) const
{
    return ((x() == kOther.x()) && (y() == kOther.y()));
}

Vector2D Vector2D::operator-() const
{
    return Vector2D(-x(), -y());
}
