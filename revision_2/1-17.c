#include <stdio.h>

#define MAXLINE 4000
#define MIN_LENGTH_TO_PRINT 80

int _getline(char line[], int limit, FILE *file);
void _copy(char from[], char to[]);

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
        printf("Could not find / open file with name %s", argv[1]);
        return 2;
    }

    int curr_len;
    char line[MAXLINE];
    while ((curr_len = _getline(line, MAXLINE, f)))
    {
        if (curr_len > MIN_LENGTH_TO_PRINT)
        {
            printf("%s", line);
        }
            
    }

    fclose(f);
}

int _getline(char line[], int limit, FILE *file)
{
    int i, c;

    for (i = 0; i < limit - 1 && (c = fgetc(file)) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';
    return i;
}
