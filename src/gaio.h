#ifndef _GAIO_H
#define _GAIO_H

#include <sys/stat.h>
#include <libgenc/genc_generic.h>

struct gaio_Io {
    union genc_Generic object;
    struct gaio_Io_Callbacks* callbacks;
};

struct gaio_Io_Callbacks {
    int (*read)(struct gaio_Io*, void*, int);
    int (*write)(struct gaio_Io*, void*, int);
    int (*sendfile)(struct gaio_Io*, struct gaio_Io*, int*, int);
    int (*fcntl)(struct gaio_Io*, int, int, ...);
    int (*fstat)(struct gaio_Io*, struct stat* statBuffer);
    int (*fileno)(struct gaio_Io*);
    int (*close)(struct gaio_Io*);
};

int gaio_Nop_read(struct gaio_Io* io, void* buffer, int readSize);
int gaio_Nop_write(struct gaio_Io* io, void* buffer, int readSize);
int gaio_Nop_sendfile(struct gaio_Io* outIo, struct gaio_Io* inIo, int* offset, int count);
int gaio_Nop_fcntl(struct gaio_Io* io, int command, int argCount, ...);
int gaio_Nop_fstat(struct gaio_Io* io, struct stat* statBuffer);
int gaio_Nop_fileno(struct gaio_Io* io);
int gaio_Nop_close(struct gaio_Io* io);

#define GAIO_NOP_INIT(callbacks)           \
(callbacks)->read = gaio_Nop_read;         \
(callbacks)->write = gaio_Nop_write;       \
(callbacks)->sendfile = gaio_Nop_sendfile; \
(callbacks)->fcntl = gaio_Nop_fcntl;       \
(callbacks)->fstat = gaio_Nop_fstat;       \
(callbacks)->fileno = gaio_Nop_fileno;     \
(callbacks)->close = gaio_Nop_close

int gaio_Fd_read(struct gaio_Io* io, void* buffer, int readSize);
int gaio_Fd_write(struct gaio_Io* io, void* buffer, int writeSize);
int gaio_Fd_fcntl(struct gaio_Io* io, int command, int argCount, ...);
int gaio_Fd_fstat(struct gaio_Io* io, struct stat* statBuffer);
int gaio_Fd_fileno(struct gaio_Io* io);
int gaio_Fd_close(struct gaio_Io* io);

int gaio_Generic_sendfile(struct gaio_Io* outIo, struct gaio_Io* inIo, int* offset, int count);

#endif
