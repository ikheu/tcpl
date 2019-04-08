#include <stdio.h>

int main() {
    void qsort(int v[], int left, int right);
    void print_arr(int v[], int len);
    int v[4] = {1, 4, 3, 2};

    qsort(v, 0, 3);
    print_arr(v, 4);
    return 0;
}


void qsort(int v[], int left, int right) {
    int i, last;
    void swap(int v[], int i, int j);
    void print_arr(int v[], int len);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        } 
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void print_arr(int v[], int len) {
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", v[i]);
    printf("\n");
}