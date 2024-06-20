#include <stdio.h>

#define MAXLINE 1000

int _getline(char s[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;
    int max = 0;
    char line[MAXLINE + 1];
    char longest[MAXLINE + 1];

    while ((len = _getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
        printf("%s\n", longest);
}

int _getline(char s[], int maxline)
{
    int c, i;
    for (i = 0; i < maxline && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    for (i = 0; from[i] != '\0'; i++)
        to[i] = from[i];
    to[i] = '\0';
}
