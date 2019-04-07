#include <stdio.h>
# define swap(t, x, y) { t _z; \
                        _z = x; \
                        x = y; \
                        y = _z;}

int main() {
    int x = 1, y = 2;
    swap(int, x ,y);
    printf("x: %d, y: %d\n", x, y);
    return 0;
}
