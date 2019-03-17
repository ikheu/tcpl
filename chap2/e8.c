#include <stdio.h>

int main() {
    unsigned rightrot(unsigned x, int n);
    unsigned x = 12;
    printf("%u\n", rightrot(x, 3));
    return 0;
}

unsigned rightrot(unsigned x, int n) {
    int wordlength(void);
    int len = wordlength();
    if ((n = n % len) > 0) {
        x = (x >> n) | (x << (len - n));
    }
    return x;
}

int wordlength() {
    int i;
    unsigned v = (unsigned) ~0;
    for (i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}
