#include <unistd.h>
#include "gaio.h"

int gaio_linux_read(struct gaio_Io io, void* buffer, int readSize) {
    return read(*((int*)io.object.pointer), buffer, readSize);
}

int gaio_linux_write(struct gaio_Io io, void* buffer, int writeSize) {
    return write(*((int*)io.object.pointer), buffer, writeSize);
}

int gaio_linux_close(struct gaio_Io io) {
    int returnValue = close(*((int*)io.object.pointer));
    *((int*)io.object.pointer) = -1;
    return returnValue;
}
