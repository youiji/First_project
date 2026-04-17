#include <stdio.h>
#include <stdbool.h>

typedef struct {
    bool b;
    bool e;
    bool n;
    bool s;
    bool t;

}Flags;

int main(int argc, char *argv[]) {
    Flags flags = {0};
    parcing_flags(argc, argv, &flags);
    for (int i = optind; i < argc; ++i){
        print_file(argv[i], flags);
    }
    return 0;
}