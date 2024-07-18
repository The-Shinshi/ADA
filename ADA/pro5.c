#include<stdio.h>
void findindegree(int [10][10],int[10],int);
void topological(int,int [10][10]);
void main ()
{
	int a[10][10],i,j,n;
	printf("Enter the number of nodes:"); 
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
	printf("\nThe adjacency matirx is:\n"); 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	topological(n,a);
}

void findindegree(int a[10][10],int indegree[10],int n){
	int i,j,sum;
	for(j=1;j<=n;j++){
		sum=0;
		for(i=1;i<=n;i++){
			sum=sum+a[i][j];
		}
		indegree[j]=sum;
	}
}

void topological(int n,int a[10][10]){
	int k,top,t[100],i,stack[20],u,v,indegree[20];
	k=1;
	top=-1;
	findindegree(a,indegree,n);
	for(i=1;i<=n;i++){
		if(indegree[i]==0){
			stack[++top]=i;
		}
	}
	while(top!=-1){
		u=stack[top--];
		t[k++]=u;
		for(v=1;v<=n;v++){
			if(a[u][v]==1){
				indegree[v]--;
				if(indegree[v]==0){
					stack[++top]=v;
				}
			}
		}
	}
	printf("\nTopological sequence is\n");
	for(i=1;i<=n;i++)
	printf("%d\t",t[i]);
}
