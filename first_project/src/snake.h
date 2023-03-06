#include "game.h"

class Snake: public Game
{
public:
    void reset() override;
    void update(ImGuiIO& io, float elapsed_time) override;
    void draw(ImGuiIO& io, ImDrawList& bg_drawlist) override;
private:
    int head_x;
    int head_y;
};
