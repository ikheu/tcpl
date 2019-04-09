#include <stdio.h>
#include <string.h>
#include "alloc.c"

#define MAXLINES 5000

char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

int main() {
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000
#define MAXSTORE 10000

int myGetline(char s[], int lim);
char char_store[MAXSTORE];
char *store_top = char_store;

int readlines(char *lineptr[], int maxlines) {
    int nlines, len;
    char line[MAXLEN];

    nlines = 0;
    while ((len = myGetline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || store_top + MAXSTORE - char_store < len)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(store_top, line);
            lineptr[nlines++] = store_top;
            store_top += len;
        }
    }
    return nlines;

}

// #define MAXLEN 1000
// int myGetline(char s[], int lim);
// char *alloc(int);

// int readlines(char *lineptr[], int maxlines) {
//     int nlines, len;
//     char *p, line[MAXLEN];

//     nlines = 0;
//     while ((len = myGetline(line, MAXLEN)) > 0) {
//         if (nlines >= maxlines || (p = alloc(len)) == NULL)
//             return -1;
//         else {
//             line[len - 1] = '\0';
//             strcpy(p, line);
//             lineptr[nlines++] = p;
//         }
//     }
//     return nlines;

// }

void writelines(char *lineptr[], int nlines) {
    int i;
    printf("result:\n");
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

int myGetline(char s[], int lim) {
    int c, i, j;
    j = 0;
    for (i = 0;(c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 2){
            s[j] = c;
            ++j;
        }
    }
    if (c == '\n'){
        s[j] = c;
        ++j;
        ++i;
    }   
    s[j] = '\0';
    return i;
}

void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
