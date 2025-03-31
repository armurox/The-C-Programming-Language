#include <stdio.h>

#define IN 1
#define OUT 2

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./a.out [FILENAME]\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Could not find / open file %s!\n", argv[1]);
        return 2;
    }

    int state = OUT;
    int c;
    while ((c = fgetc(f)) != EOF)
    {
        if ((c == ' ' || c == '\n' || c == '\t') && state == IN)
        {
            state = OUT;
            putchar('\n');
        }

        else if ((c != ' ' && c != '\n' && c != '\t'))
        {
            state = IN;
            putchar(c);
        }
    }

}
