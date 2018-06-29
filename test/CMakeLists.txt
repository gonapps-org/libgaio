add_executable(gaio_test gaio_test.c)
target_link_libraries(gaio_test gaio cmocka)
add_test(NAME gaio_test COMMAND gaio_test  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
