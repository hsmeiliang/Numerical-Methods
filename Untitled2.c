#include<stdio.h>
#include<math.h>

double dot(double x[4],double y[4])
{
    int i=0;
    double ans=0;
    for(i=0;i<4;i++)
        ans=ans+x[i]*y[i];
    return ans;
}
void normalize(double x[4])
{
    double norm=sqrt(dot(x,x));
    int i=0;
    for(i=0;i<4;i++)
        x[i]=x[i]/norm;
}

void Gram(double q[][4],int n)
{
    int i=0,j=0,k=0;

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            double s=dot(q[j],q[i])/dot(q[j],q[j]);
            for(k=0;k<4;k++)
                q[i][k]=q[i][k]-s*q[j][k];
        }
    }
    for(i=0;i<n;i++)
        normalize(q[i]);
}

int main()
{
    double A[3][4]={{1,2,3,1},{2,-1,1,1},{2,2,1,-1}};
    int n=3;
    Gram(A,n);

    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%.4lf ",A[i][j]);
            printf("\n");
    }
}
