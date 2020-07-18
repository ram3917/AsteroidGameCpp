#ifndef M_FALCON_H_
#define M_FALCON_H_

#include "object.h"
#include "motion_model.h"
#include "asteroid.h"
#include <vector>
#include <memory>
#include <algorithm>

class Bullet : public Object
{
public:
    Bullet(Position pos);

    // Rule of five
    ~Bullet() = default;
    Bullet(const Bullet& other) = default;    
    Bullet& operator=(const Bullet& other) = default;

    Bullet(Bullet&& other) = default;
    Bullet& operator=(Bullet&& other) = default;
};

class MFalcon : public Object
{
public:
    
    MFalcon(int x, int y);

    // Rule of five
    ~MFalcon() = default;
    MFalcon(const MFalcon& other) = default;   
    MFalcon& operator=(const MFalcon& other) = default;

    MFalcon(MFalcon&& other) = default;
    MFalcon& operator=(MFalcon&& other) = default;

    void Shoot();

    void UpdateBullets(std::vector<std::shared_ptr<Asteroid>>& asteroids);    

    std::vector<std::shared_ptr<Bullet>> GetBullets()
    {
        return _bullets;
    }

private:
   
    // A list of all bullets
    std::vector<std::shared_ptr<Bullet>> _bullets;
};

#endif