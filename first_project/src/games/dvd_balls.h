#include "game.h"

#include "elements/ball.h"

class DVDBalls: public Game
{
public:
    void reset() override;
    void update(ImGuiIO& io, float elapsed_time) override;
    void draw(ImGuiIO& io, ImDrawList& draw_list) override;
private:
    void process_ball_border_collided();

    void draw_ball(ImDrawList& draw_list);

    int _balls_count = 1;
    Ball _ball;
    int _ball_color = 5;
};
