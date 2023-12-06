/*
This program evaluates a postfix expression.
Author: Advaith Manoj
*/
#include <stdio.h>
#include <string.h> //since strlen() is used.
#include <ctype.h>  //since isdigit() and ispunct() functions are used.
#include <stdlib.h> //since atoi() is used.
#include <math.h>   //since pow() is used.

// function prototypes
void posteval(int len, char postarr[], int oprnds[]);
void push(int x, int oprnds[], int *p);
int pop(int oprnds[], int *p);
int evalfn(int x, int y, char operator);

void main()
{
    char postfix[50]; // char array for storing postfix expression.
    int operands[50]; // intger array for storing operands.
    printf("Enter the postfix expression: ");
    gets(postfix);
    int size = strlen(postfix);
    posteval(size, postfix, operands); // posteval function call.
}

void posteval(int len, char postarr[], int oprnds[])
{
    int top = -1; // for pop and push functions.
    for (int i = 0; i < len; i++)
    {
        if (isdigit(postarr[i])) // checks if an element from postfix expression is a number if so pushes it's integer value to operand array.
        {
            char test[1];
            test[0] = postarr[i]; // since atoi() works only on null terminated strings so the character is added to a character array, technically converting it to a string.

            int x = atoi(test);
            push(x, oprnds, &top);
        }
        else if (ispunct(postarr[i])) // if element is any punctuation character (+,-,*,/,^...)
        {
            int y = pop(oprnds, &top);
            int x = pop(oprnds, &top);
            int result = evalfn(x, y, postarr[i]); // passes x, y and opertor as argument to evalfunc, which returns the value of the expression.
            push(result, oprnds, &top);
        }
    }
    printf("\nResult: %d\n\n", oprnds[top]);
}

// function for pushing element to an array.
void push(int x, int oprnds[], int *p)
{
    *p += 1;
    oprnds[*p] = x;
}

// function for popping an element from an array.
int pop(int oprnds[], int *p)
{
    int item = oprnds[*p];
    *p -= 1;
    return item;
}

// function to evaluate an expression according to the given operator.
int evalfn(int x, int y, char operator)
{
    if (operator== '+')
    {
        return x + y;
    }
    else if (operator== '-')
    {
        return x - y;
    }
    else if (operator== '*')
    {
        return x * y;
    }
    else if (operator== '/')
    {
        return x / y;
    }
    else if (operator== '^')
    {
        return pow(x, y); // pow(base,power), x^y = pow(x,y).
    }
}
