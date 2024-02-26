#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void create();
void insert_front();
void insert_rear();
void display();
void delete_front();
void delete_rear();
int count = 0;
struct node
{
    char usn[20], name[50], branch[10];
    int sem;
    unsigned long long int phno;
    struct node *link;
};
struct node *first = NULL, *last = NULL, *temp = NULL, *p;
void main()
{
    int ch, n, i;
    while (1)
    {
        printf("1.create SLL 2.insert at front 3.insert at rear 4.display 5.delete at front 6.delete at rear 7.exit\n");
        printf("enter choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the no.of students\n");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
                insert_front();
            break;
        case 2:
            insert_front();
            break;
        case 3:
            insert_rear();
            break;
        case 4:
            display();
            break;
        case 5:
            delete_front();
            break;
        case 6:
            delete_rear();
            break;
        case 7:
            exit(0);
        default:
            printf("invalid choice\n");
            break;
        }
    }
}
void create()
{
    char usn[20], name[50], branch[10];
    int sem;
    unsigned long long int phno;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("enter usn,name,branch,sem,phno\n");
    scanf("%s%s%s%d%llu", usn, name, branch, &sem, &phno);
    strcpy(temp->usn, usn);
    strcpy(temp->name, name);
    strcpy(temp->branch, branch);
    temp->sem = sem;
    temp->phno = phno;
    count++;
}
void insert_front()
{
    if (first == NULL)
    {
        create();
        temp->link = NULL;
        first = temp;
        last = temp;
    }
    else
    {
        create();
        temp->link = first;
        first = temp;
    }
}
void insert_rear()
{
    if (first == NULL)
    {
        create();
        temp->link = NULL;
        first = temp;
        last = temp;
    }
    else
    {
        create();
        temp->link = NULL;
        last->link = temp;
        last = temp;
    }
}
void display()
{
    if (first == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        p = first;
        printf("content of list is\n");
        while (p != NULL)
        {
            printf("%s\t%s\t%s\t%d\t%llu\n", p->usn, p->name, p->branch, p->sem, p->phno);
            p = p->link;
        }
        printf("total no.of students %d\n", count);
    }
}
void delete_front()
{
    p = first;
    if (first == NULL)
    {
        printf("list is empty\n");
    }
    else if (p->link == NULL)
    {
        printf("deleted node is %s\t%s\t%s\t%d\t%llu\n", p->usn, p->name, p->branch, p->sem, p->phno);
        free(p);
        first = NULL;
        count--;
    }
    else
    {
        first = p->link;
        printf("deleted node is %s\t%s\t%s\t%d\t%llu\n", p->usn, p->name, p->branch, p->sem, p->phno);
        free(p);
        count--;
    }
}
void delete_rear()
{
    p = first;
    if (first == NULL)
    {
        printf("list is empty\n");
    }
    else if (p->link == NULL)
    {
        printf("deleted node is %s\t%s\t%s\t%d\t%llu\n", p->usn, p->name, p->branch, p->sem, p->phno);
        free(p);
        first = NULL;
        count--;
    }
    else
    {
        while (p->link != last)
            p = p->link;
        printf("deleted node is %s\t%s\t%s\t%d\t%llu\n", last->usn, last->name, last->branch, last->sem, last->phno);
        free(last);
        p->link = NULL;
        last = p;
        count--;
    }
}
