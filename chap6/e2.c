#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
}

int main() {
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
    }
    
}

struct tnode *talloc(void);
char *strdup(char *s);

struct tnode *addtree(struct tnode *p, char *s) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(s);
        p->count = 1;
        p->left = NULL;
        p->right = NULL;
    } else if ((cond == strcmp(w, p -> word))) {
        p -> count++;
    } else if (cond < 0) {
        p->left = addtree(p -> left, s);
    } else {
        p->right = addtree(p -> right, s);
    }
    return p;
}

void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p -> left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p -> right);
    }
}

#include <stdlib.h>
struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup(char *s) {
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p ,s);
    return p;
}

int getword(char *word, int lim) {
    int getch(void);
    void ungetch(int);
    int c;
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

#define BUFSIZE 100
int buf = 0;

int getch() {
    int c;
    c = (buf != 0) ? buf : getchar();
    buf = 0;
    return c;
}

void ungetch(int c) {
    if (buf != 0) {
        printf("ungetch: too many characters\n");
    } else {
        buf = c;
    }
}
