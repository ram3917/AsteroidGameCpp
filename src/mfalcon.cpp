#include "mfalcon.h"

MFalcon::MFalcon(int grid_width, int grid_height)
{    
    SetPosition(grid_height - (grid_height/10),
                         (grid_width / 2));
    SetSize(15, 15);
    SetArena(grid_height, grid_width);
    SetSpeed(10);
}