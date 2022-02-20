#include "glfw_window.h"

void
glfw_setup(Window_Data *wd)
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  #ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  #endif

  glfwWindowHint(GLFW_RESIZABLE, false);

  wd->window = glfwCreateWindow(wd->screen_width,
				wd->screen_height, wd->title.c_str(), nullptr, nullptr);
  glfwMakeContextCurrent(wd->window);
  
}

void
glfw_setup_callbacks(Window_Data *wd)
{
  glfwSetKeyCallback(wd->window, key_callback);
  
}

void
glfw_handle_input()
{
  glfwPollEvents();
}

void
glfw_cleanup(Window_Data *w)
{
  glfwTerminate();
}

bool
glfw_window_should_close(GLFWwindow *w)
{
  return glfwWindowShouldClose(w);
}

void
glfw_swap_buffers(GLFWwindow *w)
{
  glfwSwapBuffers(w);
}

void
key_callback(GLFWwindow *window, int key, int scan_code, int action, int mode)
{

  if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}


void
framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
  glViewport(0,0, width, height);
}
