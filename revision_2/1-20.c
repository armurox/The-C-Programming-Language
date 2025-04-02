#include <stdio.h>

#define N 8

int main(void)
{
    int c;
    int count = 0;
    int spaces_left;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            spaces_left = N - (count % N);
            count = 0;
            for (int i = 0; i < spaces_left; i++)
                putchar(' ');
        }

        else if (c == '\n')
        {
            count = 0;
            putchar(c);
        }
            

        else
        {
            putchar(c);
            count++;
        }
            
    }
}
