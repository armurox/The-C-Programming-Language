#include <stdio.h>

int main(void)
{
    int c;
    int consecutive_spaces = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' && consecutive_spaces)
        {
            continue;
        }

        else if (c == ' ')
        {
            putchar(c);
            consecutive_spaces = 1;
        }

        else
        {
            putchar(c);
            consecutive_spaces = 0;
        }
    }
}
