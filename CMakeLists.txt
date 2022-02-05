cmake_minimum_required(VERSION 3.10)
project(client-prototype)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6Widgets REQUIRED)
find_package(Qt6Quick REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(${CMAKE_BINARY_DIR})

add_executable(client-prototype
        main.cpp
        cavokeclientcontroller.cpp
        cavokeclientmodel.cpp
        cavokeclientview.cpp
        cavokeqmlgamemodel.cpp
        tictactoelogic.cpp
        )

target_link_libraries(client-prototype Qt6::Widgets)
target_link_libraries(client-prototype Qt6::Quick)
