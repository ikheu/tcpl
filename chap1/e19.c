#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main() {
    char s[] = "hello";
    reverse(s);
    printf("%s\n", s);
    return 0;
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
