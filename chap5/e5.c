#include <stdio.h>

int main() {
    void strncpy1(char *s,  char *t, int n);
    char s[10];
    char t[] = "hello";
    strncpy1(s, t, 2);
    printf("%s\n", s);
    return 0;
}

void strncpy1(char *s,  char *t, int n) {
    char * tp = t;
    while (*s++ = *t++)
        if (t - tp == n){
            *s = '\0';
            break;
        }
             
}
