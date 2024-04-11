cmake_minimum_required(VERSION 3.16)

project(helloworld VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
qt_standard_project_setup()

qt_add_executable(test
    src/chat_item.cc
    test/main.cc
    test/mainwindow.cc
)

target_link_libraries(test PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
target_include_directories(test PRIVATE src)
