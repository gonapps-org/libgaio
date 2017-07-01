#include <unistd.h>
#include <libgon_c/gon_c_generic.h>
#include "gaio.h"

int gaio_nop_read(union gon_c_Generic object, void* buffer, int readSize) {
    return 0;
}

int gaio_nop_write(union gon_c_Generic object, void* buffer, int writeSize) {
    return 0;
}

int gaio_nop_close(union gon_c_Generic object) {
    return 0;
}

int gaio_linux_read(union gon_c_Generic object, void* buffer, int readSize) {
    return read(*((int*)object.pointer), buffer, readSize);
}

int gaio_linux_write(union gon_c_Generic object, void* buffer, int writeSize) {
    return write(*((int*)object.pointer), buffer, writeSize);
}

int gaio_linux_close(union gon_c_Generic object) {
    int returnValue = close(*((int*)object.pointer));
    *((int*)object.pointer) = -1;
    return returnValue;
}
