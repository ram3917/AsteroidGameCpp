#ifndef MOTION_MODEL_H_
#define MOTION_MODEL_H_

/*
*   This class defines the motion models for all the 
*   objects in space.
*/

class Position 
{
public:
    Position(int x, int y);

    // Rule of five
    ~Position();
    Position(const Position& pos)
    {
        *this = pos;
    }   

    Position& operator=(const Position& pos)
    {
        *this = pos;

        return *this;
    }

    Position(const Position&& pos)
    {
        *this = pos;    
    }

    Position& operator=(Position&& pos)
    {
        *this = pos;
        return *this;
    }

    Position operator+=(Position pos)
    {
        pos._x += this->_x;
        pos._y += this->_y;

        return *this;
    }

    Position operator-=(Position pos)
    {
        pos._x += this->_x;
        pos._y += this->_y;

        return *this;
    }

private:
    int _x;
    int _y;
};

class MotionModel
{
public:

    MotionModel();

    // Move up and down
    void MoveUp(Position& pos);
    void MoveDown(Position& pos);

private:

};

#endif