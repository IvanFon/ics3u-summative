/// @file Physics.cpp
/// @brief Physics
/// @author Ivan Fonseca

#include "../inc/Physics.h"

#include "../inc/Utils.h"

Vector addVect(Vector a, Vector b) {
    return { a.x + b.x, a.y + b.y };
}

Vector subVect(Vector a, Vector b) {
    return { a.x - b.x, a.y - b.y };
}

Vector multVect(Vector a, Vector b) {
    return { a.x * b.x, a.y * b.y };
}

bool collides(Rectangle a, Rectangle b) {
    bool collidesX = (a.pos.x + a.size.x > b.pos.x) && (a.pos.x < b.pos.x + b.size.x);
    bool collidesY = (a.pos.y + a.size.y > b.pos.y) && (a.pos.y < b.pos.y + b.size.y);

    return collidesX && collidesY;
}

float collisionDepthX(Rectangle a, Rectangle b) {
    // a on left
    if (a.pos.x < b.pos.x) {
        return b.pos.x - (a.pos.x + a.size.x);
    }

    // a on right
    if (a.pos.x > b.pos.x) {
        return (b.pos.x + b.size.x) - a.pos.x;
    }
}

float collisionDepthY(Rectangle a, Rectangle b) {
    // a on top
    if (a.pos.y < b.pos.y) {
        return b.pos.y - (a.pos.y + a.size.y);
    }

    // a on bottom
    if (a.pos.y > b.pos.y) {
        return (b.pos.y + b.size.y) - a.pos.y;
    }
}

bool pointRect(Vector point, Rectangle rect) {
    return (
        point.x > rect.pos.x &&
        point.x < rect.pos.x + rect.size.x &&
        point.y > rect.pos.y &&
        point.y < rect.pos.y + rect.size.y
    );
}