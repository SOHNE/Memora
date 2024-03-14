cmake_minimum_required(VERSION 3.15)
project(Memora
    VERSION 0.0.1
    DESCRIPTION "A simple Memory Management"
    LANGUAGES C
)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Configuration options
option(MEMORA_BUILD_UNIT_TESTS "Build the Memora unit tests" OFF)
option(MEMORA_BUILD_TESTBED "Build the Memora testbed" ON)
option(BUILD_SHARED_LIBS "Build Memora as a shared library" OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

include(GNUInstallDirs)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(src)

if (MEMORA_BUILD_UNIT_TESTS)
    #add_subdirectory(unit-test)
endif()

if (MEMORA_BUILD_TESTBED)
    add_subdirectory(testbed)
endif()

install(
        DIRECTORY "${CMAKE_SOURCE_DIR}/include/memora"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)


