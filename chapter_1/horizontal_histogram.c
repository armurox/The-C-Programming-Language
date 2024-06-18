#include <stdio.h>
#include <string.h>

#define IN 1
#define OUT 0
#define MAXWORDLENGTH 10
#define MAXFREQUENCY 500

int main(void)
{
    int c;
    int wl = 0;
    int state = OUT;
    char str[MAXWORDLENGTH][MAXFREQUENCY];
    for (int i = 0; i < MAXWORDLENGTH; i++)
    {
        for (int j = 0; j < MAXFREQUENCY; j++)
        {
            str[i][j] = '\0';
        }
    }
    while((c = getchar()) != EOF)
    {
        if ((c == ' ' || c == '\t' || c == '\n') && state == IN)
        {
            strcat(str[wl - 1], "-");
            wl = 0;
            state = OUT;
        }

        else if ((c != ' ' && c != '\t' && c != '\n'))
        {
            wl++;
            state = IN;
        }
    }

    for (int i = 0; i < MAXWORDLENGTH; i++)
    {
        printf("%d %s\n", i + 1, str[i]);
    }

    return 0;
}

