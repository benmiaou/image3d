cmake_minimum_required (VERSION 2.6)
project(Image)

find_package(OpenGL REQUIRED)
find_package(Qt4 REQUIRED QtCore QtOpenGL QtGui QtXml)
include(${QT_USE_FILE})

set(SRCS
    main.cpp
    utils/pgm3D.cpp
    utils/pgm3D.hpp
utils/voxel.cpp
utils/voxel.hpp
utils/point.cpp
utils/point.hpp
utils/quad.cpp
utils/quad.hpp
visu/myWindow.cpp
visu/myWindow.hpp
visu/myGLWidget.cpp
visu/myGLWidget.hpp
)

add_executable(Image ${SRCS} ${OPENGL_LIBRARIES} ${QT_LIBRARIES})


