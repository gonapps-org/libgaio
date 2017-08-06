add_executable(gaio_test gaio_test.c)
target_link_libraries(gaio_test gaio)
add_test(NAME gaio_test COMMAND gaio_test)
