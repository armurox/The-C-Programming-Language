#include <stdio.h>
#include <string.h>

#define IN 1  /* Inside a word */
#define OUT 0  /* Outside a word */

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("USAGE: ./wc -flag FILENAME\n");
        return 1;
    }

    FILE *f = fopen(argv[2], "r");
    if (f == NULL)
    {
        printf("Could not open file %s!\n", argv[2]);
        return 2;
    }

    int c, nc, nl, nw, state;
    state = OUT;
    nc = nw = nl = 0;
    while ((c = fgetc(f)) != EOF)
    {
        nc++;
        if (c == '\n')
            nl++;
        if (c == '\n' || c == '\t' || c == ' ')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            nw++;
        }
    }

    if (!strcmp(argv[1], "-a"))
    {
        printf("File is %s\nNumber of characters: %d\nNumber of lines: %d\nNumber of words: %d\n", argv[2], nc, nl, nw);
    }

    else if (!strcmp(argv[1], "-c"))
    {
        printf("File is %s\nNumber of characters: %d\n", argv[2], nc);
    }

    else if (!strcmp(argv[1],"-w"))
    {
        printf("File is %s\nNumber of words: %d\n", argv[2], nw);
    }

    else if (!strcmp(argv[1], "-l"))
    {
        printf("File is %s\nNumber of lines: %d\n", argv[2], nl);
    }

    else
    {
        printf("Invalid flag provided! Options are -a, -w and -l\n");
        return 3;
    }
}
