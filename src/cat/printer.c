#include "s21_cat.h"

static void handle_numbering(t_flags *f, int c, int *prev, int *idx) {
    if (*prev == '\n') {
        if (f->n || (f->b && c != '\n')) {
            printf("%6d\t", ++(*idx));
        }
    }
}

static int transform_char(t_flags *f, int c) {
    int result = c;
    if (f->T && c == '\t') {
        printf("^I");
        result = -1;
    } else if (f->v && c != '\n' && c != '\t' && (c < 32 || c == 127)) {
        printf("^");
        result = (c == 127) ? '?' : c + 64;
    }
    return result;
}

static int squeeze_blank(t_flags *f, int c, int prev, int *squeeze) {
    int result = 0;
    if (f->s && prev == '\n' && c == '\n') {
        result = *squeeze ? 1 : 0;
        *squeeze = 1;
    } else {
        *squeeze = 0;
    }
    return result;
}

void print_symb(int c, int *prev, t_flags *f, int *idx, int *squeeze) {
    int skip = squeeze_blank(f, c, *prev, squeeze);
    
    if (!skip) {
        handle_numbering(f, c, prev, idx);
        
        if (f->E && c == '\n')
            putchar('$');
        
        int transformed = transform_char(f, c);
        if (transformed != -1)
            putchar(transformed);
    }
    
    *prev = c;
}