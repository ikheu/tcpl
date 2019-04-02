#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[]) {
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (islower(c)) {
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        if (strlen(s) > 1)
            return NAME;
        else
            return s[0];
    }
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c;
        else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int ii = 0;
char tmp[100];

int getop_v2(char s[]) {
    int i, c;
    int myGetline(char [], int);

    if (tmp[ii] == '\0')
        if (myGetline(tmp, 100) == 0)
            return EOF;
        else
            ii = 0;
    while((s[0] = c = tmp[ii++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (islower(c)) {
        while (islower(s[++i] = c = tmp[ii++]))
            ;
        s[i] = '\0';
        if (c != EOF)
            ii--;
        if (strlen(s) > 1)
            return NAME;
        else
            return s[0];
    }
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    
    if (c == '-') {
        if (isdigit(c = tmp[ii++]) || c == '.')
            s[++i] = c;
        else {
            if (c != EOF)
                ii--;
            return '-';
        }
    }
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = tmp[ii++]))
            ;
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = tmp[ii++]))
            ;
    }
    s[i] = '\0';
    if (c != EOF)
        ii--;
    return NUMBER;
}



int myGetline(char s[], int lim) {
    int c, i, j;
    j = 0;
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
