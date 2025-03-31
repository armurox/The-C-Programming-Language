#include <stdio.h>

#define IN 1
#define OUT 2

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./wc [FILENAME]\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Could not find / open file %s!\n", argv[1]);
        return 2;
    }

    int nl = 1;
    long nw = 0;
    long nc = 0;
    int c = 0;
    int in_char = 0;
    int state = OUT;
    while ((c = fgetc(f)) != EOF)
    {
       nc++;
        if (c == '\n')
            nl++;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            nw++;
        }
    }

    fclose(f);
    printf("No. of characters: %ld\nNo. of words: %ld\nNo. of lines: %d\n", nc, nw, nl);

}
