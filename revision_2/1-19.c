#include <stdio.h>

#define MAXLINE 4000

int _getline(char line[], int limit, FILE *file);
void _reverse_string(char s[]);
int _strlen(char s[]);

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
        printf("Could not find / open file %s", argv[1]);
        return 2;
    }

    char line[MAXLINE];
    while(_getline(line, MAXLINE, f))
    {
        _reverse_string(line);
        printf("%s", line);
    }
    printf("\n");
        
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

void _reverse_string(char s[])
{
    int len = _strlen(s);
    char temp_s[len + 1];
    for (int i = 0; i < len; i++)
        temp_s[i] = s[len - 1 - i];
    temp_s[len] = '\0';

    for (int i = 0; i < len + 1; i++)
        s[i] = temp_s[i];
    
}


int _strlen(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}