#include "s21_cat.h"

static void handle_numbering(t_flags *f, int c, int *prev, int *idx) {
    if (*prev == '\n') {
        if (f->b) {
            if (c != '\n')
                printf("%6d\t", ++(*idx));
        }   else if (f->n) {
                printf("%6d\t", ++(*idx));
            }
    }
}

static int transform_char(t_flags *f, int c) {
    int status = c;
    if (f->T && c == '\t') {
        printf("^I");
        status = -1;
    }

    if (f->v && c != '\n' && c != '\t' && (c < 32 || c == 127)) {
        printf("^");
        if (c == 127){
            status = '?';
        } else {
            status = c + 64;
        }
    }

    return status;
}

static int squeeze_blank(t_flags *f, int c, int prev, int *squeeze) {
    int status = 0;
    if (f->s && prev == '\n' && c == '\n') {
    if (*squeeze)
        status = 1;
    *squeeze = 1;
} else {
    *squeeze = 0;
}
return status;
}

void print_symb(int c, int *prev, t_flags *f, int *idx, int *squeeze) {
    if (!squeeze_blank(f, c, *prev, squeeze)) {
        handle_numbering(f, c, prev, idx);

        if (f->E && c == '\n')
            putchar('$');

        int out = transform_char(f, c);
        if (out != -1)
            putchar(out);
    }

    *prev = c;
}