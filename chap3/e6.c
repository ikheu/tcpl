#include <stdio.h>
#include <string.h>
#define abs(x) ((x) < 0 ? - (x) : (x))

void itoa(int n, char s[], int w);

int main() {
    char s[60];
    itoa(12, s, 4);
    printf("%s\n", s);
}

void itoa(int n, char s[], int w) {
    void reverse(char s[]);
    int sign;
    int i = 0;
    
    sign = n;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    while (i < w) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int i;
    char temp;
    int len = strlen(s);

    for (i = 0; i < len / 2; ++i) {
        temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}
