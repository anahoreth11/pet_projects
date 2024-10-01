#pragma once

#include "../utils/base.h"

struct GameSettings
{
    bool step_by_step = false;
    bool debug_draw = false;
    float debug_draw_pos_radius = 5.0f;
    float debug_draw_normal_length = 30.0f;
    float debug_draw_timeout = 0.5f;

    Vect world_size = Vect(800.0f, 600.f);
};