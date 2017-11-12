find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_library (NCPoisonsList nc_poisons_list.h nc_poisons_list.c)
target_link_libraries(NCPoisonsList ${CURSES_LIBRARIES} Position Poison PoisonsList)
