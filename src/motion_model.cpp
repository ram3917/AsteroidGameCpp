#include"motion_model.h"

void MotionModel::MoveDown(Position& pos)
{
    pos += Position(1,1);
}

void MotionModel::MoveUp(Position& pos)
{
    pos -= Position(1, 1);   
}