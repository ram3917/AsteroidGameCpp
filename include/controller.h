#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "mfalcon.h"
#include "motion_model.h"

class Controller{

public:

  Controller(int width, int height);

  void HandleInput(bool &running, std::shared_ptr<MFalcon> falcon) const;

private:

  MotionModel* _mm;

};

#endif