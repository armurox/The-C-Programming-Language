#include <stdio.h>

int main(void)
{
    int f = 1;
    printf("F C\n%d %d\n", f, (5 * (f - 32)) / 9);
    for (int f = 20; f < 301; f += 20)
        printf("%d %d\n", f, (5 * (f - 32) / 9));
}
