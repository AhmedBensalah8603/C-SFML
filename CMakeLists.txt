cmake_minimum_required(VERSION 3.27)
project(FlappyZiwziw)

include(FetchContent)
set(SFML_STATIC_LIBRARIES TRUE)
FIND_PACKAGE(SFML 2.6.1 COMPONENTS system window graphics audio)
set(CMAKE_CXX_STANDARD 17)


add_executable(FlappyZiwziw
        Dimension.h
        FlappyZiwziw.cpp
        Game.cpp
        Game.h
        Chejra.cpp
        Chejra.h
        Ziwziw.cpp
        Ziwziw.h

)
target_link_libraries(FlappyZiwziw
        sfml-graphics
        sfml-window
        sfml-audio
        sfml-system -static
)
