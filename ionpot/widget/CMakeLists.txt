add_library(ionpot_widget box.cpp text.cpp texture.cpp)

target_include_directories(ionpot_widget PUBLIC "${PROJECT_SOURCE_DIR}/ionpot")

target_link_libraries(ionpot_widget PUBLIC ionpot_util ionpot_sdl)
