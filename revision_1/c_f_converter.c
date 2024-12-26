#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage ./c_f_converter NUMBER Celsius | Fahrenheit\n");
        return 1;
    }

    int number_input;
    if (!(number_input = atoi(argv[1])))
    {
        printf("Did not provide a number as the first argument!\n Usage ./c_f_converter NUMBER Celsius | Fahrenheit\n");
        return 2;
    }

    // Convert argv string to lowercase
    for (int i = 0; i < (int) strlen(argv[2]); i++)
        argv[2][i] = tolower(argv[2][i]);

    if (!(strcmp(argv[2], "fahrenheit")))
    {
        printf("%d Fahrenheit is %d Celsius\n", number_input, (5 * (number_input - 32)) / 9);
    }
    else if (!(strcmp(argv[2], "celsius")))
    {
        printf("%d Celsius is %d Fahrenheit", number_input, ((9 * number_input) / 5) + 32);
    }
    else
    {
        printf("Invalid unit, only Celsius or Fahrenheit allowed!\n");
        return 3;
    }

}
