#pragma once
#include <SDL3/SDL.h>

class Window {
private:
  bool running_;

public:
  Window(const char *title, int w, int h);
  ~Window();

  bool isRunning();
  void stopRunning();

  bool poll_event(SDL_Event &e);
  void clear(float r = 0.1f, float g = 0.1f, float b = 0.1f, float a = 1.0f);
  void present();

  SDL_Window *window_ = nullptr;
  SDL_Renderer *renderer_ = nullptr;
};
