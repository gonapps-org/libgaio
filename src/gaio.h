#ifndef _GAIO_H
#define _GAIO_H

#include <libgon_c/gon_c_generic.h>

struct gaio_Io {
    union gon_c_Generic object;
    int (*read)(union gon_c_Generic, void*, int);
    int (*write)(union gon_c_Generic, void*, int);
    int (*close)(union gon_c_Generic);
};

int gaio_nop_read(union gon_c_Generic object, void* buffer, int readSize);
int gaio_nop_write(union gon_c_Generic object, void* buffer, int readSize);
int gaio_nop_close(union gon_c_Generic object);

int gaio_linux_read(union gon_c_Generic object, void* buffer, int readSize);
int gaio_linux_write(union gon_c_Generic object, void* buffer, int writeSize);
int gaio_linux_close(union gon_c_Generic object);

#endif
