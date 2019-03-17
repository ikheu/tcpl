#include <stdio.h>

int main() {
    int bitcount1(unsigned x);
    printf("%d\n", bitcount1(3u));
    return 0;

}

int bitcount0(unsigned x) {
    int n = 0;
    for ( ; x != 0; x >>= 1) {
        if (x & 01) {
            ++n;
        }
    }
    return n;
}

int bitcount1(unsigned x) {
    int n = 0;
    while (x) {
        ++n;
        x &= (x - 1);
    }
    return n;
}