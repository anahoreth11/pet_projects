#pragma once

#include "imgui.h"

class Game
{
public:
    virtual ~Game() = default;;
    virtual void reset()  = 0;
    virtual void update(ImGuiIO& io, float elapsed_time) = 0;
    virtual void draw(ImGuiIO& io, ImDrawList& bg_drawlist)  = 0;
};
