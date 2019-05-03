#include <stdio.h>
struct nlist {
    struct nlist *next;
    char *key;
    char *value;
};

struct nlist *install(char *key, char *value);

int main() {
    char *key = "hi";
    char *value = "hello";
    struct nlist * np;
    np = install(key, value);
    printf("key: %s, value: %s\n", np->key, np->value);
    return 0;
}

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

#include <string.h>
#include <stdlib.h>
char *strdup1(char *s) {
    char *p;

    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p ,s);
    return p;
}

#include <string.h>
struct nlist *lookup(char *s) {
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np -> next) {
        if (strcmp(s, np -> key) == 0)
            return np;
    }
    return NULL;
}


struct nlist *install(char *key, char *value) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(key)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->key = strdup1(key)) == NULL)
            return NULL;
        hashval = hash(key);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->value);
    if ((np->value = strdup1(value)) == NULL)
        return NULL;
    return np;
}
