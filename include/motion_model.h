#ifndef MOTION_MODEL_H_
#define MOTION_MODEL_H_

/*
*   A base class defines the motion for all the 
*   objects in space and their states. 
*/

#include "object.h"

// Motion model
class MotionModel
{
public:

    MotionModel(int screenX, int screenY);

    // Move up and down
    void MoveUp(Position* pos, int& speed);
    void MoveDown(Position* pos, int& speed);
    void MoveLeft(Position* pos, int& speeds);
    void MoveRight(Position* pos, int& speed);

    // Is in the play area
    bool IsItemOnScreen(const Position& pos,
                      const Size& size);

    // Check collision
    bool CheckCollision(Position& l1, Size& s1,
                     Position& l2, Size& s2);
 
private:
    // Area
    Size _area;
};

#endif