#ifndef RAND64_SW_H
#define RAND64_SW_H

void filename_init (char* file);
void software_rand64_init (void);
unsigned long long software_rand64 (void);
void software_rand64_fini (void);

#endif