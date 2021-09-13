cmake_minimum_required(VERSION 3.14)

project(Qt-task-1 LANGUAGES CXX)

add_subdirectory(polarFuncLib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6Widgets)
find_package(Qt6Core)

#find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
#find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

set(MAIN_SOURCES main.cpp
    polargraphwindow.cpp polargraphwindow.h
    datapaneldialog.h datapaneldialog.cpp)

set(MAIN_FORMS
    PolarGraphWindow.ui
    DataPanelDialog.ui)
#QT6_WRAP_CPP(MAIN_HEADERS_MOC ${MAIN_HEADERS})
#QT6_WRAP_UI(MAIN_FORMS_MOC ${MAIN_FORMS})

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} polarFuncLib/)
add_executable(Qt-task-1 WIN32
  ${MAIN_SOURCES}
  ${MAIN_FORMS}
)
target_link_libraries(Qt-task-1 Qt6::Core Qt6::Widgets)
target_link_libraries(Qt-task-1 PolarFuncLib)
