#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

int buf = 0;

int getch() {
    int c;
    c = (buf != 0) ? buf : getchar();
    buf = 0;
    return c;
}

void ungetch(int c) {
    if (buf != 0) {
        printf("ungetch: too many characters\n");
    } else {
        buf = c;
    }
}

void ungetchs(char s[]) {
    int len = strlen(s);
    while (len > 0)
        ungetch(s[--len]);
}
