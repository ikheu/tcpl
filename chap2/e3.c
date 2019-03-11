#include <stdio.h>
#define YES 1
#define NO 2

int hoti(char s[]);

int main() {
    char s[] = "0123";
    printf("%d\n", hoti(s));
}

int hoti(char s[]) {
    int inhex, hexdigit, n;
    int i = 0;

    if (s[i] == 0) {
        ++i;
        if (s[i] == 'x' || s[i] == 'X') {
            ++i;
        }
    }
    n = 0;
    inhex = YES;
    for( ; inhex == YES; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            hexdigit = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            hexdigit = s[i] - 'a';
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            hexdigit = s[i] - 'A';
        } else {
            inhex = NO;
        }
        if (inhex == YES) {
            n = n * 16 + hexdigit;
        }
    }
    return n;
}