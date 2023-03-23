#include <iostream>

#define CENTURION_NO_VULKAN
#include "centurion.hpp"

int main(int, char**)
{
    int mousex = 0;
    int mousey = 0;

    try
    {
        const cen::sdl sdl;
        const cen::img img;
        const cen::mix mix;
        const cen::ttf ttf;
        
        cen::window window("Atmosphere", cen::iarea(600, 800));
        cen::renderer renderer = window.make_renderer();

        const cen::font font16{"res/Roboto-Regular.ttf", 16};
        
        auto bg = renderer.make_texture("res/bg.png");

        window.show();

        bool running = true;
        cen::event_handler handler;
        while (running)
        {
            while (handler.poll())
            {
                if (handler.is(cen::event_type::quit))
                {
                    running = false;
                    break;
                }
                else if (const auto* mouse_ev = handler.try_get<cen::mouse_motion_event>())
                {
                    mousex = mouse_ev->x();
                    mousey = mouse_ev->y();
                }
            }

            renderer.clear_with(cen::colors::black);

            renderer.render(bg, cen::irect(0, 0, 600, 800));
            renderer.render(renderer.make_texture(font16.render_blended((std::string("Altitude: ") + std::to_string((800-mousey)*2)).c_str(), cen::colors::white)), cen::ipoint(480, 20));

            renderer.present();
        }
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }

    return 0;
}
