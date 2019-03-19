#include <stdio.h>

void unescape(char s[], char t[]);
// c 不做数组越界判断
int main() {
    char s[2];
    char t[] = "\\";
    unescape(s, t);
    printf("%s\n", s);
    return 0;
}

void escape(char s[], char t[]) {
    int i;
    int j = 0;
    for (i = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[]) {
    int i, j;
    j = 0;
    for (i = 0; t[i] != '\0'; ++i) {
        if (t[i] == '\\') {
            switch (t[++i]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                case '\0':
                    s[j++] = '\\';
                    i--;
                    break;
                default:
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
            }
        } else {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}
