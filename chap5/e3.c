#include <stdio.h>

int main() {
    void strcat1(char *s, char *t);
    char s[100] = "hello";
    char t[] = " world";
    strcat1(s, t);
    printf("%s\n", s);
    return 0;   
}

void strcat1(char *s, char *t) {
    while(*s++)
        ;
    s--;
    while(*s++ = *t++)
        ;
}