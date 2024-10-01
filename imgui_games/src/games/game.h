#pragma once

#include <string>

#include "imgui.h"

#include "game_settings.h"
#include "../utils/base.h"

class Game
{
public:
    virtual ~Game() = default;
    virtual void reset()  = 0;
    virtual void reset(const GameSettings& game_settings)  = 0;
    virtual void update(ImGuiIO& io, float elapsed_time) = 0;
    virtual void draw(ImGuiIO& io, ImDrawList& bg_drawlist)  = 0;

    virtual std::string get_name()  = 0;
protected:
    Vect _world_size = Vect(0.0f);
    Vect _world_to_screen = Vect(0.0f);
};
