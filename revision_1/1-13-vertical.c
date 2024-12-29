#include <stdio.h>

#define MAX_WORD_LENGTH 16
#define IN 1
#define OUT 0

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("USAGE: ./1-13 FILENAME");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Could not open file %s\n! Are you sure the file exists?\n", argv[1]);
        return 2;
    }

    int lwords[MAX_WORD_LENGTH];
    for (int i = 0; i < MAX_WORD_LENGTH; i++)
        lwords[i] = 0;
    int state = OUT;
    int word_length = 0;
    int c;
    while ((c = fgetc(f)) != EOF)
    {
        if (c == '\n' || c == ' ' || c == '\t')
        {
            if (state == IN)
            {
                lwords[word_length - 1]++;
                word_length = 0;
            }
            state = OUT;
        }

        else
        {
            state = IN;
            word_length++;
        }
    }

    if (state == IN)
    {
        lwords[word_length - 1]++;
    }

    printf("\n\n");
    int max_freq = 0;
    for (int i = 0; i < MAX_WORD_LENGTH; i++)
        max_freq = (lwords[i] > max_freq) ? lwords[i] : max_freq;
    
    for (int i = max_freq; i > 0; i--)
    {
        for (int j = 0; j < MAX_WORD_LENGTH; j++)
        {
            if (lwords[j] == i)
            {
                if (j + 1 < 10)
                {
                    printf("| ");
                    lwords[j]--;
                }
                else
                {
                    printf("|  ");
                    lwords[j]--;
                }
                
            }
            else if (j + 1 < 10)
            {
                printf("  ");
            }

            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }

    for (int i = 1; i < MAX_WORD_LENGTH + 1; i++)
        printf("%d ", i);
    printf("\n");
    
}
