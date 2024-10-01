// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "utils/gl_helper.h"

#include "games/game_settings.h"
#include "games/dvd_balls.h"
#include "games/snake.h"

#include <mathfu/rect.h>
#include <mathfu/vector.h>
#include <iostream>


int main(int, char**)
{
    GLHelper gl_helper;
    bool gl_init_result = gl_helper.init();
    if(!gl_init_result)
    {
        std::cout << "gl init error\n";
        return 1;
    }
    
    Game * game = new DVDBalls(2);
    GameSettings game_settings;
    game->reset();
    // Main loop
    double last_time = glfwGetTime();
    while (!gl_helper.is_window_should_close())
    {
        gl_helper.cycle();
        
        // update settings window
        {
            ImGui::Begin(game->get_name().c_str());

            ImGui::InputFloat2("World size", game_settings.world_size.data_);

            if (ImGui::Button("Reset"))
                game->reset(game_settings);

            ImGui::End();
        }

        double cur_time = glfwGetTime();
        float elapsed_time = static_cast<float>(std::min(cur_time - last_time, 1.0));
        last_time = cur_time;
        game->update(ImGui::GetIO(), elapsed_time);

        ImDrawList* bg_drawlist = ImGui::GetBackgroundDrawList();
        game->draw(ImGui::GetIO(), *bg_drawlist);

        // Rendering
        gl_helper.render();   
    }
    
    return 0;
}
