#include "game.h"

#include "elements/ball.h"

#include <vector>

class DVDBalls: public Game
{
public:
    DVDBalls(int balls_count): 
        _balls_count(balls_count), 
        _balls(std::vector<Ball>(balls_count))  {}

    void reset() override;
    void reset(const GameSettings& game_settings)  override;
    void update(ImGuiIO& io, float elapsed_time) override;
    void draw(ImGuiIO& io, ImDrawList& draw_list) override;
    std::string get_name()  override {
        return "DVDBalls";
    };
private:
    // collision
    void process_ball_border_collided(Ball & ball);
    void process_balls_border_collided();
    void process_balls_collided(float elapsed_time);
    bool is_balls_collided(Ball& first_ball, Ball& second_ball, float elapsed_time);
    void process_collision(Ball& first_ball, Ball& second_ball);

    // drawing
    void draw_balls(ImDrawList& draw_list);
    void draw_collisions_count(ImDrawList& draw_list);

    // fields
    int collisions_count = 0;
    int _balls_count;
    std::vector<Ball> _balls;
    Ball _ball;
};
