#include <stdio.h>

#define MAXLINE 300

int _getline(char line[], int limit, FILE *file);
void _copy(char from[], char to[]);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./a.out [FILENAME]");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Could not find / open file with name %s", argv[1]);
        return 2;
    }

    int largest_length = 0;
    int curr_len;
    char line[MAXLINE];
    char largest_line[MAXLINE]; 
    while ((curr_len = _getline(line, MAXLINE, f)))
    {
        if (curr_len > largest_length)
        {
            _copy(line, largest_line);
            largest_length = curr_len;
        }
            
    }

    fclose(f);

    printf("The largest line in the file %s is: %s of size %d\n", argv[1], largest_line, largest_length);
}

int _getline(char line[], int limit, FILE *file)
{
    int i, c;

    for (i = 0; i < limit - 1 && (c = fgetc(file)) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';

    if (i > limit - 2)
    {
        i++;
        while ((c = fgetc(file)) != EOF && c != '\n')
            i++;
    }

    return i;
}

void _copy(char from[], char to[])
{
    int i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
