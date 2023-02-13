#include<stdio.h>
#include<cmath>


double Q1(double x)
{
    return pow(x/(x+1),4)-2*pow(x,4)+1;
}
double Q1d(double x)
{
    return 4*pow(x/(x/1),3)*((x+1-x)/pow(x+1,2))+(-8)*pow(x,3);
}
double Q2(double x)
{
    return 6*x+10-sin(x);
}
double Q2d(double x)
{
    return 6-cos(x);
}
double Q3(double x)
{
    return log(x)+2*pow(x,2)-3;
}
double Q3d(double x)
{
    return (1/x)+4*x;
}
double N(double x0,double (*Q1)(double),double (*Q1d)(double),double e)
{
    double x=x0;
    do{
        x0=x;
        x=x0-Q1(x0)/Q1d(x0);
    }while(fabs(x-x0)>e);
    return x;
}
int main()
{
    const double e=1E-9;

    double x1=0,x0=0,x2=0,x3=0;

    x0=3;
    x1=N(x0,Q1,Q1d,e);
    x2=N(x0,Q2,Q2d,e);
    x3=N(x0,Q3,Q3d,e);
    printf("Q1=%.4lf\nQ2=%.4lf\nQ3=%.4lf\n",x1,x2,x3);
}




