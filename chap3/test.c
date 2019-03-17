#include <stdio.h>

int main() {
    int i = 1;
    printf("%d\n", *(int *)(&i));
    return 0;
}
