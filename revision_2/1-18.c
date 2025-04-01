#include <stdio.h>

#define MAXLINE 300

int _getline_remove_blanks(char line[], int limit, FILE *file);

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

    char line[MAXLINE];
    while (_getline_remove_blanks(line, MAXLINE, f))
        printf("%s", line);

    fclose(f);
}

int _getline_remove_blanks(char line[], int limit, FILE *file)
{
    int i, c;
    char blanks[limit];
    int blank_count = 0;

    for (i = 0; i < limit - 1 && (c = fgetc(file)) != EOF && c != '\n'; i++)
    {
        if (c == ' ' || c == '\t')
            blanks[blank_count++] = c;
        else
        {
            blanks[blank_count] = '\0';
            blank_count = 0;
            for (int j = 0; blanks[j] != '\0'; j++)
            {
                line[i + j] = blanks[j];
                i = i + j;
            }
                
            line[i] = c;
        }
            
    }
        
    if (c == '\n')
    {
        line[i++] = c;
    }
        

    line[i] = '\0';
    return i;
}
