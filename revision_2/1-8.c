#include <stdio.h>

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
        printf("Could not find / open file with name %s\n", argv[1]);
        return 2;
    }

    long nb = 0;
    long nt = 0;
    long ns = 0;

    int c = 0;
    while((c = fgetc(f)) != EOF)
    {
        if (c == ' ')
            ns++;
        if (c == '\t')
            nt++;
        if (c == '\n' || c == ' ' || c == '\t')
            nb++;
    }

    printf("No. of spaces: %ld\nNo. of tabs: %ld\nNo. of blanks: %ld\n", ns, nt, nb);
}
