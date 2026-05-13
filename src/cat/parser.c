#include "s21_cat.h"
#include <string.h>

static void set_flag(t_flags *f, char c) {
    switch (c) {
        case 'b':
            f->b = true;
            break;
        case 'n':
            f->n = true;
            break;
        case 'E':
            f->E = true;
            break;
        case 'e':
            f->E = true;
            f->v = true;
            break;
        case 's':
            f->s = true;
            break;
        case 't':
            f->T = true;
            f->v = true;
            break;
        case 'T':
            f->T = true;
            break;
        case 'v':
            f->v = true;
            break;
    }
}

static void parse_long_flag(t_flags *f, const char *arg) {
    if (strcmp(arg, "--number") == 0) {
    f->n = true;
} else if (strcmp(arg, "--number-nonblank") == 0) {
    f->b = true;
} else if (strcmp(arg, "--squeeze-blank") == 0) {
    f->s = true;
}
}

int parse_flags(t_flags *f, int argc, char **argv) {
    int i = 1;

    while (i < argc) {
        if (argv[i][0] != '-' || strcmp(argv[i], "-") == 0)
            break;

        if (strcmp(argv[i], "--") == 0) {
            i++;
            break;
        }

        if (argv[i][1] == '-') {
            parse_long_flag(f, argv[i]);
        } else {
            for (int j = 1; argv[i][j]; j++) {
                set_flag(f, argv[i][j]);
            }
        }

        i++;
    }

    return i;
}