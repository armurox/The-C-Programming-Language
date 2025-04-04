#include <stdio.h>

#define COLUMNS 8
#define MAX_SPACES 8

int main(void)
{
    int c;
    int num_chars = 0;
    int num_spaces_before_non_blank = 0;
    int i;
    char spaces[MAX_SPACES + 1];
    for (i = 0; i < MAX_SPACES + 1; i++)
        spaces[i] = '\0';
    i = 0;
    while ((c = getchar()) != EOF)
    {
        if (num_chars >= COLUMNS || num_spaces_before_non_blank == MAX_SPACES)
        {
            putchar('\n');
            num_chars = 0;
            if (num_spaces_before_non_blank == MAX_SPACES)
                num_spaces_before_non_blank = 0;
        }
            
        if ((c == ' ' || c == '\t'))
        {
            num_chars++;
            spaces[num_spaces_before_non_blank++] = c;
        }
            
        else if (c != '\n')
        {
            num_chars++;
            for (i = 0; i < num_spaces_before_non_blank; i++)
                putchar(spaces[i]);
            i = 0;
            num_spaces_before_non_blank = 0;
            putchar(c);
        }

        else
        {
            num_chars = 0;
        }
        
    }

}
