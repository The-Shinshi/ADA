#include <stdio.h>
void tower(int n, char frompeg, char topeg, char auxpeg);
int
    n;
void main()
{
    printf("Enter the no. of discs: \n");
    scanf("%d", &n);
    printf("the number of moves in tower of henoi problem\n");
    tower(n, 'A', 'C', 'B');
}
void tower(int n, char frompeg, char topeg, char auxpeg)
{
    if (n == 1)
    {
        printf("move disk1 from %C to %C\n ", frompeg, topeg);
        return;
    }
    tower(n - 1, frompeg, auxpeg, topeg);
    printf("move disk%d from %C to %C\n", n, frompeg, topeg);
    tower(n - 1, auxpeg, topeg, frompeg);
}