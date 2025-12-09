#include "window.hpp"
#include <SDL3/SDL.h>

Window::Window(const char *title, int w, int h) {
  running_ = true;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(title, w, h, 0, &window_, &renderer_);
}

Window::~Window() {
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

bool Window::isRunning() { return running_; }
void Window::stopRunning() { running_ = false; }

bool Window::poll_event(SDL_Event &e) { return SDL_PollEvent(&e); }

void Window::clear(float r, float g, float b, float a) {
  SDL_SetRenderDrawColor(renderer_, Uint8(r * 255), Uint8(g * 255),
                         Uint8(b * 255), Uint8(a * 255));
  SDL_RenderClear(renderer_);
}

void Window::present() { SDL_RenderPresent(renderer_); }
