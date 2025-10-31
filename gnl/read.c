#define _GNU_SOURCE

#include "../../get_next_line/get_next_line.h"

#include <stdio.h>
#include <dlfcn.h>

ssize_t read(int fildes, void *buf, size_t nbyte)
{
	ssize_t(*libc_read)(int, void *, size_t) =
		(ssize_t (*)(int, void *, size_t))dlsym(RTLD_NEXT, "read");
	if (nbyte != BUFFER_SIZE) {
		printf("[ERROR: read: nbyte (%zu) != BUFFER_SIZE (%d)]", nbyte, BUFFER_SIZE);
		return (-1);
	}
	return libc_read(fildes, buf, nbyte);
}
