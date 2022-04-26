cmake_minimum_required(VERSION 3.5)

file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(amcore SHARED ${HEADERS} ${SOURCES})

target_link_libraries(amcore Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Sql)
