#ifndef M_FALCON_H_
#define M_FALCON_H_

#include "motion_model.h"

class MFalcon : public MotionModel
{
public:
    
    MFalcon(int width, int height);

    // TODO : Rule of 5 ?

    // getter
    bool IsAlive() {return _alive; }

    // void Update();

private:

    // default alive
    bool _alive { true };

    // Motion 
    // MotionModel _mm;

};

#endif