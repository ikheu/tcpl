#include <stdio.h>

struct flags {
    unsigned int is_admin : 1;
    unsigned int is_valid : 1;
};

int main() {
    struct flags f;
    f.is_admin = 1;
    f.is_valid = 0;
    printf("%d\n", f.is_admin);
    printf("%d\n", f.is_valid);
    return 0;
}
