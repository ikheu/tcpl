#include <stdio.h>

unsigned invert (unsigned x, int p ,int n) {
    unsigned tmp = (~(~0 << n)) << (p - n + 1);  // 00001110000
    return (x | tmp) & (~x | ~temp); // 应该直接使用 异或^  ： x ^ tmp
}
