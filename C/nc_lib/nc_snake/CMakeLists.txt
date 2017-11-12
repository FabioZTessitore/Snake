find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_library (NCSnake nc_snake.h nc_snake.c)
target_link_libraries(NCSnake ${CURSES_LIBRARIES} Snake)
