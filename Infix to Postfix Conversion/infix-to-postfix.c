#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char STACK[100];
char INFIX[100];
int TOP = -1;

void push(char);
char pop();

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

    char current_character;

    for (int i = 0; i < strlen(INFIX); i++)
    {
        current_character = INFIX[i];
        if (current_character == '(')
        {
            push(current_character);
        }
        else if (current_character = ')')
        {
            while (STACK[TOP] != '(')
            {
                printf("%c", pop());
            }
        }
    }
}