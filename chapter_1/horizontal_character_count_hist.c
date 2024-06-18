#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORDLENGTH 26
#define MAXFREQUENCY 40000

int main(void)
{
    int c;
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
        if ((c == ' ' || c == '\t' || c == '\n'))
        {
            continue;
        }

        else
        {
            strcat(str[tolower(c) - 'a'], "-");
        }
    }

    for (int i = 0; i < MAXWORDLENGTH; i++)
    {
        printf("%c %s\n", i + 'a', str[i]);
    }

    return 0;
}

