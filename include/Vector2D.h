/**
 @file Vector2D.h
 */

#ifndef VECTOR2D_H
#define VECTOR2D_H
/*! \class Vector2D
 \brief A 2D vector class
 */
class Vector2D
{
protected:
    float fData[2];   /*!< Float array to hold the vector data */
public:
    Vector2D(); //!< Default constructor
    Vector2D(const float fAllValues /*!< Value which x and y will be set to */); //!< Constructor that takes in a value and sets all components to equal it
    Vector2D(const float fX /*!< Initial x value*/, const float fY /*!< Initial Y value*/); //!< Constructor that takes in an x and y value
    void set(const float fX, const float fY);//!< Set both the x and y values of the vector
    void setX(const float fXIn);//!< Set the x value of the vector
    void setY(const float fYIn);//!< Set the y value of the vector
    float angle(const Vector2D& kother) const; //!< Return angle between two vectors
    float dotProduct(const Vector2D& kOther ) const; //!< Return dot product of two vectors
    float crossProduct(const Vector2D& kOther) const; //!< Return cross product of two vectors
    Vector2D vectorCrossScalar(const float kfScalar) const; //!< Returns cross product of vector by scalar
    
    Vector2D scalarCrossVector(const float kfScalar) const; //!< Returns cross product of scalar by vector
    Vector2D unitVector() const; //!< Return unit vector
    float x() const;//!< Return x value of vector
    float y() const;//!< Return y value of vector
    float magnitude() const;//!< Return magnitude of vector
    Vector2D operator- (const Vector2D& kOther) const;//!< Operator for subtracting one vector from another
    Vector2D operator+ (const Vector2D& kOther) const;//!< Operator for adding two vectors
    Vector2D operator* (const Vector2D& kOther) const;//!< Operator for multiplying two vectors
    Vector2D operator/ (const Vector2D& kOther) const;//!< Operator for dividing two vectors
    Vector2D operator* (const float kfScalar) const;//!< Operator for multiplying a vector by a scalar

    Vector2D& operator+= (const Vector2D& kOther);//!< Operator to add components of one vector to the other
    Vector2D& operator-= (const Vector2D& kOther);//!< Operator to subtract components of one vector from another
    Vector2D operator-()const; //!< Returns the negative of the vector
    
    Vector2D& operator= (const Vector2D& kOther);//!< Operator for assigning a vector
    bool operator==(const Vector2D& kOther) const;//!< Operator to check if a vector is equal to another vector
};
#endif