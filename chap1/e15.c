#include <stdio.h>

float celsius(float);
int main() {
    int lower, upper, step;
    float fahr;

    lower = 0;
    upper = 300;
    step = 10;

    fahr = lower;
    while(fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, celsius(fahr));
        fahr += step;
    }
}

float celsius(float fahr) {
    return (fahr - 32.0) * 5.0 / 9.0;
}
