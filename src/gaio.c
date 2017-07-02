#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>
#include <libgenc/genc_generic.h>
#include "gaio.h"

int gaio_Nop_read(union genc_Generic object, void* buffer, int readSize) {
    return 0;
}

int gaio_Nop_write(union genc_Generic object, void* buffer, int writeSize) {
    return 0;
}

int gaio_Nop_fcntl(union genc_Generic object, int command, int argCount, ...) {
    return 0;
}

int gaio_Nop_close(union genc_Generic object) {
    return 0;
}

int gaio_FdPointer_read(union genc_Generic object, void* buffer, int readSize) {
    return read(*((int*)object.pointer), buffer, readSize);
}

int gaio_FdPointer_write(union genc_Generic object, void* buffer, int writeSize) {
    return write(*((int*)object.pointer), buffer, writeSize);
}

int gaio_FdPointer_fcntl(union genc_Generic object, int command, int argCount, ...) {
    va_list args;
    va_start(args, argCount);
    int returnValue = fcntl(*((int*)object.pointer), command, argCount, args);
    va_end(args);
    return returnValue;
}

int gaio_FdPointer_close(union genc_Generic object) {
    int returnValue = close(*((int*)object.pointer));
    *((int*)object.pointer) = -1;
    return returnValue;
}
