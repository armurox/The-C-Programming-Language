#include <stdio.h>

#define IN_COMMENT 1
#define OUT_OF_COMMENT 0
#define IN_BRACKET 1
#define OUT_OF_BRACKET 0
#define IN_PARENTHESES 1
#define OUT_OF_PARENTHESES 0
#define IN_BRACES 1
#define OUT_OF_BRACES 0
#define IN_STRING 1
#define OUT_OF_STRING 0
#define IN_CHARACTER 1
#define OUT_OF_CHARACTER 0
#define IN_ESCAPE_SEQUENCE 1
#define OUT_OF_ESCAPE_SEQUENCE 0
#define MAXLINE 1000

int _getline_and_check_syntax_error(
    int line[], 
    int *comment_state, 
    int *string_state, 
    int *bracket_state,
    int *braces_state,
    int *parentheses_state
);


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

    int string_state = OUT_OF_STRING;
    int bracket_state = OUT_OF_BRACKET;
    int parentheses_state = OUT_OF_PARENTHESES;
    int braces_state = OUT_OF_BRACES;
    int comment_state = OUT_OF_COMMENT;
    int character_state = OUT_OF_CHARACTER;
    int escape_state = OUT_OF_ESCAPE_SEQUENCE;
    int escape_count = 0;

    int c;
    while ((c = fgetc(f)) != EOF)
    {
        putchar(c);
        if (!comment_state && !string_state && !character_state && !escape_state)
        {
            if (c == '}' && !braces_state)
            {
                printf("Syntax error! Closing brace used before opening brace\n");
                fclose(f);
                return 3;
            }

            else if (c == ')' && !parentheses_state)
            {
                printf("Syntax error! Closing parentheses used before opening parentheses\n");
                fclose(f);
                return 3;
            }

            else if (c == ']' && !bracket_state)
            {
                printf("Syntax error! Closing bracket used before opening bracket\n");
                fclose(f);
                return 3;
            }

            if (c == '(')
                parentheses_state++;
                
            else if (c == '[')
                bracket_state++;
            else if (c == '{')
                braces_state++;

            else if (c == ')')
                parentheses_state--;

            else if (c == ']')
                bracket_state--;
            else if (c == '}')
                braces_state--;
            
            else if (c == '\"')
                string_state = !string_state;

            else if (c == '\'')
                character_state = !character_state;


            else if (c == '\\')
                escape_state = 1;
        }

        else if (c == '\"' && !character_state && !escape_state)
        {
            string_state = !string_state;
        }
            

        else if (c == '\'' && !string_state && !escape_state)
        {
            escape_state--;
            character_state = !character_state;
        }

        else if (c == '\\' && (string_state || character_state) && !escape_state)
        {
            escape_state = 1;
            escape_count = 2;
        }

    
        escape_count--;

        if (escape_count <= 0)
        {
            escape_state = 0;
        }
            
    }

    if (string_state || braces_state || parentheses_state || bracket_state)
    {
        printf("Syntax Error! Unclosed symbol\n");
        fclose(f);
        return 3;
    }

    fclose(f);

}
