#include <stdio.h>

int main(void)
{
    for (int c; (c = getchar()) != EOF;)
    {
        putchar(c);
    }
}
