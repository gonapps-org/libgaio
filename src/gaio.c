#include <sys/stat.h>
#include <stdarg.h>
#include <sys/sendfile.h>
#include <unistd.h>
#include <libgenc/genc_Generic.h>
#include "gaio.h"

int gaio_Nop_read(struct gaio_Io* io, void* buffer, int readSize) {
    return 0;
}

int gaio_Nop_write(struct gaio_Io* io, void* buffer, int writeSize) {
    return 0;
}

int gaio_Nop_sendfile(struct gaio_Io* outIo, struct gaio_Io* inIo, off_t* offset, int count) {
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

int gaio_Fd_fstat(struct gaio_Io* io, struct stat* statBuffer) {
    return fstat(io->object.integer, statBuffer);
}

int gaio_Fd_fileno(struct gaio_Io* io) {
    return io->object.integer;
}

int gaio_Fd_close(struct gaio_Io* io) {
    return close(io->object.integer);
}

int gaio_Generic_sendfile(struct gaio_Io* outIo, struct gaio_Io* inIo, off_t* offset, int count) {
    return sendfile(outIo->methods->fileno(outIo), inIo->methods->fileno(inIo), offset, count);
}

