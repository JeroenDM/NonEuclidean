#pragma once
#include <GL/glew.h>

#include "Camera.h"

// Forward declaration
class Portal;

class FrameBuffer {
 public:
  FrameBuffer();

  void Render(const Camera& cam, GLuint curFBO, const Portal* skipPortal);
  void Use();

 private:
  GLuint texId;
  GLuint fbo;
  GLuint renderBuf;
};
