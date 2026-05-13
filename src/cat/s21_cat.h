#ifndef S21_CAT_H
#define S21_CAT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    bool b, E, n, s, T, v;
} t_flags;
void print_symb(int c, int *prev, t_flags *f, int *idx, int *squeeze);
int parse_flags(t_flags *f, int argc, char **argv);
int print_file(const char *name, t_flags *f);

#endif