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
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)
