#include <stdio.h>

int main(void)
{
    printf("%3c%7c\n", 'f', 'c');
    for (float cels = 0; cels <= 148.9; cels += 11.1)
    {
        printf("%5.1f%6.0f\n", cels, ((9.0 / 5.0) * cels) + 32.0);
    }
}
