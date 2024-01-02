#include <stdio.h>
#include <stdlib.h>
#define MAX 5
char q[MAX], item;
int f = 0, r = -1, count = 0;
void insert();
void delete();
void display();
main()
{
    int ch;
    while (1)
    {
        printf("1.insert 2.delete 3.display 4.exit \n");
        printf("enter choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            getchar();
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
void insert()
{
    if (count == MAX)
        printf("queue overflow\n");
    else
    {
        printf("enter the item to be inserted\n");
        scanf("%c", &item);
        r = (r + 1) % MAX;
        q[r] = item;
        count++;
    }
}
void delete()
{
    if (count == 0)
        printf("queue underflow\n");
    else
    {
        printf("deleted item is %c\n", q[f]);
        f = (f + 1) % MAX;
        count--;
    }
}
void display()
{
    int j = f, i;
    if (count == 0)
        printf("queue is empty\n");
    else
    {
        printf("contents of circular queue\n");
        for (i = 1; i <= count; i++)
        {
            printf("%c\t", q[j]);
            j = (j + 1) % MAX;
        }
        printf("total number of items=%d\n", count);
    }
}
