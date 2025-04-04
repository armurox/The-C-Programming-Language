#include <stdio.h>

#define IN_COMMENT 1
#define IN_STAR_COMMENT 2
#define OUT_OF_COMMENT 0

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage ./a.out [FILENAME]");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Could not find / open file %s!", argv[1]);
        return 2;
    }

    int c = fgetc(f);
    int prev;
    int state = OUT_OF_COMMENT;
    if (c != EOF)
    {
        prev = c;
        putchar(c);
    }

    else
    {
        fclose(f);
        return 0;
    }

    while ((c = fgetc(f)) != EOF)
    {
        if (prev == '/' && state == OUT_OF_COMMENT)
        {
            if (c == '/')
                state = IN_COMMENT;
            else if (c == '*')
                state = IN_STAR_COMMENT;
            else
            {
                // Print both, as we would have ignored previous character initially
                // putchar(prev);
                putchar(c);
            }
            prev = c;
        }

        /*
        Need to be clear to ignore this in case we are in a starred comment,
        of course
        */
        else if ((c == '/' || c == '*' ) && state != IN_STAR_COMMENT)
        {
            prev = c;
            continue;
        }

        else if (c == '\n' && state != IN_STAR_COMMENT)
        {
            prev = c;
            state = OUT_OF_COMMENT;
            if (state == OUT_OF_COMMENT)
                putchar(c);
        }

        else if (state == IN_STAR_COMMENT && prev == '*' && c == '/')
        {
            state = OUT_OF_COMMENT;
            prev = ' ';
        }

        else if (state == IN_COMMENT || state == IN_STAR_COMMENT)
        {
            prev = c;
            continue;
        }
            
        else
        {
            prev = c;
            putchar(c);
        }
            
    }

    fclose(f);
}
