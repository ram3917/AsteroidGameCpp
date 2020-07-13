#ifndef OBJECT_H_
#define OBJECT_H_

/**
  * Base class with all definitions
 */

// Move directions
enum class Direction{mLeft, mRight, mUp, mDown};

// World size
typedef struct Size
{
    int w { 0 };
    int h { 0 };
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
    
    void SetSize(int w, int h)
    {
        Size s = { w, h };
        SetSize(s);
    }

    void SetPosition(Position pos)
    {
        _pos.x = pos.x;
        _pos.y = pos.y;
    }

    void SetSize(Size size)
    {
        _size.w = size.w;
        _size.h = size.h;
    }

    Position& GetPosition() { return _pos; }
    Size& GetSize() { return _size; }
    
    void SetSpeed(int speed) { _speed = speed; }
    int GetSpeed() { return _speed; }

private:
   // Default alive
   Position _pos;
   Size _size;
   int _speed { 0 };
};

#endif