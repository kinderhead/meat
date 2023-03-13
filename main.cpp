#include <iostream>
#include "centurion.hpp"

int main(int, char**) {
    const cen::sdl sdl;
    const cen::img img;
    const cen::mix mix;
    const cen::ttf ttf;
    
    cen::window window;
    cen::renderer renderer = window.make_renderer();
    
    window.show();
}
