project(libgaio)
set(CMAKE_BUILD_TYPE Debug)
add_library(gaio SHARED src/gaio.c)
set_target_properties(gaio PROPERTIES PUBLIC_HEADER "src/gaio.h")
install(TARGETS gaio DESTINATION /usr/local/lib/
	PUBLIC_HEADER DESTINATION /usr/local/include/)
