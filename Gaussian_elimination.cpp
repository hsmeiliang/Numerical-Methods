#include<stdio.h>

void Gauss(float A[10][10])
{
    float c=0,sum=0,x[10]={0};
    int i=0,j=0,k=0;
    int n=4,m=5;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%f",&A[i][j]);
        }
    }

    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    x[n]=A[n][n+1]/A[n][n];
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+A[i][j]*x[j];
        }
        x[i]=(A[i][n+1]-sum)/A[i][i];
    }
    printf("x=%f y=%f z=%f w=%f",x[1],x[2],x[3],x[4]);
}


int main()
{
    float A[10][10];

    Gauss(A);



}
