#include "mfalcon.h"

Bullet::Bullet(Position pos)
{
  SetPosition(pos);
  SetSize(2, 2);
  SetSpeed(5);
}

MFalcon::MFalcon(int x, int y)
{    
    SetPosition(x, y);
    SetSize(15, 10);
    SetSpeed(10);
}

void MFalcon::Shoot()
{
    // Get current position
    auto pos = GetPosition();

    // Init bullet
    Bullet bullet(pos);
    
    // Add list to bullet
    _bullets.emplace_back(std::make_shared<Bullet>(bullet));
}

void MFalcon::UpdateBullets(std::vector<std::shared_ptr<Asteroid>>& asteroids)
{

  MotionModel mm(1, 1);

  // Update position
  for (auto iter = _bullets.begin(); iter != _bullets.end(); )
  {
    Position pos = (*iter)->GetPosition();
    int speed = (*iter)->GetSpeed();
    Size size = (*iter)->GetSize();
    mm.MoveUp(&pos, speed);
   
    // bool to get status
    bool hasHit = false;

   // Check if bullet has hit target
    for (auto& a : asteroids)
    {
      auto aSize = a->GetSize();
      auto aPos  = a->GetPosition();

      // If collision
      if (mm.CheckCollision(pos, size, aPos, aSize))
      {
        // kill asteroid
        a->KillAsteroid();
        hasHit = true;        
        break;
      }     
    }

    if (hasHit)
    {
      // Kill bullet
        _bullets.erase(iter);
    }       
    else
    {
      // Update position
        (*iter)->SetPosition(pos);
        ++iter;
    }    
  }
} 
