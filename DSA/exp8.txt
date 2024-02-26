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
    int ssn;
    char name[50], dept[20], desg[20];
    float sal;
    unsigned long long int phno;
    struct node *llink, *rlink;
};
struct node *first = NULL, *last = NULL, *temp;
main()
{
    int ch, n, i;
    while (1)
    {
        printf("1.create\n 2.insert_front\n 3.insert_rear\n 4.display\n 5.delete_front\n 6.delete_rear\n 7.exit\n");
        printf("enter choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the number of employee\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                insert_rear();
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
    int ssn;
    char name[50], dept[20], desg[20];
    float sal;
    unsigned long long int phno;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->llink = temp->rlink = NULL;
    printf("enter ssn,name,dept,desg,salaryand phno\n");
    scanf("%d%s%s%s%f%llu", &ssn, name, dept, desg, &sal, &phno);
    temp->ssn = ssn;
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->desg, desg);
    temp->sal = sal;
    temp->phno = phno;
    count++;
}
void insert_front()
{
    if (first == NULL)
    {
        create();
        first = temp;
        last = temp;
    }
    else
    {
        create();
        temp->rlink = first;
        first->llink = temp;
        first = temp;
    }
}
void insert_rear()
{
    if (first == NULL)
    {
        create();
        first = temp;
        last = temp;
    }
    else
    {
        create();
        last->rlink = temp;
        temp->llink = last;
        temp->rlink = NULL;
        last = temp;
    }
}
void display()
{
    struct node *p;
    if (first == NULL)
    {
        printf("list is empty\n");
        return;
    }
    p = first;
    printf("contents of list\n");
    while (p != NULL)
    {
        printf("%d\t%s\t%s\t%s\t%f\t%llu\n", p->ssn, p->name, p->dept, p->desg, p->sal, p->phno);
        p = p->rlink;
    }
    printf("total no. of employee %d\n", count);
}
void delete_front()
{
    struct node *p;
    if (first == NULL)
    {
        printf("list is empty,cannot delete\n");
    }
    else if (first->rlink == NULL)
    {
        printf("deleted data is %d\t%s\t%s\t%s\t%f\t%llu\n", first->ssn, first->name, first->dept, first->desg, first->sal, first->phno);
        first = NULL;
        free(first);
        count--;
    }
    else
    {
        p = first;
        first = p->rlink;
        printf("deleted data is %d\t%s\t%s\t%s\t%f\t%llu\n", p->ssn, p->name, p->dept, p->desg, p->sal, p->phno);
        free(p);
        count--;
    }
}
void delete_rear()
{
    struct node *p;
    if (first == NULL)
    {
        printf("list is empty,cannot delete\n");
    }
    else if (first->rlink == NULL)
    {
        printf("deleted data is %d\t%s\t%s\t%s\t%f\t%llu\n", first->ssn, first->name, first->dept, first->desg, first->sal, first->phno);
        first = NULL;
        free(first);
        count--;
    }
    else
    {
        p = last;
        last = p->llink;
        printf("deleted data is %d\t%s\t%s\t%s\t%f\t%llu\n", p->ssn, p->name, p->dept, p->desg, p->sal, p->phno);
        free(p);
        last->rlink = NULL;
        count--;
    }
}
