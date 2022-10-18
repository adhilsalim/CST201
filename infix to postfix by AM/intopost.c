#include<stdio.h>
#include<string.h>                                      //for strlen().
#include<ctype.h>                                       //for isalnum().

//function prototypes
int priority(char x);
void push(char x,char arr[],int *p);                                      
char pop(char arr[],int *p);
void in_pos(int size,char infarr[],char operarr[]);

//main func
void main()
{
    char infix[50],operators[52];                       //char arrays for storing infix expressions and operators.
    printf("Enter the infix expression: ");
    gets(infix);
    int  len = strlen(infix);                           //adds ')' if it is not present in the infix expression.                            
    if(infix[len-1] != ')')
    {
        infix[len] = ')';
    }
    operators[0] = '(' ;                                //adds ')' to index 0 of the operator array.
    in_pos(len,infix,operators);
}

//function for converting infix-postfix
void in_pos(int size,char infarr[],char operarr[])   
{
    int top = 0;                                        //sets top to 0 for pop and push functions.
    for(int i = 0; i < size+1; i++)
    {
        if(isalnum(infarr[i]))                          //checks if element from infix array is either alphabet or a number
        {
            printf("%c ",infarr[i]);
        }
        else
        {
            if(infarr[i] == '(')                        //if the element is '(', pushes it to operator array
            {
                push(infarr[i],operarr,&top);
            }
            else if(infarr[i] == ')')                   //if element is ')', pops the elements in operator array till '(' and finally pops the '(' too.
            {
                while(operarr[top] != '(')
                {
                    printf("%c ",pop(operarr,&top));
                }
                pop(operarr,&top);
            }
            else if(priority(infarr[i]) == priority(operarr[top]))    //if priorities are same then element at top of operator array is popped out and element from infix array is pushed to opereator array.
            {
                printf("%c ",pop(operarr,&top));
                push(infarr[i],operarr,&top);
            }
            else if( priority(infarr[i]) > priority(operarr[top]))    //if element from infix array has higher priority than element from operator array, element from infix array is pushed to the operator array.
            {
                push(infarr[i],operarr,&top);
            }
            else if( priority(infarr[i]) < priority(operarr[top]))    //if priority of element from operator array is greater than the element from the infix array...
            {
                while(priority(operarr[top]) >= priority(infarr[i]))  //until priorities becomes equal or lower..
                {
                    if(operarr[top] == '(')                           //when '(' is encountered the loop is broken.
                    {
                        break;
                    }
                    else if(priority(operarr[top]) == priority(infarr[i])) //if priorities are equal that element is popped out and the loop is broken.
                    {
                        printf("%c ",pop(operarr,&top));
                        break;
                    }
                    else
                    {
                        printf("%c ",pop(operarr,&top));
                    }
                }
                push(infarr[i],operarr,&top);                         //if the else works then the element at top is popped out.
            }
        }
    }
}
//function for checking priority of operators
int priority(char x)
{

    if(x == '+' || x == '-')                                          //if argument is either + or -, priority ill return 1
    {
        return 1;
    }
    else if(x == '*' || x =='/')                                      //if argument is either * or /, priority will return 2                                          
    {
        return 2;
    }
    else if(x == '^')
    {
        return 3;
    }
}
//function for push
void push(char x,char arr[],int *p)
{
    *p+=1;
    arr[*p] = x;

}
//function for pop
char pop(char arr[],int *p) 
{
    char item = arr[*p];
    *p-=1;
    return item;
}