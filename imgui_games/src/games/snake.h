#include "game.h"

class Snake: public Game
{
public:
    void reset() override;
    void update(ImGuiIO& io, float elapsed_time) override;
    void draw(ImGuiIO& io, ImDrawList& bg_drawlist) override;
    std::string get_name()  override {
        return "Snake";
    };
private:
    int head_x;
    int head_y;
};
