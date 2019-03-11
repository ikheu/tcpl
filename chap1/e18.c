#include <stdio.h>
#define MAXLINE = 1000

int main() {
    int c, len;
    int line[MAXLINE];
    int current;

    while((len = myGetline(line, MAXLINE)) > 0 ) {
        for (int i = len - 1; i > -1 && (current = line[i]) != ' ' && current != '\t'; --i)
            ;
        line[i] = '\0'
        printf("%s", line);
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
