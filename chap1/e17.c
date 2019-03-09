#include <stdio.h>
#define MAXLINE 1000
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
    int c, i, j;
    j = 0;
    // \n 终止本行，并且要记入 \n
    for (i = 0;(c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 2){
            s[j] = c;
            ++j;
        }
    }
    if (c == '\n'){
        s[j] = c;
        ++j;
        ++i;
    }   
    s[j] = '\0';
    return i;
}
