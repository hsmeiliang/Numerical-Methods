
//fit exponential
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{

    int i;
    float Y[20],sumx=0,sumy=0,sumxy=0,sumx2=0;
    float a,b,A;

    int n=4;
    float x[4]={1960-1960,1970-1960,1990-1960,2000-1960};
    float y[4]={3039585530,3707475887,5281653820,6079603571};
    for(i=0;i<=n-1;i++)
    {
        Y[i]=log(y[i]);
    }
    for(i=0;i<=n-1;i++)
    {
        sumx=sumx +x[i];
        sumx2=sumx2 +x[i]*x[i];
        sumy=sumy +Y[i];
        sumxy=sumxy +x[i]*Y[i];

    }
    A=((sumx2*sumy -sumx*sumxy)*1.0/(n*sumx2-sumx*sumx)*1.0);
    b=((n*sumxy-sumx*sumy)*1.0/(n*sumx2-sumx*sumx)*1.0);
    a=exp(A);
    float ans=0;
    ans=a*exp(b*(1980-1960));
    printf("%f, %f, %f",ans,a,b);
    return(0);
}

//fit linear

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{

    int n,i,x[20],y[20],sumx=0,sumy=0,sumxy=0,sumx2=0;
    float a,b;
    printf("\n   C program for Linear Curve Fitting \n ");
    printf("\n Enter the value of number of terms n:");
    scanf("%d",&n);
    printf("\n Enter the values of x:\n");
    for(i=0;i<=n-1;i++)
    {
        scanf(" %d",&x[i]);

    }
    printf("\n Enter the values of y:");
    for(i=0;i<=n-1;i++)
    {
        scanf("%d",&y[i]);
    }
    for(i=0;i<=n-1;i++)
    {
        sumx=sumx +x[i];
        sumx2=sumx2 +x[i]*x[i];
        sumy=sumy +y[i];
        sumxy=sumxy +x[i]*y[i];

    }
    a=((sumx2*sumy -sumx*sumxy)*1.0/(n*sumx2-sumx*sumx)*1.0);
    b=((n*sumxy-sumx*sumy)*1.0/(n*sumx2-sumx*sumx)*1.0);
    printf("\n\nThe line is Y=%3.3f +%3.3f X",a,b);
    return(0);
}
