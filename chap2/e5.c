#include <stdio.h>

int any(char s[], char q[]);

int main() {
    char s[] = "hello";
    char q[] = "w";
    printf("%d\n", any(s, q));
}

int any(char s[], char q[]) {
    int i, j;
    int pos = -1;
    for (j = 0; q[j] != '\0' && pos == -1; ++j) {
        for (i= 0; s[i] != '\0' && pos == -1; ++i) {
            if (s[i] == q[j]) {
                pos = i;
            }
        }
    }
    return pos;
}
