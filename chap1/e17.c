#include <stdio.h>

#define MAXLINE 10
#define LONGLINE 80

int myGetline(char line[], int maxline);
void copy(char to[], char from []);

int main() {
    int len;
    char line[MAXLINE];
    
    while (len = myGetline(line, MAXLINE)){
        if (len > LONGLINE) {
            printf("%s\n", line);
        }
    }
    return 0;
}

int myGetline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] == c;
        ++i;
    }   
    s[i] = '\0';
    return i;
}
