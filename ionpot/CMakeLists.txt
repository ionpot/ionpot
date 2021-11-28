set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC"
OR "${CMAKE_CXX_SIMULATE_ID}" STREQUAL "MSVC")
	# /W4 -> warning level 4
	# /WX -> warnings are errors
	# /we4062 -> enable warning C4062 as an error
	add_compile_options(/W4 /WX /we4062)
else()
	add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# subdirectories
add_subdirectory(util)
add_subdirectory(sdl)

# use the library with <ionpot/...> include syntax
add_library(ionpot INTERFACE)
target_include_directories(ionpot INTERFACE "${PROJECT_SOURCE_DIR}")
target_link_libraries(ionpot INTERFACE ionpot_util ionpot_sdl)
