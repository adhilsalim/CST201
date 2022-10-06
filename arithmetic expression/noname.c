/*
AUTH: ADHIL SALIM
*/

#include <stdio.h>
#include <stdbool.h> //for bool,true,false

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void main()
{

    int totalChars = 0, stack_TOP = -1;

    printf("Entr total number of characters in the arithmetic expression: ");
    scanf("%d", &totalChars);

    char expression[totalChars];
    char stack[totalChars];

    printf("Enter the arithmetic expression: ");
    scanf("%s", expression);

    printf("The expression is: %s", expression);

    printf("\n");

    for (int i = 0; i < totalChars; i++)
    {
        if (!isOperator(expression[i]))
        {
            // printf("not an operator\n");
        }
        else
        {
            // printf("operator\n");
        }
    }
}