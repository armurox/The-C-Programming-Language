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
    int c;
    int wl = 0;
    int wls[20];
    for (int i = 0; i < 20; i++)
        wls[i] = 0;

    while ((c = fgetc(f)) != EOF)
    {
        if ((c == ' ' || c == '\n' || c == '\t') && state == IN)
        {
            state = OUT;
            wls[wl - 1]++;
            wl = 0;
        }

        else if ((c != ' ' && c != '\n' && c != '\t'))
        {
            state = IN;
            wl++;
        }
    }

    if (strcmp("-h", argv[1]) == 0)
    {
        for (int i = 0; i < 20; i++)
        {
            printf("%d ", i + 1);
            for (int j = 0; j < wls[i]; j++)
                printf("-");
            printf("\n");
        }
    }
    
    else
    {

        int max_val = 0;
        int check_found[20];
        for (int i = 0; i < 20; i++)
        {
            if (max_val < wls[i])
                max_val = wls[i];
            check_found[i] = 0;
        }

        printf("\n");
        for (int i = 0; i < max_val; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                if (max_val - i == wls[j] || check_found[j])
                {   
                    if (j < 10)
                        printf("| ");
                    else
                        printf(" | ");
                    check_found[j] = 1;
                }

                else
                {
                    if (j < 10)
                        printf("  ");
                    else
                        printf("   ");
                }
                    
            }
            printf("\n");
        }

        for (int i = 0; i < 20; i++)
        {
            printf("%d ", i + 1);
        }
        printf("\n");
    }
    fclose(f);
        

}
