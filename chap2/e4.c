#include <stdio.h>

void squeeze(char s[], char q[]);

int main() {
    char s[] = "hello";
    char q[] = "el";
    squeeze(s, q);
    printf("%s\n", s);
}

void squeeze(char s[], char q[]) {
    int i, j, k;
    int c;
    for (k = 0; q[k] != '\0'; ++k) {
        c = q[k];
        for (i = j = 0; s[i] != '\0'; ++i) {
            if (s[i] != c) {
                s[j++] = s[i];
            }
        }
        s[j] = '\0';
    }
    
}
