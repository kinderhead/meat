cmake_minimum_required(VERSION 3.0.0)
project(meat VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)

add_executable(meat main.cpp)
target_include_directories(meat PUBLIC include)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_image_INCLUDE_DIRS})
include_directories(${SDL2_ttf_INCLUDE_DIRS})
include_directories(${SDL2_mixer_INCLUDE_DIRS})
target_link_libraries(meat PRIVATE SDL2 SDL2_image SDL2_ttf SDL2_mixer)

# set_target_properties(
#     meat
#     PROPERTIES
#     LINK_FLAGS
#     "-O2 -s USE_SDL=2 -s USE_WEBGL2=1"
# )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
