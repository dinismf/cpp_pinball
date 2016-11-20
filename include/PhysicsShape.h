/**
 @file PhysicsShape.h
 */

#ifndef PHYSICSSHAPE_H
#define PHYSICSSHAPE_H

//!< Enumerator for the types of shapes
enum type {
    circle,
    aabb,
    obb
};

/*! \class PhysicsShape
 \brief A class which holds the types of shapes
 */
class PhysicsShape
{
protected:
    type shapeType; //!< Type of shape
public:
    PhysicsShape(); //!< Default constructor
    void setType(type shapeTypeIn/*!< new shape type*/); //!< Set the type of shape
    type getType(); //!< Return the type of shape
};


#endif
