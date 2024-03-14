#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int co, ex, ey, ez;
    struct node *link;
};
typedef struct node NODE;
NODE *createnode(int, int, int, int);
NODE *attachnode(NODE *, NODE *);
NODE *readpoly();
void display(NODE *);
void evaluate(NODE *);
NODE *addpoly(NODE *, NODE *, NODE *);
NODE *createnode(int co, int ex, int ey, int ez)
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->co = co;
    temp->ex = ex;
    temp->ey = ey;
    temp->ez = ez;
    temp->link = NULL;
    return temp;
}
NODE *attachnode(NODE *temp, NODE *head)
{
    NODE *cur;
    cur = head->link;
    while (cur->link != head)
    {
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = head;
    return head;
}
NODE *readpoly()
{
    int i, n, co, ex, ey, ez;
    NODE *head = (NODE *)malloc(sizeof(NODE));
    NODE *temp;
    head->link = head;
    printf("enter the number of terms\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("term %d\n", i + 1);
        printf("enter the coefficient\n");
        scanf("%d", &co);
        printf("enter exponent values of x,yand z\n");
        scanf("%d%d%d", &ex, &ey, &ez);
        temp = createnode(co, ex, ey, ez);
        head = attachnode(temp, head);
    }
    return head;
}
void display(NODE *poly)
{
    NODE *cur;
    cur = poly->link;
    while (cur != poly)
    {
        printf("%dx^%dy^%dz^%d+", cur->co, cur->ex, cur->ey, cur->ez);
        cur = cur->link;
    }
    printf("\n");
}
void evaluate(NODE *poly)
{
    NODE *cur;
    int x, y, z, res = 0;
    cur = poly->link;
    printf("enter the values of x,y,z\n");
    scanf("%d%d%d", &x, &y, &z);
    while (cur != poly)
    {
        res += cur->co * pow(x, cur->ex) * pow(y, cur->ey) * pow(z, cur->ez);
        cur = cur->link;
    }
    printf("result=%d\n", res);
}
NODE *addpoly(NODE *p1, NODE *p2, NODE *poly)
{
    int comp;
    NODE *a, *b, *temp;
    a = p1->link;
    b = p2->link;
    while (a != p1 && b != p2)
    {
        if (a->ex == b->ex && a->ey == b->ey && a->ez == b->ez)
            comp = 0;
        else if (a->ex > b->ex)
            comp = 1;
        else if (a->ex == b->ex && a->ey == b->ey)
            comp = 1;
        else if (a->ex == b->ex && a->ey == b->ey && a->ez > b->ez)
            comp = 1;
        else
            comp = -1;
        switch (comp)
        {
        case 0:
            temp = createnode(a->co + b->co, a->ex, a->ey, a->ez);
            poly = attachnode(temp, poly);
            a = a->link;
            b = b->link;
            break;
        case 1:
            temp = createnode(a->co, a->ex, a->ey, a->ez);
            poly = attachnode(temp, poly);
            a = a->link;
            break;
        case -1:
            temp = createnode(b->co, b->ex, b->ey, b->ez);
            poly = attachnode(temp, poly);
            b = b->link;
            break;
        }
    }
    while (a != p1)
    {
        temp = createnode(a->co, a->ex, a->ey, a->ez);
        poly = attachnode(temp, poly);
        a = a->link;
    }
    while (b != p2)
    {
        temp = createnode(b->co, b->ex, b->ey, b->ez);
        poly = attachnode(temp, poly);
        b = b->link;
    }
    return poly;
}
main()
{
    int ch;
    NODE *p1, *p2, *p3;
    p3 = (NODE *)malloc(sizeof(NODE));
    p3->link = p3;
    while (1)
    {
        printf("1.represent and evaluate 2.add two polynomial 3.exit\n");
        printf("enter choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter a polynomial\n");
            p1 = readpoly();
            display(p1);
            evaluate(p1);
            break;
        case 2:
            printf("enter polynomial 1\n");
            p1 = readpoly();
            display(p1);
            printf(" enter polynomial 2\n");
            p2 = readpoly();
            display(p2);
            p3 = addpoly(p1, p2, p3);
            printf("the resultant polynomial is\n");
            display(p3);
            break;
        case 3:
            exit(0);
        default:
            printf("invalid choice\n");
            break;
        }
    }
}
