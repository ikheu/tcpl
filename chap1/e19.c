#include <stdio.h>

void reverse(char s[], int len);

int main() {
    char s[] = "hello";
    reverse(s, 5);
    print("%s\n", s);
    return 0;
}

void reverse(char s[], int len) {
    int i;
    char temp;
    for (i = 0; i < (len - 1)/ 2; ++i) {
        temp = s[i];
        s[i] = s[temp - 1 - i];
        s[temp - 1 - i] = temp;
    }
}
