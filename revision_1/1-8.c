#include <stdio.h>

int main(void)
{
    long nb = 0;
    long nt = 0;
    long nl = 0;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
            nt++;
        if (c == ' ')
            nb++;
        if (c == '\n')
            nl++;
    }

    printf("Number of blanks: %ld\nNumber of tabs: %ld\nNumber of newlines: %ld\n", nb, nt, nl);
}
