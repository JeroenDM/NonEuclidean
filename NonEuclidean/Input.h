#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

struct tagRAWINPUT;
class Input {
 public:
  Input();

  void EndFrame();
  void UpdateRaw(const tagRAWINPUT* raw);

  bool isKeyPressed(GLFWwindow* window, int key);

  // Keyboard
  bool key[256];
  bool key_press[256];

  // Mouse
  bool mouse_button[3];
  bool mouse_button_press[3];
  float mouse_dx;
  float mouse_dy;
  float mouse_ddx;
  float mouse_ddy;

  // Joystick
  // TODO:

  // Bindings
  // TODO:

  // Calibration
  // TODO:
};
