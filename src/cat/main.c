#include "s21_cat.h"
#include <string.h>

int print_file(const char *name, t_flags *f);

int main(int argc, char **argv) {
    t_flags flags = {0};
    int file_start = parse_flags(&flags, argc, argv);
    int return_arg = 0;

    if (file_start < argc) {
        for (int i = file_start; i < argc && !return_arg; i++) {
            if (strcmp(argv[i], "--") != 0) {
                return_arg = print_file(argv[i], &flags);
            }
        }
    } else {
        return_arg = print_file("-", &flags);
    }

    return return_arg;
}