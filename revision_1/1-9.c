#include <stdio.h>

int main(void)
{
    int in_blank = 0;
    int c;
    int prev_c;
    while ((c = getchar()) != EOF)
    {
        prev_c = c;
        if (c == ' ')
            in_blank = 1;
        else if (in_blank)
        {
            printf("%c%c", ' ', c);
            in_blank = 0;
        }
            
        else
            printf("%c", c);
    }

    if (prev_c == ' ')
        printf("%c", ' ');
    printf("\n");
}
