cmake_minimum_required(VERSION 3.5)

project(AccountManagement VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Sql Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Sql Core REQUIRED)

add_subdirectory(AMCore)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/AMCore
                    ${CMAKE_CURRENT_SOURCE_DIR}/ui)

set(project_sources ui/MainWindow.cpp ui/QCreateAccount.cpp ui/QLoginWidget.cpp ui/QHomeWidget.cpp main.cpp)
set(project_headers ui/MainWindow.h ui/QCreateAccount.h ui/QLoginWidget.h ui/QHomeWidget.h)
set(project_ui ui/mainwindow.ui ui/qcreateaccount.ui ui/qloginwidget.ui ui/qhomewidget.ui)

# wrap the ui file to a c++ header
qt5_wrap_ui(ui_wrap ${project_ui})
qt5_wrap_cpp(moc_sources ${project_headers})

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(AccountManagement
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET AccountManagement APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(AccountManagement SHARED
            ${project_sources}
            ${project_headers}
            ${ui_wrap}
            ${moc_sources}
        )
    # Define properties for Android with Qt 5 after find_package() calls as:
    #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
else()
    add_executable(AccountManagement
        ${project_sources}
        ${project_headers}
        ${ui_wrap}
        ${moc_sources}
    )
endif()
endif()

target_link_libraries(AccountManagement PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core amcore)

set_target_properties(AccountManagement PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(AccountManagement)
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
