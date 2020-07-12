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
    SetSize(15, 15);
    SetSpeed(10);
}

void MFalcon::Shoot()
{
    // Get current position
    auto pos = GetPosition();

    // Init bullet
    Bullet bullet(pos);
    
    // Add list to bullet
    _bullets.emplace_back(bullet);
}

void MFalcon::UpdateBullets()
{

  MotionModel mm(1, 1);

  // Update position
  for (auto& b : _bullets)
  {
    Position pos = b.GetPosition();
    int speed = b.GetSpeed();
    mm.MoveUp(&pos, speed);
    // Update position
    b.SetPosition(pos);
  }
}
