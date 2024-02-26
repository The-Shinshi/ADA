#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void display(int a[MAX]);
int create(int num);
void linearprob(int a [MAX],int key,int num);
void main()
{
int a[MAX],i,num,key,ans=1;
printf("collission handling by linear probing\n");
for(i=0;i<MAX;i++)
a[i]= -1;
do
{
printf("enter the data\n");
scanf("%4d",&num);
key=create(num);
linearprob(a,key,num);
printf("do you want to continue[1/0]\n");
scanf("%d",&ans);
}while(ans);
display(a);
}
int create(int num)
{
int key;
key=num%100;
return key;
}
void linearprob(int a[MAX],int key, int num)
{
int flag=0,count=0,i;
if(a[key]==-1)
a[key]=num;
else
{
printf("\n collision deleted\n");
i=0;
while((i<key)&&(flag==0))
{
if(a[i]==-1)
{
a[i]=num;
flag=1;
break;
}
i++;
}
}
}
void display(int a[MAX])
{
int ch,i;
printf("\n 1.display all 2.filtered display\n");
printf("enter choice\n");
scanf("%d",&ch);
if(ch==1)
{
for(i=0;i<MAX;i++)
printf("%d\t %d\n",i,a[i]);
}
else
{
for(i=0;i<MAX;i++)
{
if(a[i]!=-1)
{
printf("%d\t %d\n",i,a[i]);
continue;
}
}
}
}
