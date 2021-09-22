# Generated from qtquickcalendar.pro.

cmake_minimum_required(VERSION 3.16)

include(.cmake.conf)
project(quickcalendar
    VERSION "${QT_REPO_MODULE_VERSION}"
    DESCRIPTION "Qt Quick Calendar Library"
    HOMEPAGE_URL "https://marketplace.qt.io/products/qt-quick-calendar"
    LANGUAGES CXX C
)

find_package(Qt6 ${PROJECT_VERSION} CONFIG REQUIRED COMPONENTS BuildInternals Core QuickControls2 QuickTemplates2)

find_package(Qt6 ${PROJECT_VERSION} CONFIG OPTIONAL_COMPONENTS
    # Needed when building examples in-tree
    Sql
    # Needed for tests
    QuickTest
)

if(NOT TARGET Qt::QuickControls2)
    message(NOTICE "Skipping the build as the condition \"TARGET Qt::QuickControls2\" is not met.")
    return()
endif()
qt_build_repo()
