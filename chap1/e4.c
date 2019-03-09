# include <stdio.h>

int main() {
    float fahr, celsius;
    int lower = -10;
    int upper = 300;
    int step = 20;
    
    celsius = lower;
    printf("%6s %6s\n", "celsius", "fahr");
    while (celsius <= upper) {
        fahr = celsius * 9 / 5 + 32;
        printf("%6.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }
    return 0;
}
