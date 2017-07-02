#include <fcntl.h>
#include <gaio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    struct gaio_Io io;
    int fd = STDOUT_FILENO;
    io.object.pointer = &fd;
    char* buf = "HELLO WORLD!\n";
    io.read = gaio_Nop_read;
    io.write = gaio_fdPointer_write;
    io.write(io.object, buf, sizeof("HELLO WORLD!\n") - 1);
    io.close = gaio_Nop_close;
    io.close(io.object);
    io.fcntl = gaio_fdPointer_fcntl;
    io.fcntl(io.object, F_SETFL, io.fcntl(io.object, F_GETFL, 0) | O_NONBLOCK);
};
