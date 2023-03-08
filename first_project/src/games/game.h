#pragma once

#include "imgui.h"

#include "../utils/base.h"

class Game
{
public:
    virtual ~Game() = default;
    virtual void reset()  = 0;
    virtual void update(ImGuiIO& io, float elapsed_time) = 0;
    virtual void draw(ImGuiIO& io, ImDrawList& bg_drawlist)  = 0;
protected:
    Vect _world_size = Vect(0.0f);
    Vect _world_to_screen = Vect(0.0f);
};
