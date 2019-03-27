#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main() {
    char s[] = "3.14159e3";
    printf("%.10f\n", atof(s));
}

double atof(char s[]) {
    int sign, i, power2, sign2;
    double val, power;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10 * val + s[i] - '0';
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10 * val + s[i] - '0';
        power = power * 10;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    sign2 = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (power2 = 0; isdigit(s[i]); i++)
        power2 = power2 * 10 + s[i] - '0';
    while (power2 > 0) {
        if (sign2 == -1) {
            val /= 10;
        } else {
            val *= 10;
        }
        power2--;
        
    }
    return sign * val / power;
}
