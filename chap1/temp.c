#include <stdio.h>

int main() {
    int c, d;
    while((c = getchar()) != EOF) {
        printf("c: %c\n", c);
        d = getchar();
        printf("d: %c\n", d);
    }
    return 0;
}
