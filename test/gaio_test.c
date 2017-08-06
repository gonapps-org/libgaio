#include <fcntl.h>
#include <gaio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    struct gaio_Io io;
    struct gaio_Io_Methods methods;
    GAIO_NOP_INIT(&methods);
    io.methods = &methods;
    int fd = STDOUT_FILENO;
    io.object.integer = fd;
    io.methods->write = gaio_Fd_write;
    io.methods->fileno = gaio_Fd_fileno;
    char* buf = "HELLO WORLD!\n";
    io.methods->write(&io, buf, sizeof("HELLO WORLD!\n") - 1);
    io.methods->sendfile = gaio_Generic_sendfile;
    int self = open("gaio_test.c", O_RDONLY);
    struct gaio_Io selfIo;
    selfIo.object.pointer = &self;
    selfIo.methods = &methods;
    io.methods->sendfile(&io, &selfIo, NULL, 1024);
    io.methods->close = gaio_Nop_close;
    io.methods->close(&io);
    io.methods->fcntl = gaio_Fd_fcntl;
    io.methods->fcntl(&io, F_SETFL, io.methods->fcntl(&io, F_GETFL, 0) | O_NONBLOCK);
};
