cmake_minimum_required (VERSION 2.6)

project (SnakeGame)

set (CMAKE_C_FLAGS "-Wall -ansi -pedantic")

include_directories (lib/random)
include_directories (lib/position)
include_directories (lib/poison)
include_directories (lib/poisons_list)
include_directories (lib/snake)
include_directories (nc_lib/nc_poisons_list)
include_directories (nc_lib/nc_snake)

add_subdirectory (lib/random)
add_subdirectory (lib/position)
add_subdirectory (lib/poison)
add_subdirectory (lib/poisons_list)
add_subdirectory (lib/snake)
add_subdirectory (nc_lib/nc_poisons_list)
add_subdirectory (nc_lib/nc_snake)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable (SnakeGame main.c)
target_link_libraries(SnakeGame ${CURSES_LIBRARIES} Random Position Poison NCPoisonsList Snake NCSnake)

#add_executable (test_position test_position.c)
#target_link_libraries(test_position Position)

#add_executable (test_poison test_poison.c)
#target_link_libraries(test_poison Poison)

#add_executable (test_poisons_list test_poisons_list.c)
#target_link_libraries(test_poisons_list PoisonsList)

#add_executable (test_snake test_snake.c)
#target_link_libraries(test_snake Snake)
