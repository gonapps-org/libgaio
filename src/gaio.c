#include <fcntl.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <sys/sendfile.h>
#include <unistd.h>
#include <libgenc/genc_generic.h>
#include "gaio.h"

int gaio_Nop_read(struct gaio_Io* io, void* buffer, int readSize) {
    return 0;
}

int gaio_Nop_write(struct gaio_Io* io, void* buffer, int writeSize) {
    return 0;
}

int gaio_Nop_sendfile(struct gaio_Io* outIo, struct gaio_Io* inIo, int* offset, int count) {
    return 0;
}

int gaio_Nop_fcntl(struct gaio_Io* io, int command, int argCount, ...) {
    return 0;
}

int gaio_Nop_fstat(struct gaio_Io* io, struct stat* statBuffer) {
    return 0;
}

int gaio_Nop_fileno(struct gaio_Io* io) {
    return -1;
}

int gaio_Nop_close(struct gaio_Io* io) {
    return 0;
}


int gaio_Fd_read(struct gaio_Io* io, void* buffer, int readSize) {
    return read(io->object.integer, buffer, readSize);
}

int gaio_Fd_write(struct gaio_Io* io, void* buffer, int writeSize) {
    return write(io->object.integer, buffer, writeSize);
}

int gaio_Fd_fcntl(struct gaio_Io* io, int command, int argCount, ...) {
    va_list args;
    va_start(args, argCount);
    int returnValue = fcntl(io->object.integer, command, argCount, args);
    va_end(args);
    return returnValue;
}

int gaio_Fd_fstat(struct gaio_Io* io, struct stat* statBuffer) {
    return fstat(io->object.integer, statBuffer);
}

int gaio_Fd_fileno(struct gaio_Io* io) {
    return io->object.integer;
}

int gaio_Fd_close(struct gaio_Io* io) {
    return close(io->object.integer);
}

int gaio_Generic_sendfile(struct gaio_Io* outIo, struct gaio_Io* inIo, int* offset, int count) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
    return sendfile(outIo->methods->fileno(outIo), inIo->methods->fileno(inIo), offset, count);
#pragma GCC diagnostic pop
}

