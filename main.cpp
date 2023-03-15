#include <iostream>
#include "centurion.hpp"

int main(int, char**) {
    const cen::sdl sdl;
    const cen::img img;
    const cen::mix mix;
    const cen::ttf ttf;
    
    cen::window window("Atmosphere", cen::iarea{});
    cen::renderer renderer = window.make_renderer();

    const cen::font font32{"res/Roboto-Regular.ttf", 32};
    auto text = renderer.make_texture(font32.render_blended("Hello world!", cen::colors::white));

    window.show();

    bool running = true;
    cen::event_handler handler;
    while (running) {
        while (handler.poll()) {
            if (handler.is(cen::event_type::quit)) {
                running = false;
                break;
            }
        }

        renderer.clear_with(cen::colors::black);

        renderer.render(text, cen::fpoint{5, 5});

        renderer.present();
    }
}
