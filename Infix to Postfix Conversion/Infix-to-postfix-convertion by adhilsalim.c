/*
Program to find postfix of an arithmetic expression

AUTH: ADHIL SALIM
CONTRIBUTORS:

READ ME:
 (1) to find existing issues search for [ISSUE]
 (2) to mark an issue follow the format [ISSUE #count] - explain the issue,
     if the the last issue is #3 then the next issue will be #4, also don't forget to open an issue on github
 (3) if an issue is resolved then [ISSUE #count][RESOLVED]
 (4) while making changes use your username and comment about the change in few sentences.
     eg: [USERNAME] added a function to check if the stack is empty
*/

#include <stdio.h>
#include <stdbool.h>

// function to check if the character is an operator, returns either true or false
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

// function to return order of operator
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
    stack[stack_TOP] = '('; // pushing '(' to the stack to mark the starting of the expression

    // getting expression
    printf("Enter the arithmetic expression: ");
    scanf("%s", expression);

    // traversing through the expression
    for (int i = 0; i < totalChars; i++)
    {
        /*
            if it's an operand print it
        */
        if (!isOperator(expression[i]))
        {
            printf("%c", expression[i]);
        }
        /*
            if it's an operator
        */
        else
        {
            /*
                If the precedence and associativity of the scanned operator are greater
                than the precedence and associativity of the operator in the stack, then push to stack.
            */

            if (orderOfOperator(expression[i] > orderOfOperator(stack[stack_TOP])))
            {
                stack_TOP++;
                stack[stack_TOP] = expression[i];
            }
            /*
                ‘^’ operator is right associative. So if operator to be pushed and operator present at top of
                stack are ^ then push ^ due to right associativity.
            */
            else if (expression[i] == '^' && stack[stack_TOP] == '^')
            {
                stack_TOP++;
                stack[stack_TOP] = expression[i];
            }
            /*
                In all the other cases when the top of the operator stack is the same as the scanned operator,
                then pop the operator from the stack because of left associativity due to which the scanned operator
                has less precedence.

            */
            else if (orderOfOperator(expression[i]) != 3 && orderOfOperator(expression[i]) == orderOfOperator(stack[stack_TOP]))
            {
                stack_TOP--;
                printf("%c", expression[i]);
            }
            else if ()
            {
                /* code */
            }

            if (expression[i] == '(')
            {
            }
            // if the order of current op is greater than the order of op in stack then push to stack
            else if (orderOfOperator(expression[i]) > orderOfOperator(stack[stack_TOP]))
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