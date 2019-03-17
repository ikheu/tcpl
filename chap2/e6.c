#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

unsigned getbits(unsigned x, int p, int n) {
    return (x & ~(~(~0 << n) << (p - n + 1))) |
           (y & (~0 << n) << (p - n + 1));
}
