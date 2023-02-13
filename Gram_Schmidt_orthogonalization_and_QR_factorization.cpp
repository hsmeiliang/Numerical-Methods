#include<stdio.h>
#include<math.h>

int main()
{
    double A[10][10]={};

    int n=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&A[i][j]);
    double q[3][3]={};

    for(int i=0;i<n;i++)
    {
        double y[3]={};
        for(int k=0;k<n;k++)
            y[k]=A[i][k];

        for(int j=0;j<i;j++)
        {
            double t[3]={};

                double x=0;

    for(int w=0;w<3;w++)
        x=x+q[j][w]*A[i][w];
    for(int w=0;w<3;w++)
        t[w]=q[j][w]*x;

            for(int k=0;k<n;k++)
            {
                y[k]=y[k]-t[k];
            }
        }

        double r=0;
        for(int k=0;k<n;k++)
            r=r+pow(y[k],2);
        r=sqrt(r);
        for(int j=0;j<n;j++)
            q[i][j]=y[j]/r;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%.4f ",q[i][j]);
        printf("\n");
    }
}
