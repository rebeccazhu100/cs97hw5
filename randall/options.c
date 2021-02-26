#include "options.h"

#include <cpuid.h>
#include <errno.h>
#include <immintrin.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Check arguments.  */
bool valid = false;

int options(int argc, char **argv, long long *nbytes) {
    if (argc == 2) {
        char *endptr;
        errno = 0;
        *nbytes = strtoll (argv[1], &endptr, 10);

        if (errno)
            perror (argv[1]);
        else
            valid = !*endptr && 0 <= *nbytes;
    }

    if (!valid) {
        fprintf (stderr, "%s: usage: %s NBYTES\n", argv[0], argv[0]);
        return 1;
    }
}
