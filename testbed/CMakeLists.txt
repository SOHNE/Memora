set(TESTBED_SOURCE_FILES
    main.c
)

set(TESTBED_HEADER_FILES

    )

add_executable(testbed)
target_sources(testbed PRIVATE ${TESTBED_SOURCE_FILES} ${TESTBED_HEADER_FILES})
target_include_directories(testbed PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(testbed PUBLIC memora)

set_target_properties(testbed PROPERTIES
    C_STANDARD 17
    C_EXTENSIONS ON
)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set( CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" )
    set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT ${CMAKE_PROJECT_NAME} )
    set_property( TARGET testbed PROPERTY WIN32_EXECUTABLE true )

    target_link_options(testbed PUBLIC -static -static-libgcc -static-libstdc++)

endif ()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${TESTBED_SOURCE_FILES} ${TESTBED_HEADER_FILES})

