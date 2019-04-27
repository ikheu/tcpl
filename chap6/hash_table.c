struct nlist {
    struct nlist next;
    char *key;
    char *value;
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