#pragma once

#include <string>

#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>


struct Window_Data
{
  unsigned int screen_width  = 0;
  unsigned int screen_height = 0;

  std::string  title         = "";
  GLFWwindow  *window        = nullptr; 
};

void glfw_setup               (Window_Data *wd);
void glfw_setup_callbacks     (Window_Data *wd);
void glfw_handle_input        ();
void glfw_cleanup             (Window_Data *wd);
bool glfw_window_should_close (GLFWwindow *w);
void glfw_swap_buffers        (GLFWwindow *w);
void key_callback             (GLFWwindow *window, int key, int scan_code, int action, int mode);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
