
#include "ball.h"

#include "../../utils/consts.h"

void Ball::reset(Point& p, Vect& s, float r, int c)
{
    center_position = p;
    speed = s;
    radius = r;
    color = c;
}

void Ball::draw(ImDrawList& draw_list, Vect& world_to_screen)
{
    Point screen_pos = center_position * world_to_screen;
    float screen_radius = radius * world_to_screen.x;
    ImVec2 screen_pos2{screen_pos.x, screen_pos.y};
    draw_list.AddCircleFilled(screen_pos2, screen_radius, COLORS[color]);
}