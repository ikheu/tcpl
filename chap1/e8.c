#include <stdio.h>

int main() {
    int c;
    int nl = 0, ns = 0, nt = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
        }
        if (c == '\t') {
            ++nt;
        }
        if (c == ' '){
            ++ns;
        }
    }
    printf("%d, %d, %d\n", ns, nt, nl);
    return 0;
}
