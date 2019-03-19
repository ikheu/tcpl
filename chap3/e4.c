#include <stdio.h>
#include <string.h>
#define abs(x) ((x) < 0 ? - (x) : (x))

void itoa(int n, char s[]);
void itoa2(int n, char s[]);

int main() {
    char s[60];
    char s2[60];
    itoa(12345, s);
    itoa2(-12345, s2);
    printf("%s\n", s);
    printf("%s\n", s2);
}

void itoa(int n, char s[]) {
    void reverse(char s[]);
    int sign;
    int i = 0;
    

    if ((sign = n) < 0) {
        n = -n;
    }
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void itoa2(int n, char s[]) {
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
