#include <stdio.h>
#include <string.h>
#define abs(x) ((x) < 0 ? - (x) : (x))

void itob(int n, char s[], int b);

int main() {
    char s[60];
    itob(123, s, 16);
    printf("%s\n", s);
    printf("%d\n", 'A');
}

// 当然这里不考虑实际位存储情况
void itob(int n, char s[], int b) {
    void reverse(char s[]);
    int sign;
    int tmp;
    int i = 0;
    
    sign = n;
    do {
        tmp = abs(n % b);
        if (tmp <= 9)
            s[i++] = tmp + '0';
        else
            s[i++] = tmp - 10 + 'A';
    } while ((n /= b) != 0);
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
