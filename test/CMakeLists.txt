add_executable(gaio_test gaio_test.c)
set_target_properties(gaio_test PROPERTIES C_STANDARD 11)
target_link_libraries(gaio_test gaio cmocka)
add_test(NAME gaio_test COMMAND gaio_test)
