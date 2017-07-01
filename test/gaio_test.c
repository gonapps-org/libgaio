#include <gaio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    struct gaio_Io io;
    int fd = STDOUT_FILENO;
    io.object.pointer = &fd;
    char* buf = "HELLO WORLD!\n";
    io.read = gaio_nop_read;
    io.write = gaio_linux_write;
    io.write(io.object, buf, sizeof("HELLO WORLD!\n") - 1);
    io.close = gaio_nop_close;
    io.close(io.object);
};
