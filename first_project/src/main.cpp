// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "gl_helper.h"

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

    Vect screen_pos{30, 30};
    ImVec2 x{30, 30};
    float screen_radius{30};
    ImColor col {0, 255, 255};
    ImVec2 y{100, 100};

    // Main loop
    while (!gl_helper.is_window_should_close())
    {
        gl_helper.cycle();
        x.x += 1;
        y.x += 1;
        ImDrawList* bg_drawlist = ImGui::GetBackgroundDrawList();
        bg_drawlist->AddCircleFilled(x, screen_radius, col);
        bg_drawlist->AddText(y, col, "Level:");

        // Rendering
        gl_helper.render();   
    }
    
    return 0;
}
