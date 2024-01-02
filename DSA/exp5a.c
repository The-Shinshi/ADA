#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 50
char post[MAX];
int stack[MAX], top = -1, i;
void pushstack(int);
void calculator(char);
main()
{
    printf("enter suffix expression\n");
    gets(post);
    for (i = 0; i < strlen(post); i++)
    {
        if (post[i] > '0' && post[i] <= '9')
            pushstack(i);
        else
            calculator(post[i]);
    }
    printf("result=%d\n", stack[top]);
}
void pushstack(int i)
{
    top = top + 1;
    stack[top] = (int)(post[i] - 48);
}
void calculator(char c)
{
    int a, b, ans;
    b = stack[top--];
    a = stack[top--];
    switch (c)
    {
    case '+':
        ans = a + b;
        break;
    case '-':
        ans = a - b;
        break;
    case '*':
        ans = a * b;
        break;
    case '/':
        ans = a / b;
        break;
    case '%':
        ans = a % b;
        break;
    case '^':
        ans = pow(a, b);
        break;
    default:
        printf("wrong input\n");
        exit(0);
    }
    top++;
    stack[top] = ans;
}
