#include <stdio.h>

#define STEP 20
#define UPPER 300
#define LOWER 0

int main(void)
{
    /* Print Fahrenheit to Celsius table */
    printf("%3c%10c\n", 'c', 'f');
    for (float fahr = UPPER; fahr >= LOWER; fahr -= STEP)
    {
        printf("%3.0f\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}
