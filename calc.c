#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/***    data    ***/
struct calcConfig
{
    char *line;
    size_t len;
};
struct calcConfig C;
/***    input   ***/
/***    output  ***/
int evaluate()
{
    int result = 0;
    int current_number = 0;
    char op = '+'; // Assume positive first number

    for (int i = 0; C.line[i] != '\0'; i++)
    {
        char c = C.line[i];

        if (isdigit(c))
        {
            current_number = current_number * 10 + (c - '0');
        }

        if (!isdigit(c) && !isspace(c) || C.line[i + 1] == '\0')
        {
            if (op == '+')
            {
                result += current_number;
            }
            else if (op == '-')
            {
                result -= current_number;
            }
            op = c;
            current_number = 0;
        }
    }

    return result;
}

/***    init    ***/
void initCalc()
{
    C.line = NULL;
    C.len = 0;
}

int main()
{
    initCalc();
    printf("Enter an expression: ");
    getline(&C.line, &C.len, stdin);

    int result = evaluate();
    printf("Result: %d\n", result);

    free(C.line);
    return 0;
}