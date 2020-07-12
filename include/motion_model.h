#ifndef MOTION_MODEL_H_
#define MOTION_MODEL_H_

/*
*   This class defines the motion for all the 
*   objects in space and their states. 
*/

// Move directions
enum class Direction{mLeft, mRight, mUp, mDown};

// State : alive, dead
enum class State{sAlive, sDead};

// World size
typedef struct Size
{
    int x { 0 };
    int y { 0 };
}Size;

typedef struct Position
{
    int x { 0 };
    int y { 0 };
}Position;

// Motion model
class MotionModel
{
public:

    // MotionModel(int posX, int posY,
    //             int sizeX, int sizeY);

    // Move up and down
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    // Setters and Getters
    void SetPosition(int x, int y)
    {
        _pos.x = x;
        _pos.y = y;
    }

    void SetSize(int x, int y)
    {
        _size.x = x;
        _size.y = y;
    }

    void SetArena(int x, int y)
    {   
        _area.x = x;
        _area.y = y;
    }

    Position GetPosition()
    {
        return _pos;
    }

    Size GetSize()
    {
        return _size;
    }

    void SetSpeed(int speed)
    {        
        // Check against max allowed speed
       _speed = (speed > 10) ? 10 : speed;
    }

private:

    // Move 
    void Move(const Direction& dir);

    // Size
    Size _size;
    // Position
    Position _pos;
    // Game Area
    Size _area;
    // Object speed
    int _speed { 1 }; 
};

#endif