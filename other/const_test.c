#include <stdio.h>

#define SS 2

int main() {
    const int a = 2;
    int arr[SS*SS*a] = {1, 2};
    const int b = 1200;
    const int *p;
    p = &a;
    p = &b;

    printf("%d\n", *p);
    return 0;
}