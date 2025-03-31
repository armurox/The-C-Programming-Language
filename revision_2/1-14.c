#include <stdio.h>
#include <string.h>

#define IN 1
#define OUT 2

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: ./a.out [-h | -v] [FILENAME]\n");
        return 1;
    }

    FILE *f = fopen(argv[2], "r");
    if (f == NULL)
    {
        printf("Could not find / open file %s!\n", argv[1]);
        return 2;
    }

    int state = OUT;
    char c;
    int char_count[256];
    for (int i = 0; i < 256; i++)
        char_count[i] = 0;

    while ((c = fgetc(f)) != EOF)
    {
        char_count[c]++;
    }

    if (strcmp("-h", argv[1]) == 0)
    {
        for (int i = 0; i < 256; i++)
        {
            printf("%c ", (char) i);
            for (int j = 0; j < char_count[i]; j++)
                printf("-");
            printf("\n");
        }
    }
            
    fclose(f);
        

}
