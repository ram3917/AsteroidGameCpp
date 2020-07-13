#ifndef M_FALCON_H_
#define M_FALCON_H_

#include "object.h"
#include "motion_model.h"
#include "asteroid.h"
#include <vector>
#include <memory>

class Bullet : public Object
{
public:
    Bullet(Position pos);
};

class MFalcon : public Object
{
public:
    
    MFalcon(int x, int y);

    void Shoot();

    void UpdateBullets(std::vector<Asteroid>& asteroids);    

    std::vector<Bullet> GetBullets()
    {
        return _bullets;
    }

private:
    
    // A list of all bullets
    std::vector<Bullet> _bullets;
};

#endif