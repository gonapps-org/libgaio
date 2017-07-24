#include <fcntl.h>
#include <gaio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    struct gaio_Io io;
    struct gaio_Io_Callbacks callbacks;
    GAIO_NOP_INIT(&callbacks);
    io.callbacks = &callbacks;
    int fd = STDOUT_FILENO;
    io.object.integer = fd;
    io.callbacks->write = gaio_Fd_write;
    io.callbacks->fileno = gaio_Fd_fileno;
    char* buf = "HELLO WORLD!\n";
    io.callbacks->write(&io, buf, sizeof("HELLO WORLD!\n") - 1);
    io.callbacks->sendfile = gaio_Generic_sendfile;
    int self = open("gaio_test.c", O_RDONLY);
    struct gaio_Io selfIo;
    selfIo.object.pointer = &self;
    selfIo.callbacks = &callbacks;
    io.callbacks->sendfile(&io, &selfIo, NULL, 1024);
    io.callbacks->close = gaio_Nop_close;
    io.callbacks->close(&io);
    io.callbacks->fcntl = gaio_Fd_fcntl;
    io.callbacks->fcntl(&io, F_SETFL, io.callbacks->fcntl(&io, F_GETFL, 0) | O_NONBLOCK);
};
