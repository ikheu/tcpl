#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
    int v[] = {3, 5, 7, 9};
    printf("%d\n", binsearch(5, v, 4));
    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {   // while (low <= high && x != mid) ...
        mid = (low + high) /2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
