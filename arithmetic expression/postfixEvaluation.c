/*
AUTH: ADHIL SALIM

while making changes use comments with username.
*/

#include <stdio.h>
#include <stdbool.h>

// function to check if the character is an operator
// requires header file <stdbool.h>
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

int orderOfOperator(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

void main()
{
    // setting up variables
    int totalChars = 0, stack_TOP = -1;

    // getting input
    printf("Entr total number of characters in the arithmetic expression: ");
    scanf("%d", &totalChars);

    char expression[totalChars]; // array to store the expression
    char stack[totalChars];      // stack for operators

    stack_TOP++;
    stack[stack_TOP] = '('; // pushing '(' to the stack to mark the end of the expression

    // getting expression
    printf("Enter the arithmetic expression: ");
    scanf("%s", expression);

    // printf("The expression is: %s\n", expression);

    // looping through the expression
    for (int i = 0; i < totalChars; i++)
    {
        if (!isOperator(expression[i]))
        {
            printf("%c", expression[i]);
        }
        else
        {
            // if the order of current op is greater than the order of op in stack then push to stack
            if (orderOfOperator(expression[i]) > orderOfOperator(stack[stack_TOP]))
            {

                stack_TOP++;
                stack[stack_TOP] = expression[i];
            }
            else
            {
                while (orderOfOperator(expression[i]) <= orderOfOperator(stack[stack_TOP]))
                {
                    printf("%c", stack[stack_TOP]);
                    stack_TOP--;
                }
                stack_TOP++;
                stack[stack_TOP] = expression[i];
            }
        }
    }
    // printf("%c", stack[stack_TOP]);
}