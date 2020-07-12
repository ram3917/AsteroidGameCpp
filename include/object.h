#ifndef OBJECT_H_
#define OBJECT_H_

/**
  * Base class with all definitions
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

class Object
{
public:

    // Setters and getters
    void SetPosition(int x, int y)
    {
        Position p = { x, y };
        SetPosition(p);
    }
    
    void SetSize(int x, int y)
    {
        Size s = { x, y };
        SetSize(s);
    }

    void SetPosition(Position pos)
    {
        _pos.x = pos.x;
        _pos.y = pos.y;
    }

    void SetSize(Size size)
    {
        _size.x = size.x;
        _size.y = size.y;
    }

    Position& GetPosition() { return _pos; }
    Size& GetSize() { return _size; }

    void KillObject() { _active = false; }
    bool IsAlive() const {return _active; }

    void SetSpeed(int speed) { _speed = speed; }
    int GetSpeed() { return _speed; }

private:

   // Default alive
   bool _active { true };
   Position _pos;
   Size _size;
   int _speed { 0 };
};

#endif