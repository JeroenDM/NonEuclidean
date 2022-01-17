#include <iostream>
#include <cstdlib>

// #include "Engine.h"
#include "GameHeader.h"
#include "Vector.h"
#include "Camera.h"
#include "Mesh.h"
#include "Shader.h"
#include "Resources.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

inline GLFWwindow *hWindow;
inline GLint occlusionCullingSupported;

void CreateGLWindow()
{
  /* Initialize the library */
  if (!glfwInit())
  {
    std::exit(EXIT_FAILURE);
  }

  hWindow = glfwCreateWindow(
      GH_SCREEN_WIDTH,
      GH_SCREEN_HEIGHT,
      "Non Euclidean world",
      NULL,
      NULL);
  if (!hWindow)
  {
    glfwTerminate();
    std::cout << "Failed to create window.\n";
    std::exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(hWindow);
}

void InitGLObjects()
{
  //Initialize extensions
  GLenum err = glewInit();

  if (err != GLEW_OK)
  {
    std::cout << "Failed to initialize glew.\n";
  }

  //Basic global variables
  glClearColor(0.6f, 0.9f, 1.0f, 1.0f);
  // glEnable(GL_CULL_FACE);
  // glCullFace(GL_BACK);
  // glEnable(GL_DEPTH_TEST);
  // glDepthFunc(GL_LESS);
  // glDepthMask(GL_TRUE);

  // //Check GL functionality
  glGetQueryiv(GL_SAMPLES_PASSED_ARB, GL_QUERY_COUNTER_BITS_ARB, &occlusionCullingSupported);
  std::cout << "Occlusion culling supported: " << occlusionCullingSupported << "\n";

  // //Attempt to enalbe vsync (if failure then oh well)
  // glSwapIntervalEXT(1);
}

int main()
{
  //Run the main engine
  // Engine engine;
  // return engine.Run();

  CreateGLWindow();
  InitGLObjects();

  // Mesh mesh("bunny.obj");
  auto mesh = AquireMesh("bunny.obj");
  // auto mesh = AquireMesh("pillar.obj");
  auto shader = AquireShader("emtpy");
  // auto texture = AquireTexture("white.bmp");

  // shader->Use();
  // texture->Use();

  while (!glfwWindowShouldClose(hWindow))
  {
    mesh->Draw();
    glfwSwapBuffers(hWindow);
    glfwPollEvents();
  }
  glfwDestroyWindow(hWindow);
  glfwTerminate();
}
