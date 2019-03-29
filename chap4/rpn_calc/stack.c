#include <stdio.h>
#include "calc.h"
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop() {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double top() {
    if (sp > 0)
        return val[sp - 1];
    else
        printf("error: stack empty\n");
        return 0.0;
}

void reset() {
    sp = 0;
}

void swap_top() {
    double top1, top2;
    if (sp > 2) {
        top1 = pop();
        top2 = pop();
        push(top1);
        push(top2);
    } else {
        printf("stack size less than two\n");
    }
}