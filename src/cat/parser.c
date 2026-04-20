#include "s21_cat.h"
#include <string.h>

static void set_flag(t_flags *f, char c) {
    switch (c) {
        case 'b': f->b = true; f->n = false; break;
        case 'E': f->E = true; break;
        case 'e': f->E = true; f->v = true; break;
        case 'n': f->n = true; f->b = false; break;
        case 's': f->s = true; break;
        case 't': f->T = true; f->v = true; break;
        case 'T': f->T = true; break;
        case 'v': f->v = true; break;
    }
}

int parse_flags(t_flags *f, int argc, char **argv) {
    int i = 1;
    bool is_flag = true;

    while (i < argc && is_flag) {
        is_flag = (argv[i][0] == '-' && strcmp(argv[i], "-") != 0 && strcmp(argv[i], "--") != 0);
        
        if (is_flag) {
            for (int j = 1; argv[i][j]; j++)
                set_flag(f, argv[i][j]);
            i++;
        }
    }

    return i;
}