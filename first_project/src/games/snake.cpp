#include "snake.h"

#include <iostream>

void Snake::update(ImGuiIO& io, float elapsed_time)
{
    std::cout << "update\n"; 
}

void Snake::reset()
{
    std::cout << "reset\n"; 
}

void Snake::draw(ImGuiIO& io, ImDrawList& bg_drawlist)
{
    
    ImVec2 x{30, 30};
    float screen_radius{30};
    ImColor col {0, 255, 255};
    ImVec2 y{0, 0};
    
    bg_drawlist.AddCircleFilled(x, screen_radius, col);
    bg_drawlist.AddText(y, col, "Hello");
    std::cout << "draw\n";
}
