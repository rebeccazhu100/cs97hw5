#include "options.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void parseOptions(int argc, char **argv, struct options* opt) {
    opt->valid = false;
    int flags;
    while ((flags = getopt(argc, argv, ":i:o:")) != -1) {
        switch(flags) {
            case 'i':
                if (strcmp("rdrand", optarg) == 0) {
                    opt->input = 1;
                    opt->valid = true;
                    break;
                } else if (strcmp("mrand48_r", optarg) == 0){
                    opt->input = 2;
                    opt->valid = true;
                    break;
                } else if (optarg[0] == '/') {
                    opt->input = 3;
                    opt->source = optarg;
                    opt->valid = true;
                    break;
                }
                return;
            case 'o':
                if (strcmp("stdio", optarg) == 0) {
                opt->output = "stdio";
                } else {
                    opt->output = "N";
                    opt->blocksize = atoi(optarg);
                    if (opt->blocksize == 0) {
                        fprintf (stderr, 'Invalid block size');
                        return;
                    }
                }
                opt->valid = true; break;
            case ':':
                fprintf (stderr, "Missing argument");
                break;
            case '?':
                fprintf (stderr, "Unrecognized option");
                break;
        }
    }
    if (optind >= argc) {
        return;
    }

    opt->nbytes = atoi(argv[optind]);

    if (opt->nbytes >= 0) {
        opt->valid = true;
    } 
    // else {
    //     opt->valid = false; 
    // }
    // printf("The input option is %d", opt->input);
}

/* Check arguments.  */
// bool valid = false;

// int options(int argc, char **argv, long long *nbytes) {
//     if (argc == 2) {
//         char *endptr;
//         errno = 0;
//         *nbytes = strtoll (argv[1], &endptr, 10);

//         if (errno)
//             perror (argv[1]);
//         else
//             valid = !*endptr && 0 <= *nbytes;
//     }

//     if (!valid) {
//         fprintf (stderr, "%s: usage: %s NBYTES\n", argv[0], argv[0]);
//         return 1;
//     }
// }
