#include<stdio.h>
#include<math.h>
#include<cmath>

double fpi1(double x)
{
    double y=0;
    y=(sin(x)-5)/6;
    return y;
}

double fpi2(double x)
{
    double y=0;
    double p=1.0/3.0;
    y=pow(2*x+2,p);
    return y;
}


int main()
{
    double x1=1,p1=1.5;
	double x2=2,p2=2.5;
    
    while(true)
    {
    	x1=fpi1(x1);
        if(fabs(x1-p1)<0.000001)break;
		p1=x1;
        
        
    }
    
    while(true)
    {
    	x2=fpi2(x2);
        if(fabs(x2-p2)<0.000001)break;
		p2=x2;
        
        
    }
    printf("Q1: %.4lf\n",x1);
    printf("Q2: %.4lf\n",x2);
}
