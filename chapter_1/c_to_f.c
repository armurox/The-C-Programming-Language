#include <stdio.h>

int main(void)
{
    float fahr;
    printf("%3c%6c\n", 'f', 'c');
    for (float cels = 0; cels <= 148.9; cels += 11.1)
    {
        fahr = ((9.0 / 5.0 ) * cels) + 32.0;
        printf("%4.1f%6.0f\n", cels, fahr);
    }
}