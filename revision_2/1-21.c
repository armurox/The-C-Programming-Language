#include <stdio.h>

#define N 8

int main(void)
{
    int c;
    int spaces_count = 0;
    int character_count = 0;
    int tab_count = 0;
    int spaces_left_to_first_tab_stop;

    while ((c = getchar()) != EOF)
    {
        tab_count = 0;
        if (c == ' ')
            spaces_count++;

        else if (spaces_count)
        {
            spaces_left_to_first_tab_stop = N - (character_count % N);
            spaces_count -= spaces_left_to_first_tab_stop;
            tab_count = spaces_count / N;
            for (int i = 0; i < tab_count; i++)
            {
                putchar('\t');
                character_count++;
            }

            if (tab_count)
                spaces_count %= N;
            else
                spaces_count += spaces_left_to_first_tab_stop;
                
            for (int i = 0; i < spaces_count; i++)
            {
                putchar(' ');
                character_count++;
            }

            spaces_count = 0;
            putchar(c);
            character_count++; // Because this current one is also technically not a space character
        }

        else
        {
            character_count++;
            putchar(c);
        }
    }
}
