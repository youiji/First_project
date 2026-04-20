#include <stdio.h>
#include <stdbool.h>

typedef struct {
    bool b;
    bool e;
    bool n;
    bool s;
    bool t;
    bool v;

}Flags;

int main(int argc, char *argv[]) {
    Flags flags = {0};
    parcing_flags(argc, argv, &flags);
    for (int i = 1; i < argc; ++i){
        print_file(argv[i]);
    }
    return 0;
}

void print_file(char *name){
    FILE *f = fopen(name, "rt");
    if (f != NULL) {
        int c = fgetc(f);
        while (c != EOF) {
            putc(c, stdout);
            c = fgetc(f);
        }
        fclose(f);
    }
}