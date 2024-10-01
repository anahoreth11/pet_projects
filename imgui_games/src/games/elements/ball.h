#pragma once

#include "../../utils/base.h"
#include "imgui.h"

struct Ball
{
public:
    void reset(Point& p, Vect& s, float r, int c); 
    void draw(ImDrawList& draw_list, Vect& world_to_screen);
    Point center_position;
    Vect speed;
    float radius;
    int color = 5;
};
