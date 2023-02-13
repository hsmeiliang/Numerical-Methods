#include<stdio.h>

double language(double a,double x[],double y[],int n)
{
    double t=1,s=1,b=0;
    for(int j=0;j<n;j++)
    {
        s=1;t=1;
        for(int i=0;i<n;i++)
        {
            if(i!=j)
            {
                t=t*(a-x[i]);
                s=s*(x[j]-x[i]);
            }
        }
        b=b+y[j]*t/s;
    }
    return b;
}

int main()
{
    double x[100]={0},y[100]={0};
    double a=0,b=0;
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%lf %lf",&x[i],&y[i]);
    }
    printf("input\n");
    scanf("%lf",&a);
    b=language(a,x,y,n);
    printf("%lf",b);
}
