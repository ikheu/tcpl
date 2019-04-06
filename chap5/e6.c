#include <stdio.h>

int main() {
    void reverse(char *s);
    char s[] = "hello";
    
    reverse(s);
    printf("%s\n", s);
    return 0;
}

void reverse(char *s) {
    char *sp = s;
    char tmp;
    while (*s)
        s++;
    s--;
    for (; sp != s; sp++, s--) {
        tmp = *sp;
        *sp = *s;
        *s = tmp;
    }
}