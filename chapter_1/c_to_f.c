#include <stdio.h>

#define STEP 11.1
#define UPPER 148.9
#define LOWER 0.0

int main(void)
{
    /* Print Celsius to Fahrenheit table */
    printf("%3c%7c\n", 'f', 'c');
    for (float cels = LOWER; cels <= UPPER; cels += STEP)
    {
        printf("%5.1f%6.0f\n", cels, ((9.0 / 5.0) * cels) + 32.0);
    }
}
