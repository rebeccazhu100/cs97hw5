#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdbool.h>

struct options {
    bool valid;

    long long nbytes;
    char* source;
    unsigned int blocksize;

    unsigned int input;
    unsigned int output;
    //bool var1;
    //char* var2;
};

void parseOptions(int argc, char **argv, struct options* opt);

//int options(int argc, char **argv, long long *nbytes);



#endif