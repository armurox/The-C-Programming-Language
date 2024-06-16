#include <stdio.h>

int main(void)
{
    long nw = 0;
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
            nw++;
    }

    printf("%ld\n", nw);
}
