cmake_minimum_required (VERSION 2.6)
project(Image)
set(SRCS
    main.cpp
    utils/pgm3D.cpp
    utils/pgm3D.hpp
)

add_executable(Image ${SRCS})


