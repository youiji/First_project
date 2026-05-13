#include "s21_cat.h"
#include <stdio.h>

int main(int argc, char **argv) {
    t_flags flags = {0};

    int file_index = parse_flags(&flags, argc, argv);

    if (file_index == argc) {
        fprintf(stderr, "Файл не указан\n");
        return 1;
    }

    int status = 0;

    for (int i = file_index; i < argc; i++) {
        if (print_file(argv[i], &flags) != 0) {
            status = 1;
        }
    }

    return status;
}