#include <stdio.h>

#define IN_COMMENT 1
#define OUT_OF_COMMENT 0
#define MAX_LINE_LENGTH 1000

int _getline_without_comments(char line[], int limit, FILE *f, int *state);
void _printline(char line[], int line_len);

/*
A program that removes all comments from C source code.
This program is also being used as a test case to verify it's own behavior:)
Hence why you see so many more comments than I would conventionally put in a program,
in kind of a weirder style, to test all the edge cases.
*/

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage ./a.out [FILENAME]");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Could not find / open file %s!", argv[1]);
        return 2;
    }

    char line[MAX_LINE_LENGTH];
    int state = OUT_OF_COMMENT;
    int line_len;
    int num_lines = 0;
    while ((line_len = _getline_without_comments(line, MAX_LINE_LENGTH, f, &state)) != EOF)
    {
        _printline(line, line_len);
        num_lines++;
    }
    printf("\n\nNumber of lines without comment was %d\n", num_lines + 1);
    fclose(f);
}


int _getline_without_comments(char line[], int limit, FILE *f, int *state)
{
    int i, c;
    int found_non_blank = 0;
    int prev;
    for (i = 0; i < limit - 1 && ((c = fgetc(f)) != EOF && c != '\n'); i++)
    {
        /* Here I am keeping track of if the line will start with a comment or not
        essentailly, if a line starts with a comment then it should only have blanks
        behind it */
        if (c != '\t' || c != ' ' || c != '\b')
            found_non_blank = 1;
        // Skip lines starting with a comment, no newline needed. This is the // case
        if (i > 0 && line[i - 1] == '/' && c == '/' && *state != IN_COMMENT)
        {
            if (!found_non_blank)
            {
                i = 0;
                line[i] = '\0';
                while ((c = fgetc(f)) != EOF && c != '\n') // Consume rest of line
                    ;
                return i;
            }

            else if (line[i - 2] != '\t' || line[i - 2] != ' ' || line[i - 2] != '\b') /* Won't give a segmentation fault, 
            as we know at least one non blank character was // found */
            {
                line[i - 1] = '\n';
                line[i] = '\0';
                while ((c = fgetc(f)) != EOF && c != '\n')
                    ;
                return i;
            }

            else // Final case with a space between the comment and current
            {
                line[i - 2] = '\n';
                line[i - 1] = '\0';
                while ((c = fgetc(f)) != EOF && c != '\n')
                    ;
                return i - 1;
            }
                
        }

        else if (i > 0 && line[i - 1] == '/' && c == '*' && *state != IN_COMMENT)
        {
            *state = IN_COMMENT;
            line[i - 1] = '\n';
            line[i] = '\0';
            while ((c = fgetc(f)) != EOF && c != '\n')
            {
                if (prev == '*' && c == '/')
                    *state = OUT_OF_COMMENT;
                prev = c;
            }
            return i;
        }

        else if (*state == IN_COMMENT)
        {
            i = 0;
            line[i] = '\0';
            prev = c;
            while ((c = fgetc(f)) != EOF && c != '\n')
            {
                if (prev == '*' && c == '/')
                    *state = OUT_OF_COMMENT;
                prev = c;
            }
            return i;
        }

        line[i] = c;
    }

    if (c == '\n')
    {
        line[i++] = c;
    }
        
    line[i] = '\0';
    if (c == EOF)
    {
        _printline(line, i); // Calling printline internally here because we want to print extra in case of EOF
        return c;
    }
    return i;
}

void _printline(char line[], int line_len)
{
    for (int i = 0; i < line_len; i++)
        putchar(line[i]);
}
