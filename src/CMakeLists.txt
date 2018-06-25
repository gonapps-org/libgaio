add_library(gaio SHARED gaio.c)
set_target_properties(gaio PROPERTIES VERSION 0.1.0
                                      SOVERSION 0.1
                                      PUBLIC_HEADER "gaio.h")
install(TARGETS gaio 
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include)
