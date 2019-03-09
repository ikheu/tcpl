# include <stdio.h>

int main() {
    float fahr, celsius;
    int lower = 0;
    int upper = 300;
    int step = 20;
    
    fahr = lower;
    printf("%3s %6s\n", "fahr", "celsius");
    while (fahr <= upper) {
        celsius = (fahr - 32) * 5 / 9;
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }
    return 0;
}
