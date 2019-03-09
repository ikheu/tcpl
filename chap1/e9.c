#include <stdio.h>

int main() {
    int c, p;
    p = '0';
    while((c = getchar()) != EOF) {
        if (c != ' ')
            putchar(c);
        else if (p != ' ')
            putchar(c);
        p = c;
    }
    return 0;
}
