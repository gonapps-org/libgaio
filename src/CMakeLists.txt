add_library(gaio SHARED)

target_sources(gaio PRIVATE gaio.c)
target_compile_options(gaio PRIVATE -Wall)
set_target_properties(
    gaio
    PROPERTIES
    C_STANDARD 11
    VERSION ${version}
    SOVERSION ${soversion}
    PUBLIC_HEADER "gaio.h"
)

install(
    TARGETS gaio
    EXPORT gaio-targets
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)

install(
    EXPORT gaio-targets
    NAMESPACE gaio::
    FILE gaio-config.cmake
    DESTINATION lib/cmake/gaio
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    gaio-config-version.cmake
    VERSION ${version}
    COMPATIBILITY SameMinorVersion
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/gaio-config-version.cmake DESTINATION lib/cmake/gaio)
