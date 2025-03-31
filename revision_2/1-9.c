#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char **argv)
{
    if (argc != 1 && argc != 3)
    {
        printf("Usage: ./a.out [Optional -f] [Optional FILENAME]\n");
        return 1;
    }

    int c;
    int state = OUT;
    if (argc == 1)
    {
        while ((c = getchar()) != EOF)
        {
            if ((c == ' ' || c == '\n' || c == '\t') && state == OUT)
            {
                state = IN;
                putchar(c);
            }

            else if (c != ' ' && c != '\n' && c != '\t')
            {
                state = OUT;
                putchar(c);
            }
        }
    }

    else
    {
        FILE *f = fopen(argv[2], "r");
        if (f == NULL)
        {
            printf("Could not find / open file with name %s", argv[2]);
            return 2;
        }

        while ((c = fgetc(f)) != EOF)
        {
            if ((c == ' ' || c == '\n' || c == '\t') && state == OUT)
            {
                state = IN;
                putchar(c);
            }

            else if (c != ' ' && c != '\n' && c != '\t')
            {
                state = OUT;
                putchar(c);
            }
        }
    }
}