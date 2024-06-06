#include <stdio.h>

int main(void)
{
    float cels;
    printf("%3c%10c\n", 'c', 'f');
    for (float fahr = 0; fahr <= 300; fahr += 20)
    {
        cels = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, cels);
    }
}
