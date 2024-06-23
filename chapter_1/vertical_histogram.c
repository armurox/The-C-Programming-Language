#include <stdio.h>
#include <string.h>

#define IN 1
#define OUT 0
#define MAXWORDLENGTH 10
#define MAXFREQUENCY 500
#define STARTEDHIST 1
#define NOTSTARTEDHIST 0

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
            strcat(str[wl - 1], "|");
            wl = 0;
            state = OUT;
        }

        else if ((c != ' ' && c != '\t' && c != '\n'))
        {
            wl++;
            state = IN;
        }
    }

    int hist_state = NOTSTARTEDHIST;
    for (int i = MAXFREQUENCY - 1; i >= 0; i--)
    {
        for (int j = 0; j < MAXWORDLENGTH; j++)
        {
            if (str[j][i] != '\0')
            {
                printf("%3c", str[j][i]);
                hist_state = STARTEDHIST;
            }
                
            else if (str[j][i] == '\0' && hist_state == STARTEDHIST)
                printf("%3c", ' ');
        }
        if (hist_state == STARTEDHIST)
            printf("\n");
    }

    for (int i = 0; i < MAXWORDLENGTH; i++)
    {
        printf("%3d", i + 1);
    }

    printf("\n");
    return 0;
}
