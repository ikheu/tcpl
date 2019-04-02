#include <stdio.h>
#include <string.h>

int main() {
    void reverse(char s[]);
    char s[] = "hello darkness my old fridend";
    reverse(s);
    printf("%s\n", s);
    return 0;
}

void reverse(char s[]) {
    void reverse_sub(char s[], int i, int j);
    int i = 0;
    int j = strlen(s) - 1;

    reverse_sub(s, i, j);

}

void reverse_sub(char s[], int i, int j) {
    char tmp;
    
    if (i < j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        reverse_sub(s, ++i, --j);
    }
}