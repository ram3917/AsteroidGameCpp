#include "motion_model.h"

MotionModel::MotionModel(int screenX, int screenY)
{
    _area.x = screenX;
    _area.y = screenY;
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
  return ((0 <= pos.x) && ((_area.x - size.x) >= pos.x) &&
      (0 <= pos.y) && ((_area.y - size.y) >= pos.y));    
}