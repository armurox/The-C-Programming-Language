#include <stdio.h>

int power(int base, int n);

int main(void)
{
    for (int i = 0; i < 10; i++)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
}

int power(int base, int n)
{
    int p = 1;
    for (int i = 0; i < n; i++)
        p *= base;
    return p;
}
