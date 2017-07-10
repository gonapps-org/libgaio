#ifndef _GAIO_H
#define _GAIO_H

#include <libgenc/genc_generic.h>

struct gaio_Io {
    union genc_Generic object;
    int (*read)(struct gaio_Io*, void*, int);
    int (*write)(struct gaio_Io*, void*, int);
    int (*sendfile)(struct gaio_Io*, struct gaio_Io*, int*, int);
    int (*fcntl)(struct gaio_Io*, int, int, ...);
    int (*fileno)(struct gaio_Io*);
    int (*close)(struct gaio_Io*);
};


int gaio_Nop_read(struct gaio_Io* io, void* buffer, int readSize);
int gaio_Nop_write(struct gaio_Io* io, void* buffer, int readSize);
int gaio_Nop_sendfile(struct gaio_Io* outIo, struct gaio_Io* inIo, int* offset, int count);
int gaio_Nop_fcntl(struct gaio_Io* io, int command, int argCount, ...);
int gaio_Nop_fileno(struct gaio_Io* io);
int gaio_Nop_close(struct gaio_Io* io);

#define GAIO_NOP_INIT(io)           \
(io)->read = gaio_Nop_read;         \
(io)->write = gaio_Nop_write;       \
(io)->sendfile = gaio_Nop_sendfile; \
(io)->fcntl = gaio_Nop_fcntl;       \
(io)->fileno = gaio_Nop_fileno;     \
(io)->close = gaio_Nop_close

int gaio_FdPointer_read(struct gaio_Io* io, void* buffer, int readSize);
int gaio_FdPointer_write(struct gaio_Io* io, void* buffer, int writeSize);
int gaio_FdPointer_fcntl(struct gaio_Io* io, int command, int argCount, ...);
int gaio_FdPointer_fileno(struct gaio_Io* io);
int gaio_FdPointer_close(struct gaio_Io* io);

int gaio_Generic_sendfile(struct gaio_Io* outIo, struct gaio_Io* inIo, int* offset, int count);

#endif
