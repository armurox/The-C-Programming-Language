#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
    int c;
    int state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (c != '\t' && c != ' ' && c != '\n')
        {
            putchar(c);
            state = IN;
        }

        else if (state == OUT)
        {
            continue;
        }

        else
        {
            state = OUT;
            putchar('\n');
        }
    }
}
