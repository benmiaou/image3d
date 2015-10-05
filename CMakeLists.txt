cmake_minimum_required (VERSION 2.6)
project(Image)

find_package(OpenGL REQUIRED)
find_package(Qt4 REQUIRED QtCore QtOpenGL QtGui QtXml)
include(${QT_USE_FILE})

ADD_DEFINITIONS(-std=c++11 -fpermissive)

set(SRCS
    main.cpp
    utils/Pgm3DLoader.cpp
    utils/Pgm3DLoader.hpp
utils/Voxels.cpp
utils/Voxels.hpp


visu/myGLWidget.cpp
visu/mySlider.cpp

)
set(MYPROJECT_CURRENT_HEADERS

visu/myGLWidget.hpp
visu/mySlider.hpp
)
qt4_wrap_cpp(mocFiles ${MYPROJECT_CURRENT_HEADERS})

add_executable(Image ${SRCS} ${mocFiles} )
target_link_libraries(Image  ${OPENGL_LIBRARIES} ${QT_LIBRARIES})

