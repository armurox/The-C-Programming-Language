#include <stdio.h>

/* Print Fahrenehit-Celsius table
    for fahr = 0, 20, ..., 300 */
int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("%3c\t%5c\n", 'F', 'C');
    while (fahr <= upper)
    {
        celsius = (5.0 * (fahr - 32.0)) / 9.0;
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
