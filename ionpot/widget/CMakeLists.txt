add_library(ionpot_widget border.cpp box.cpp element.cpp label_value.cpp mouse.cpp padding.cpp solid_box.cpp sum_sizes.cpp text.cpp texture.cpp)

target_include_directories(ionpot_widget PUBLIC "${PROJECT_SOURCE_DIR}/ionpot")

target_link_libraries(ionpot_widget PUBLIC ionpot_util ionpot_sdl)
