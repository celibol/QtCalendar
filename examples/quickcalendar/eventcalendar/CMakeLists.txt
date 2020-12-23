# Generated from eventcalendar.pro.

cmake_minimum_required(VERSION 3.14)
project(eventcalendar LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
  set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/quickcalendar/eventcalendar")

find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS Sql)
find_package(Qt6 COMPONENTS Qml)

qt_add_executable(eventcalendar
    event.h
    eventcalendar.cpp
    eventmodel.cpp eventmodel.h
    sqleventdatabase.cpp sqleventdatabase.h
)
set_target_properties(eventcalendar PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)
target_link_libraries(eventcalendar PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Sql
)


# Resources:
set(qmake_immediate_resource_files
    "MonthGridDelegate.qml"
    "eventcalendar.qml"
    "qtquickcontrols2.conf"
)

qt6_add_resources(eventcalendar "qmake_immediate"
    PREFIX
        "/"
    FILES
        ${qmake_immediate_resource_files}
)

install(TARGETS eventcalendar
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)

set_target_properties(eventcalendar PROPERTIES
    QT_QML_MODULE_VERSION 1.0
    QT_QML_MODULE_URI App
)

qt6_qml_type_registration(eventcalendar)
