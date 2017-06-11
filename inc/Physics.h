/// @file Physics.h
/// @brief Physics
/// @author Ivan Fonseca

#ifndef _INC_PHYSICS_H
#define _INC_PHYSICS_H

/// @brief A 2D vector
struct Vector {
    /// @brief X position
    float x;
    /// @brief Y position
    float y;
};

/// @brief A rectangle
struct Rectangle {
    /// @brief Position
    Vector pos;
    /// @brief Width and height
    Vector size;
};

/// @brief Adds two vectors
Vector addVect(Vector a, Vector b);

/// @brief Subtracts two vectors
Vector subVect(Vector a, Vector b);

/// @brief Multiplies two vectors
Vector multVect(Vector a, Vector b);

/// @brief Checks if two rectangles collide
/// @param a The first Rectangle to check
/// @param b The second Rectangle to check
/// @return \p true if colliding, \p false otherwise
bool collides(Rectangle a, Rectangle b);

/// @brief Finds the depth of a collision between two Rectangles on the X axis
/// @param a The colliding Rectangle
/// @param b The Rectangle to check a's depth into
/// @return The depth of the collision
float collisionDepthX(Rectangle a, Rectangle b);

/// @brief Finds the depth of a collision between two Rectangles on the Y axis
/// @param a The colliding Rectangle
/// @param b The Rectangle to check a's depth into
/// @return The depth of the collision
float collisionDepthY(Rectangle a, Rectangle b);

/// @brief Checks if a point is in a rectangle
/// @param point The point
/// @param rect The rectangle
/// @return \p true if point is in rectangle, \p false otherwise
bool pointRect(Vector point, Rectangle rect);

#endif
