#include <stdio.h>

int main(void)
{
    int cels;
    for (int fahr = 0; fahr <= 300; fahr += 20)
    {
        cels = (5 * (fahr - 32)) / 9;
        printf("%d\t%d\n", fahr, cels);
    }
}
