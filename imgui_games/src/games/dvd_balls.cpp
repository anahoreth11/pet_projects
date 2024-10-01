#include "dvd_balls.h"

#include "../utils/base.h"
#include "../utils/consts.h"
#include <cstdlib>
#include <iostream>
#include <string>

void DVDBalls::process_balls_border_collided()
{
    for(auto& ball: _balls)
    {
        process_ball_border_collided(ball);
    }
}

bool DVDBalls::is_balls_collided(Ball& first_ball, Ball& second_ball, float elapsed_time)
{
    // we consume that the second ball is static and the first ball is dynamic
    Vect speed = first_ball.speed - second_ball.speed;
    float distance = get_distance(first_ball.center_position, second_ball.center_position);
    distance -= first_ball.radius + second_ball.radius;

    // velocity is the magnitude of the speed
    float velocity = get_module(speed);
    if(velocity * elapsed_time < distance)
    {
        return false;
    }
    
    return true;
}

void DVDBalls::process_collision(Ball& first_ball, Ball& second_ball)
{

}

void DVDBalls::process_balls_collided(float elapsed_time)
{
    // collisions_count = 0;
    for(int i = 0; i < _balls_count - 1; ++i)
    {
        for(int j = i + 1; j < _balls_count; ++j)
        {
            bool is_collided = is_balls_collided(_balls[i], _balls[j], elapsed_time);
            if(is_collided)
            {
                ++collisions_count;
                 process_collision(_balls[i], _balls[j]);
            }
        }
    }
}

void DVDBalls::process_ball_border_collided(Ball& ball)
{
    bool has_collision = false;

    if (ball.center_position.x < ball.radius)
    {
        ball.center_position.x += (ball.radius - ball.center_position.x) * 2.0f;
        ball.speed.x *= -1.0f;
        has_collision = true;
    }
    else if (ball.center_position.x > (_world_size.x - ball.radius))
    {
        ball.center_position.x -= (ball.center_position.x - (_world_size.x - ball.radius)) * 2.0f;
        ball.speed.x *= -1.0f;
        has_collision = true;
    }

    if (ball.center_position.y < ball.radius)
    {
        ball.center_position.y += (ball.radius - ball.center_position.y) * 2.0f;
        ball.speed.y *= -1.0f;
        has_collision = true;
    }
    else if (ball.center_position.y > (_world_size.y - ball.radius))
    {
        ball.center_position.y -= (ball.center_position.y - (_world_size.y - ball.radius)) * 2.0f;
        ball.speed.y *= -1.0f;
        has_collision = true;
    }

    if(has_collision) 
    {
        ball.color = (ball.color + 1) % COLORS.size();
    }
}

void DVDBalls::update(ImGuiIO& io, float elapsed_time)
{
    _world_to_screen = Vect(
        io.DisplaySize.x / _world_size.x, 
        io.DisplaySize.y / _world_size.y);
    
    process_balls_collided(elapsed_time);

    for(auto& ball: _balls)
    {
         ball.center_position += ball.speed * elapsed_time;
    }

    process_balls_border_collided();
}

void DVDBalls::reset(const GameSettings& game_settings)
{
    _world_size.x = game_settings.world_size.x;
    _world_size.y = game_settings.world_size.y;
    
    // TODO use params from settings
    float x_position = 300.0f;
    float y_position = _world_size.y * 0.6f;
    float ball_radius = 70.0f;
    float ball_speed = 250.0f;
    for(auto& ball: _balls)
    {
        // x_position = rand() % static_cast<int>(_world_size.x)
        Point ball_center_position{x_position, y_position};

        int x_speed_sign = (2.0f * (rand() & 1) - 1);
        x_speed_sign = 1;
        Vect speed{x_speed_sign * ball_speed, ball_speed};
        int ball_color = rand() % COLORS.size();
        ball_color = 7;
        ball.reset(ball_center_position, speed, ball_radius, ball_color);
        x_position += ball_radius * 4;
    }
    _balls[1].speed = {0.0, 0.0};
}

void DVDBalls::reset()
{
    _world_size.x = DEFAULT_WORLD_SIZE.x;
    _world_size.y = DEFAULT_WORLD_SIZE.y;

    float x_position = 300.0f;
    float y_position = _world_size.y * 0.6f;
    float ball_radius = 70.0f;
    float ball_speed = 250.0f;
    for(auto& ball: _balls)
    {
        // x_position = rand() % static_cast<int>(_world_size.x)
        Point ball_center_position{x_position, y_position};

        int x_speed_sign = (2.0f * (rand() & 1) - 1);
        x_speed_sign = 1;
        Vect speed{x_speed_sign * ball_speed, ball_speed};
        int ball_color = rand() % COLORS.size();
        ball_color = 7;
        ball.reset(ball_center_position, speed, ball_radius, ball_color);
        x_position += ball_radius * 4;
    }
    _balls[1].speed = {0.0, 0.0};
}

void DVDBalls::draw(ImGuiIO& io, ImDrawList& draw_list)
{
    draw_balls(draw_list);
    draw_collisions_count(draw_list);
}

void DVDBalls::draw_collisions_count(ImDrawList& draw_list)
{
    std::string s = "Collisions_count = " + std::to_string(collisions_count);
    ImVec2 screen_pos{50, 100};
    draw_list.AddText(screen_pos, COLORS[3], s.c_str());
}

void DVDBalls::draw_balls(ImDrawList& draw_list)
{
    for(auto& ball: _balls)
    {
        ball.draw(draw_list, _world_to_screen);
    }
}