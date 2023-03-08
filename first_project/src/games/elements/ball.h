#pragma once

#include "../../utils/base.h"

struct Ball
{
public:
    void reset(Vect& p, Vect& s, float r); 
    Vect center_position;
    Vect speed;
    float radius;
};
