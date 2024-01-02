#include <stdio.h>
#include <stdlib.h>
#define MAX 2
int stack[MAX], top = -1, item;
void push();
void pop();
void palindrome();
void display();
void main()
{
    int choice;
    while (1)
    {
        printf("-- -- -- -STACK OPERATIONS-- -- --\n");
        printf("\n 1.push\n 2.pop\n 3.palindrome\n 4.display\n 5.exit\n");
        printf("Enter choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            palindrome();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    }
}
void push()
{
    if (top == MAX - 1)
        printf("stack overflow");
    else
    {
        printf("Enter the item to be pushed\n");
        scanf("%d", &item);
        top = top + 1;
        stack[top] = item;
    }
}
void pop()
{
    if (top == -1)
        printf("stack underflow");
    else
    {
        item = stack[top];
        top = top - 1;
        printf("deleted item is %d", item);
    }
}
void display()
{
    int i;
    if (top ==
        -1)
        printf("stack is empty");
    else
    {
        for (i = top; i >= 0; i--)
            printf("%d\t", stack[i]);
    }
}
void palindrome()
{
    int num[10], i = 0, k, flag = 1;
    k = top;
    while (k != -1)
        num[i++] = stack[k--];
    for (i = 0; i <= top; i++)
    {
        if (num[i] == stack[i])
            continue;
        else
            flag = 0;
    }
    if (top == -1)
        printf("stack is empty");
    else
    {
        if (flag)
            printf("palindrome");
        else
            printf("not a palindrome");
    }
}