#include "s21_cat.h"
#include <string.h>

void print_symb(int c, int *prev, t_flags *f, int *idx, int *squeeze);

int print_file(const char *name, t_flags *f) {
    FILE *file = (strcmp(name, "-") == 0) ? stdin : fopen(name, "r");
    int result = (file == NULL) ? 1 : 0;
    
    if (!result) {
        int c, prev = '\n', idx = 0;
        int squeeze = 0;

        while ((c = fgetc(file)) != EOF)
            print_symb(c, &prev, f, &idx, &squeeze);

        if (file != stdin)
            fclose(file);
    }

    return result;
}