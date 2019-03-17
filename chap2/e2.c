#include <stdio.h>

enum loop {YES, NO};
enum loop okloop = YES:

void my_getline(char s[], int lim) {
    int i, c;
    i = 0;
    while (okloop == YES) {
        if (i >= lim + 1) {
            okloop = NO;
        } else if ((c = getchar()) == '\n'){
            okloop = NO;
        } else if (c == EOF) {
            okloop = NO;
        } else {
            s[i] = c;
            ++i;
        }
    }
}