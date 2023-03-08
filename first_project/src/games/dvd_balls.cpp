#include "dvd_balls.h"

#include "../utils/consts.h"
#include <cstdlib>
#include <iostream>


void DVDBalls::process_ball_border_collided()
{
    bool has_collision = false;

    if (_ball.center_position.x < _ball.radius)
    {
        _ball.center_position.x += (_ball.radius - _ball.center_position.x) * 2.0f;
        _ball.speed.x *= -1.0f;
        has_collision = true;
    }
    else if (_ball.center_position.x > (_world_size.x - _ball.radius))
    {
        _ball.center_position.x -= (_ball.center_position.x - (_world_size.x - _ball.radius)) * 2.0f;
        _ball.speed.x *= -1.0f;
        has_collision = true;
    }

    if (_ball.center_position.y < _ball.radius)
    {
        _ball.center_position.y += (_ball.radius - _ball.center_position.y) * 2.0f;
        _ball.speed.y *= -1.0f;
        has_collision = true;
    }
    else if (_ball.center_position.y > (_world_size.y - _ball.radius))
    {
        _ball.center_position.y -= (_ball.center_position.y - (_world_size.y - _ball.radius)) * 2.0f;
        _ball.speed.y *= -1.0f;
        has_collision = true;
    }

    if(has_collision) 
    {
        _ball_color = rand() % COLORS.size();
    }
}

void DVDBalls::update(ImGuiIO& io, float elapsed_time)
{
    _world_to_screen = Vect(
        io.DisplaySize.x / _world_size.x, 
        io.DisplaySize.y / _world_size.y);

    // _world_to_screen= Vect{1, 1};
    _ball.center_position += _ball.speed * elapsed_time;

    process_ball_border_collided();
}

void DVDBalls::reset()
{
    _world_size.x = DEFAULT_WORLD_SIZE.x;
    _world_size.y = DEFAULT_WORLD_SIZE.y;

    Vect ball_center_position{rand() % static_cast<int>(_world_size.x), 
                        _world_size.y * 0.6f};
    float ball_radius = 10.0f;
    float ball_speed = 150.0f;
    Vect speed{(2.0f * (rand() & 1) - 1) * ball_speed, ball_speed};
    _ball.reset(ball_center_position, speed, ball_radius);
}

void DVDBalls::draw(ImGuiIO& io, ImDrawList& draw_list)
{
    draw_ball(draw_list);
}

void DVDBalls::draw_ball(ImDrawList& draw_list)
{
    Vect screen_pos = _ball.center_position * _world_to_screen;
    float screen_radius = _ball.radius * _world_to_screen.x;
    ImVec2 screen_pos2{screen_pos.x, screen_pos.y};
    draw_list.AddCircleFilled(screen_pos2, screen_radius, COLORS[_ball_color]);
}