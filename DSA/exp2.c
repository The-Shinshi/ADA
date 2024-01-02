#include <stdio.h>
void read();
void match();
char STR[100], PAT[100], REP[100], ANS[100];
int c, i, j, k, m, flag = 0;
main()
{
    read();
    match();
}

void read()
{
    printf("Enter the main string STR: ");
    gets(STR);
    printf("Enter pattern string PAT: ");
    gets(PAT);
    printf("Enter replace string REP: ");
    gets(REP);
}

void match()
{
    c = i = j = k = m = 0;
    while (STR[c] != '\0')
    {
        if (STR[m] == PAT[i])
        {
            i++;
            m++;
            flag = 1;
            if (PAT[i] == '\0')
            {
                for (k = 0; REP[k] != '\0'; k++, j++)
                {
                    ANS[j] = REP[k];
                }
                i = 0;
                c = m;
            }
        }
        else
        {
            ANS[j] = STR[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }
    if (flag == 0)
    {
        printf("Pattern not found");
    }
    else
    {
        ANS[j] = '\0';
        printf("Resultant string is %s", ANS);
    }
}