#include <stdio.h>

int main() {
    int c;
    int p = '0';

    while((c = getchar()) != EOF) {
        if (c == '\t' || c == ' ')
            c = '\n';
        if (c != '\n') 
            putchar(c);
        else if (p != '\n')
            putchar(c);
        p = c;
    }
    return 0;
}
