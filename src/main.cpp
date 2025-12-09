#include "circle.hpp"
#include "constants.hpp"
#include "window.hpp"

int main(int, char **) {
  Window win("physics-engine - SDL3", WINDOW_WIDTH, WINDOW_HEIGHT);

  Uint64 last_time = SDL_GetTicks();
  float dt = 0;

  SDL_Event e;

  float r = 225, g = 225, b = 225;

  Circle circle(100, 100, 50, 0, 50, 1, Uint8(255));

  while (win.isRunning()) {
    Uint64 current_time = SDL_GetTicks();
    dt = static_cast<float>(current_time - last_time) / 1000.0f;
    last_time = current_time;

    while (win.poll_event(e)) {
      if (e.type == SDL_EVENT_QUIT)
        win.stopRunning();
    }

    win.clear(r, g, b, 1.0f);

    circle.update(dt);

    circle.draw(win.renderer_);

    win.present();
  }
  return 0;
}
