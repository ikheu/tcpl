#include <stdio.h>

int main() {
    int lower(int);
    printf("%c\n", lower('A'));
}

int lower(int c) {
    return (c <= 'Z' && c >= 'A') ? (c + 'a' - 'A') : c;
}
