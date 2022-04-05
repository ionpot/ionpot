add_library(ionpot_sdl base.cpp event.cpp events.cpp font.cpp img.cpp key.cpp mouse.cpp point_in_rect.cpp renderer.cpp rwops.cpp surface.cpp texture.cpp to.cpp ttf.cpp version.cpp video.cpp window.cpp)

# to include <util/...>
target_include_directories(ionpot_sdl PUBLIC "${PROJECT_SOURCE_DIR}/ionpot")

target_link_libraries(ionpot_sdl PUBLIC ionpot_util)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# SDL2 lib
find_package(SDL2 REQUIRED)
target_include_directories(ionpot_sdl PUBLIC "${SDL2_INCLUDE_DIRS}")
target_link_libraries(ionpot_sdl PUBLIC "${SDL2_LIBRARIES}")

# SDL2_image lib
find_package(SDL2_image REQUIRED)
target_include_directories(ionpot_sdl PUBLIC "${SDL2_IMAGE_INCLUDE_DIRS}")
target_link_libraries(ionpot_sdl PUBLIC "${SDL2_IMAGE_LIBRARIES}")

# SDL2_ttf lib
find_package(SDL2_ttf REQUIRED)
target_include_directories(ionpot_sdl PUBLIC "${SDL2_TTF_INCLUDE_DIRS}")
target_link_libraries(ionpot_sdl PUBLIC "${SDL2_TTF_LIBRARIES}")
