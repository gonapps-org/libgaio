#ifndef _GAIO_H
#define _GAIO_H

#include <libgon_c/gon_c_generic.h>

struct gaio_Io {
    union gon_c_Generic object;
    int (*read)(union gon_c_Generic, void*, int);
    int (*write)(union gon_c_Generic, void*, int);
    int (*close)(union gon_c_Generic, void*);
};

int gaio_linux_read(struct gaio_Io io, void* buffer, int readSize);
int gaio_linux_write(struct gaio_Io io, void* buffer, int writeSize);
int gaio_linux_close(struct gaio_Io io);

#endif
