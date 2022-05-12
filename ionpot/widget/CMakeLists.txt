add_library(ionpot_widget border.cpp box.cpp click.cpp element.cpp hover.cpp padding.cpp solid_box.cpp text.cpp text_box.cpp texture.cpp)

target_include_directories(ionpot_widget PUBLIC "${PROJECT_SOURCE_DIR}/ionpot")

target_link_libraries(ionpot_widget PUBLIC ionpot_util ionpot_sdl)
