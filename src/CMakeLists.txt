set(MEMORA_SOURCE_FILES

)

set(MEMORA_HEADER_FILES
    ../include/memora/ma_api.h
)

add_library(memora ${MEMORA_SOURCE_FILES} ${MEMORA_HEADER_FILES})
target_include_directories(memora
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
    $<INSTALL_INTERFACE:include>
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(memora PROPERTIES
    LINKER_LANGUAGE C
    C_STANDARD 20
    C_EXTENSIONS OFF
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

if (BUILD_SHARED_LIBS)
    message(STATUS "Building shared library")
    target_compile_definitions(memora PUBLIC MA_SHARED)
endif()

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "src" FILES ${MEMORA_SOURCE_FILES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/../include" PREFIX "include" FILES ${MEMORA_HEADER_FILES})

install(
    TARGETS memora
    EXPORT memoraConfig
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION include
)

install(
    EXPORT memoraConfig
    NAMESPACE memora::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/memora
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/memoraConfigVersion.cmake"
    COMPATIBILITY AnyNewerVersion
)

install(
    FILES "${CMKAE_CURRENT_BINARY_DIR}/memoraConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/memora
)

