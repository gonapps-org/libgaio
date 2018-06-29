#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <fcntl.h>
#include "../src/gaio.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

static void gaio_test(void** state) {
    struct gaio_Io io;
    struct gaio_Methods methods;
    GAIO_METHODS_NOP_INIT(&methods);
    io.methods = &methods;
    int fd = STDOUT_FILENO;
    io.object.integer = fd;
    io.methods->write = gaio_Fd_write;
    io.methods->fileno = gaio_Fd_fileno;
    char* buf = "HELLO WORLD!\n";
    assert_int_not_equal(io.methods->write(&io, buf, sizeof("HELLO WORLD!\n") - 1), -1);
    io.methods->sendfile = gaio_Generic_sendfile;
    int self = open(__FILE__, O_RDONLY);
    struct gaio_Io selfIo;
    selfIo.object.integer = self;
    selfIo.methods = &methods;
    assert_int_not_equal(io.methods->sendfile(&io, &selfIo, NULL, 1024), -1);
    io.methods->close = gaio_Nop_close;
    assert_int_equal(io.methods->close(&io), 0);
    assert_int_not_equal(fcntl(io.methods->fileno(&io), F_SETFL, fcntl(io.methods->fileno(&io), F_GETFL, 0) | O_NONBLOCK), -1);
}

int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(gaio_test),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
