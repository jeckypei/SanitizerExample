cmake_minimum_required(VERSION 3.5)
project(poison)

set(INSTALL_DIR ${CMAKE_SOURCE_DIR}/install)

aux_source_directory(. ALL_SRCS)
add_compile_options("-fsanitize=address")
add_compile_options("-g")
link_libraries("-fsanitize=address -g")

#add_executable(poison poison.c)
add_executable(poison ${ALL_SRCS})

INSTALL(TARGETS poison DESTINATION ${INSTALL_DIR}/usr/bin)
