#include <stdio.h>
#include <math.h>
using namespace std;

void lu(float a[][4],float l[][4],float u[][4],int n)
{
    int i=0,j=0,k=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(j<i)
                l[j][i]=0;
            else
            {
                l[j][i]=a[j][i];
                for(k=0; k<i; k++)
                {
                    l[j][i]=l[j][i]-l[j][k]*u[k][i];
                }
            }
        }
        for(j=0; j<n; j++)
        {
            if(j<i)
                u[i][j]=0;
            else if(j==i)
            u[i][j]=1;
            else
            {
                u[i][j]=a[i][j]/l[i][i];
                for(k=0; k<i; k++)
                {
                    u[i][j]=u[i][j]-((l[i][k]*u[k][j])/l[i][i]);
                }
            }
        }
    }
}

void output(float x[][4],int n)
{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("  %.4f",x[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    float b[4][4],l[4][4],u[4][4];
    int x=0,i=0,j=0;
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        for(j=0;j<x;j++)
        {
            scanf("%f",&b[i][j]);
        }
    }
    lu(b,l,u,x);
    printf("L matrix:\n");
    output(l,x);
    printf("U matrix:\n");
    output(u,x);
}
