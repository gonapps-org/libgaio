#ifndef _GAIO_H
#define _GAIO_H

#include <sys/stat.h>
#include <libgenc/genc_Generic.h>

/**
 * @file gaio.h
 * @author Byeonggon Lee
 * @brief libgaio header file.
 */

/**
 * @brief
 * IO object which contains real object and methods.
 */

struct gaio_Io {
    union genc_Generic object;
    struct gaio_Methods* methods;
};

/**
 * @brief
 * Struct which contains function pointers for IO.
 * @details
 * Each function pointers must point real function address, NULL is not allowed.
 */

struct gaio_Methods {
    int (*read)(struct gaio_Io* io, void* buffer, int readSize);
    int (*write)(struct gaio_Io* io, void*, int writeSize);
    int (*sendfile)(struct gaio_Io* io, struct gaio_Io*, int* offset, int sendSize);
    int (*fcntl)(struct gaio_Io* io, int command, int varArgCount, ...);
    int (*fstat)(struct gaio_Io* io, struct stat* statBuffer);
    int (*fileno)(struct gaio_Io* io);
    int (*close)(struct gaio_Io* io);
};

/**
 * @brief
 * Function that does nothing.
 * @param io
 * Pointer of IO object.
 * @param buffer
 * Pointer of buffer.
 * @param readSize
 * Reading size.
 * @returns Always 0.
 */

int gaio_Nop_read(struct gaio_Io* io, void* buffer, int readSize);

/**
 * @brief
 * Function that does nothing.
 * @param io
 * Pointer of IO object.
 * @param buffer
 * Pointer of buffer.
 * @param writeSize
 * Writing size.
 * @returns Always 0.
 */

int gaio_Nop_write(struct gaio_Io* io, void* buffer, int writeSize);

/**
 * @brief
 * Function that does nothing.
 * @param outIo
 * Pointer of output IO object.
 * @param inIo
 * Pointer of input IO object.
 * @param offset
 * Pointer of input file offset.
 * @param sendSize
 * Sending size.
 * @returns Always 0.
 */

int gaio_Nop_sendfile(struct gaio_Io* outIo, struct gaio_Io* inIo, int* offset, int sendSize);

/**
 * @brief
 * Function that does nothing.
 * @param io
 * Pointer of IO object.
 * @param command
 * fcntl command.
 * @returns Always 0.
 */

int gaio_Nop_fcntl(struct gaio_Io* io, int command, int varArgCount, ...);

/**
 * @brief
 * Function that does nothing.
 * @param io
 * Pointer of IO object.
 * @param statBuffer
 * Pointer of stat.
 * @returns Always 0.
 */

int gaio_Nop_fstat(struct gaio_Io* io, struct stat* statBuffer);

/**
 * @brief
 * Function that does nothing.
 * @param io
 * Pointer of IO object.
 * @returns Always 0.
 */

int gaio_Nop_fileno(struct gaio_Io* io);

/**
 * @brief
 * Function that does nothing.
 * @param io
 * Pointer of IO object.
 * @returns Always -1.
 */

int gaio_Nop_close(struct gaio_Io* io);

/**
 * @brief Initialize IO methods struct with nop functions.
 * @param methods
 * Pointer of struct gaio_Methods.
 */

#define GAIO_METHODS_NOP_INIT(methods)           \
(methods)->read = gaio_Nop_read;         \
(methods)->write = gaio_Nop_write;       \
(methods)->sendfile = gaio_Nop_sendfile; \
(methods)->fcntl = gaio_Nop_fcntl;       \
(methods)->fstat = gaio_Nop_fstat;       \
(methods)->fileno = gaio_Nop_fileno;     \
(methods)->close = gaio_Nop_close

/**
 * @brief
 * Wrapper function for read().
 * @details
 * IO object should be initialize like this:
 * io->object.integer = FILE_DESCRIPTOR
 * @param io
 * Pointer of IO object.
 * @param buffer
 * Pointer of buffer.
 * @param readSize
 * Reading size.
 * @returns What read() returns.
 */

int gaio_Fd_read(struct gaio_Io* io, void* buffer, int readSize);

/**
 * @brief
 * Wrapper function for write().
 * @details
 * IO object should be initialize like this:
 * io->object.integer = FILE_DESCRIPTOR
 * @param io
 * Pointer of IO object.
 * @param buffer
 * Pointer of buffer.
 * @param writeSize
 * Write size.
 * @returns What write() returns.
 */

int gaio_Fd_write(struct gaio_Io* io, void* buffer, int writeSize);

/**
 * @brief
 * Wrapper function for fcntl().
 * @details
 * IO object should be initialize like this:
 * io->object.integer = FILE_DESCRIPTOR
 * @param io
 * Pointer of IO object.
 * @param command
 * fcntl() command.
 * @param varArgCount
 * varArgCount.
 * @returns What fcntl() returns.
 */

int gaio_Fd_fcntl(struct gaio_Io* io, int command, int varArgCount, ...);

/**
 * @brief
 * Wrapper function for fstat().
 * @details
 * IO object should be initialize like this:
 * io->object.integer = FILE_DESCRIPTOR
 * @param io
 * Pointer of IO object.
 * @param statBuffer
 * Pointer of struct stat
 * @returns What fstat() returns.
 */

int gaio_Fd_fstat(struct gaio_Io* io, struct stat* statBuffer);

/**
 * @brief
 * Wrapper function for fileno().
 * @details
 * IO object should be initialize like this:
 * io->object.integer = FILE_DESCRIPTOR
 * @param io
 * Pointer of IO object.
 * @returns What fileno() returns.
 */

int gaio_Fd_fileno(struct gaio_Io* io);

/**
 * @brief
 * Wrapper function for close().
 * @details
 * IO object should be initialize like this:
 * io->object.integer = FILE_DESCRIPTOR
 * @param io
 * Pointer of IO object.
 * @returns What close() returns.
 */

int gaio_Fd_close(struct gaio_Io* io);

/**
 * @brief
 * Wrapper function for sendfile().
 * @details
 * IO object should support fileno() method.
 * @param outIo
 * Pointer of IO object.
 * @param inIo
 * Pointer of IO object.
 * @param offset
 * Offset of inIo.
 * @param count
 * Count of bytes to send.
 */

int gaio_Generic_sendfile(struct gaio_Io* outIo, struct gaio_Io* inIo, int* offset, int count);

#endif
