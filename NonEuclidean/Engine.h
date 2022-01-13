#pragma once
#include "GameHeader.h"
#include "Camera.h"
#include "Input.h"
#include "Object.h"
#include "Portal.h"
#include "Player.h"
#include "Scene.h"
#include "Sky.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>

class Engine {
public:
  Engine();
  ~Engine();

  int Run();
  void Update();
  void Render(const Camera& cam, GLuint curFBO, const Portal* skipPortal);
  void LoadScene(int ix);

  const Player& GetPlayer() const { return *player; }
  float NearestPortalDist() const;

private:
  void CreateGLWindow();
  void InitGLObjects();
  void DestroyGLObjects();
  void SetupInputs();
  void ConfineCursor();
  void ToggleFullscreen();

  // HDC   hDC;           // device context
  // HGLRC hRC;				   // opengl context
  // HWND  hWnd;				   // window
  GLFWwindow* hWindow;
  // HINSTANCE hInstance; // process id

  unsigned long iWidth;         // window width
  unsigned long iHeight;        // window height
  bool isFullscreen;   // fullscreen state

  Camera main_cam;
  Input input;
  // Timer timer;

  std::vector<std::shared_ptr<Object>> vObjects;
  std::vector<std::shared_ptr<Portal>> vPortals;
  std::shared_ptr<Sky> sky;
  std::shared_ptr<Player> player;

  GLint occlusionCullingSupported;

  std::vector<std::shared_ptr<Scene>> vScenes;
  std::shared_ptr<Scene> curScene;
};
