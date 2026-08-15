cmake_minimum_required(VERSION 3.16)

project(TimeCalculatorGui VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(TimeCalculatorGui
    main.cpp
    MainWindow.cpp
    MainWindow.h
    ../TimeCalculator/Date.cpp
    ../TimeCalculator/Time.cpp
    ../TimeCalculator/DateTime.cpp
)

target_include_directories(TimeCalculatorGui PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../TimeCalculator
)

target_link_libraries(TimeCalculatorGui PRIVATE Qt6::Widgets)
