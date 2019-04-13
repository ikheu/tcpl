#include <stdio.h>
#include <string.h>

void qsort(void *v[], int left, int right, int (*comp)(void *, void *));

int main() {
    char *arr[3];
    arr[0] = "hi";
    arr[1] = "gg";
    arr[2] = "ff";
    qsort((void **) arr, 0, 2, (int(*)(void *, void *))strcmp);
    printf("%s, %s, %s\n", arr[0], arr[1], arr[2]);
    return 0;
}

void qsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1, comp);
    qsort(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
