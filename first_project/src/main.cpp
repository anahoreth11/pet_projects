// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "gl_helper.h"
#include "snake.h"

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
    
    Game * game = new Snake();
    // Main loop
    double last_time = glfwGetTime();
    while (!gl_helper.is_window_should_close())
    {
        gl_helper.cycle();

        double cur_time = glfwGetTime();
        float elapsed_time = static_cast<float>(std::min(cur_time - last_time, 1.0));
        last_time = cur_time;
        game->update(gl_helper.get_io(), elapsed_time);

        ImDrawList* bg_drawlist = ImGui::GetBackgroundDrawList();
        game->draw(gl_helper.get_io(), *bg_drawlist);

        // Rendering
        gl_helper.render();   
    }
    
    return 0;
}
