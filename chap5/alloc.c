#include <stdio.h>

int main() {
    char *p = "hello";
    printf("%c\n", *(p + 1));
    printf("%s\n", p);
    return 0;
}
