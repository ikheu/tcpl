#include <stdio.h>

int main() {
    int c;
    while((c = getchar()) != EOF) {
        putchar(c);
    }
    printf("%d\n", (getchar()) != EOF);
    return 0;
}
