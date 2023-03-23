cmake_minimum_required(VERSION 3.0.0)
project(meat VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()

find_package(sdl2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)
find_package(sdl2-mixer CONFIG REQUIRED)

add_executable(meat main.cpp)
target_include_directories(meat PUBLIC include)
target_link_libraries(meat PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2_image SDL2::SDL2_ttf SDL2::SDL2_mixer)

# set_target_properties(
#     meat
#     PROPERTIES
#     LINK_FLAGS
#     "-O2 -s USE_SDL=2 -s USE_WEBGL2=1"
# )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
