#pragma once


#include "base.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>

#include <glad/gl.h>
#include <GLFW/glfw3.h>


class GLHelper
{
public:
    GLHelper();
    ~GLHelper();
    bool init();

    bool is_window_should_close();
    void render();
    void cycle();
private:
    GLFWwindow* _window;
    int _display_w, _display_h;
    ImVec4 _clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};