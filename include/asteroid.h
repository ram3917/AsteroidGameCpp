#ifndef ASTEROID_H_
#define ASTEROID_H_

#include "object.h"

/**
 * Defines the enemy asteroids. They must be destroyed.
 * 
 */
class Asteroid : public Object
{
public:

    Asteroid(int x, int y)
    {
        SetPosition(x, y);
        SetSize(20,20);
        SetSpeed(2);
    }
};

#endif