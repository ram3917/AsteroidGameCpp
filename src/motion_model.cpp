#include"motion_model.h"

void MotionModel::MoveDown()
{
    Move(Direction::mDown);
}

void MotionModel::MoveUp()
{
    Move(Direction::mUp);
}

void MotionModel::MoveLeft()
{
    Move(Direction::mLeft);
}

void MotionModel::MoveRight()
{
    Move(Direction::mRight);
}

void MotionModel::Move(const Direction& dir)
{
    switch (dir)
    {
        case Direction::mUp:
            _pos.x = (_pos.x - _speed);
            break;
        case Direction::mDown:
            _pos.x = (_pos.x + _speed);
            break;
        case Direction::mLeft:
            _pos.y = (_pos.y - _speed);
            break;
        case Direction::mRight:
            _pos.y = (_pos.y + _speed);
            break;
    }

    // Set Item position to limits
    _pos.x = (_pos.x <= 0) ? 0 : _pos.x;
    _pos.x = (_pos.x >= _area.x - _size.x) ? _area.x - _size.x : _pos.x;

    _pos.y = (_pos.y <= 0) ? 0 : _pos.y;
    _pos.y = (_pos.y >= _area.y - _size.y) ? _area.y - _size.y : _pos.y;    
}