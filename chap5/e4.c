#include <stdio.h>

int main() {
    int strend(char *s, char *t);
    char s[] = "hello";
    char t[] = "llo";
    printf("%d\n", strend(s, t));
    return 0;
}


int strend(char *s, char *t) {
    char *sp = s;
    char *tp = t;
    while (*s++)
        ;
    while(*t++)
        ;
    while(s > sp && t > tp && *--s == *--t)
        ;
    if (tp == t && *s == *t)
        return 1;
    else
        return 0;
}
