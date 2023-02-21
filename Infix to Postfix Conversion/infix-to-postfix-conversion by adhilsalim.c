#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char STACK[100];
char INFIX[100];
int TOP = -1;

void push(char);
char pop();
bool isOperand(char);

bool isOperand(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '(' || c == ')' || c == '^')
    {
        return false;
    }
    else
    {
        return true;
    }
}

int priority(char c)
{
    if (c == '(' || c == ')')
    {
        return 0;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 0;
    }
}

void push(char c)
{
    if (TOP != 99)
    {
        TOP++;
        STACK[TOP] = c;
    }
    else
    {
        printf("\nSTACK OVERFLOW\n");
    }
}

char pop()
{
    if (TOP != -1)
    {
        char temp = STACK[TOP];
        TOP--;
        return temp;
    }
    else
    {
        printf("\nSTACK UNDERFLOW\n");
    }
}

void main()
{
    printf("Enter the infix expression: ");
    gets(INFIX);
    // OR scanf("%s", INFIX);
    // puts(INFIX);

    char current_character, temp;

    for (int i = 0; i < strlen(INFIX); i++)
    {
        current_character = INFIX[i];

        if (isOperand(current_character))
        {
            printf("%c", current_character);
        }
        else if (current_character == '(')
        {
            push(current_character);
        }
        else if (current_character == ')')
        {
            while (STACK[TOP] != '(' && TOP != -1)
            {
                printf("%c", pop());
            }

            temp = pop();
        }
        else if (!isOperand(current_character))
        {
            if (priority(current_character) > priority(STACK[TOP]))
            {
                push(current_character);
            }
            else
            {
                while (TOP != -1 && priority(current_character) <= priority(STACK[TOP]))
                {
                    printf("%c", pop());
                }
                push(current_character);
            }
        }
    }
}