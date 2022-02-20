#include <iostream>
#include <string>

#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <cstdio>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glfw_window.h"

  
void
glad_setup()
{
  if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
      std::cout << "Failed to initialize GLAD" << std::endl;
    }
}

void
opengl_config_setup(Window_Data *wd)
{
  glViewport(0,0, wd->screen_width, wd->screen_height);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

int 
main()
{
    std::cout << "Hello, World!" << std::endl;

    Window_Data wd = { 1500, 844, "Hello World", nullptr };

    glfw_setup(&wd);
    glad_setup();

    glfw_setup_callbacks(&wd);

    opengl_config_setup(&wd);

    // Loop

    while(!glfw_window_should_close(wd.window))
      {
	glfw_handle_input();

	// draw
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
		
	glfw_swap_buffers(wd.window);
      }
    
    
    glfw_cleanup(&wd);
    
    return 0;

}
