#ifndef _GAIO_H
#define _GAIO_H

#include <libgenc/genc_generic.h>

struct gaio_Io {
    union genc_Generic object;
    int (*read)(struct gaio_Io*, void*, int);
    int (*write)(struct gaio_Io*, void*, int);
    int (*fcntl)(struct gaio_Io*, int, int, ...);
    int (*close)(struct gaio_Io*);
};

int gaio_Nop_read(struct gaio_Io* io, void* buffer, int readSize);
int gaio_Nop_write(struct gaio_Io* io, void* buffer, int readSize);
int gaio_Nop_fcntl(struct gaio_Io* io, int command, int argCount, ...);
int gaio_Nop_close(struct gaio_Io* io);

int gaio_FdPointer_read(struct gaio_Io* io, void* buffer, int readSize);
int gaio_FdPointer_write(struct gaio_Io* io, void* buffer, int writeSize);
int gaio_FdPointer_fcntl(struct gaio_Io* io, int command, int argCount, ...);
int gaio_FdPointer_close(struct gaio_Io* io);

#endif
