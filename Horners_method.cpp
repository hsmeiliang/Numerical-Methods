#include<stdio.h>

float Q2(int a[],int n,float x)
{
	float result=a[n];
	for(int i=n-1;i>=0;i--)
	{
		result=result*x+a[i];
	}return result;
}

int main()
{
	int a1[6]={1,-3,1,-3,-1,8};
	int a2[51]={};
	for(int i=0;i<51;i++)
	{
		a2[i]=1;
	}
	printf("x=-0.5=>%f\n",Q2(a1,5,-0.5));
	printf("x=1.0001=>%f\n",Q2(a2,49,1.0001));
	printf("x=0.5=>%f\n",Q2(a2,49,0.5));
}
