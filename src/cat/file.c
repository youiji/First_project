#include "s21_cat.h"
#include <string.h>


int print_file(const char *name, t_flags *f) {
    FILE *file = (name == NULL || strcmp(name, "-") == 0)
                   ? stdin
                   : fopen(name, "r");

    if (file == NULL) {
        perror(name);
        return 1;
    }

    int c;
    int prev = '\n';
    int idx = 0;
    int squeeze = 0;

    while ((c = fgetc(file)) != EOF)
        print_symb(c, &prev, f, &idx, &squeeze);

    if (file != stdin)
        fclose(file);

    return 0;
}