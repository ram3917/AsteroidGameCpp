#include "motion_model.h"
#include <algorithm>

MotionModel::MotionModel(int screenX, int screenY)
{
    _area.w = screenX;
    _area.h = screenY;
}

void MotionModel::MoveDown(Position* pos, int& speed)
{
    pos->x = (pos->x + speed);
}

void MotionModel::MoveUp(Position* pos, int& speed)
{
    pos->x = (pos->x - speed);
}

void MotionModel::MoveLeft(Position* pos, int& speed)
{
    pos->y = (pos->y - speed);
}

void MotionModel::MoveRight(Position* pos, int& speed)
{
    pos->y = (pos->y + speed);
}

bool MotionModel::IsItemOnScreen(const Position& pos,
                             const Size& size)
{
  // Check if item is on edge
  return ((0 <= pos.x) && ((_area.w - size.w) >= pos.x) &&
      (0 <= pos.y) && ((_area.h - size.h) >= pos.y));    
}

bool MotionModel::CheckCollision(Position& l1, Size& s1,
                     Position& l2, Size& s2)
{
    if ( (l1.x > l2.x + s2.h) || (l1.x + s1.h < l2.x) ||
       (l1.y > l2.y + s2.w) || (l1.y + s1.w < l2.y) )
    return false;    
  
  return true;  
}