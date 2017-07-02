#ifndef _GAIO_H
#define _GAIO_H

#include <libgenc/genc_generic.h>

struct gaio_Io {
    union genc_Generic object;
    int (*read)(union genc_Generic, void*, int);
    int (*write)(union genc_Generic, void*, int);
    int (*fcntl)(union genc_Generic, int, int, ...);
    int (*close)(union genc_Generic);
};

int gaio_nop_read(union genc_Generic object, void* buffer, int readSize);
int gaio_nop_write(union genc_Generic object, void* buffer, int readSize);
int gaio_nop_fcntl(union genc_Generic object, int command, int argCount, ...);
int gaio_nop_close(union genc_Generic object);

int gaio_linux_read(union genc_Generic object, void* buffer, int readSize);
int gaio_linux_write(union genc_Generic object, void* buffer, int writeSize);
int gaio_linux_fcntl(union genc_Generic object, int command, int argCount, ...);
int gaio_linux_close(union genc_Generic object);

#endif
