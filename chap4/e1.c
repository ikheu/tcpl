#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]);
int strrindex(char s[], char t[]);

int main() {
    char s[] = "hello";
    char t[] = "q";
    int index = strindex(s, t);
    int indexr = strrindex(s, t);
    printf("%d\n", index);
    printf("%d\n", indexr);
    return 0;
}

int strindex(char s[], char t[]) {
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

int strrindex(char s[], char t[]) {
    int i, j, k;
    int s_len = strlen(s);
    int t_len = strlen(t);

    for (i = s_len - 1; i >= 0; i--) {
        for (j = i, k = t_len - 1; k >= 0 && s[j] == t[k]; j--, k--)
            ;
        if (k < t_len - 1 && k == -1)
            return i;
    }
    return -1;
}
