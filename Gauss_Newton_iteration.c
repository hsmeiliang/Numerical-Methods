#include<stdio.h>
#include<math.h>

void Gauss(double D[4][3],double v[4],double r[4],double h,double k)
{
    double c=0,sum=0;
    int i=0,j=0,l=0;
    int n=3,m=2;
    //x-x1
    D[1][1]=(h+1)/pow(pow(h+1,2)+pow(k,2),0.5);
    D[1][2]=(k)/pow(pow(h+1,2)+pow(k,2),0.5);
    r[1]=pow(pow(h+1,2)+pow(k,2),0.5)-1;//r1

    D[2][1]=(h-1)/pow(pow(h-1,2)+pow(k-1,2),0.5);
    D[2][2]=(k-1)/pow(pow(h-1,2)+pow(k-1,2),0.5);
    r[2]=pow(pow(h-1,2)+pow(k-1,2),0.5)-1;//r2

    D[3][1]=(h-1)/pow(pow(h-1,2)+pow(k+1,2),0.5);
    D[3][2]=(k+1)/pow(pow(h-1,2)+pow(k+1,2),0.5);
    r[3]=pow(pow(h-1,2)+pow(k+1,2),0.5)-1;//r3

    double DT[3][4]= {};
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            DT[i][j]=D[j][i];
        }

    double A[3][4]= {};

    for(i=1; i<=m; i++)
        for(j=1; j<=m; j++)
        {
            A[i][j]=0;
            for(l=1; l<=n; l++)
            {
                A[i][j]=A[i][j]+DT[i][l]*D[l][j];
            }
        }
    for(i=1; i<=m; i++)
    {
        A[i][3]=0;
        for(j=1; j<=n; j++)
        {
            A[i][3]=A[i][3]-DT[i][j]*r[j];
        }
    }
    n=2;
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                c=A[i][j]/A[j][j];
                for(l=1; l<=n+1; l++)
                {
                    A[i][l]=A[i][l]-c*A[j][l];
                }
            }
        }
    }
    v[n]=A[n][n+1]/A[n][n];
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+A[i][j]*v[j];
        }
        v[i]=(A[i][n+1]-sum)/A[i][i];
    }
}


int main()
{
    double Df[4][3]= {},r[4]= {},v[4]= {};
    double x=7,y=7;
    int a=0;
    for( a=0; a<10000; a++)
    {
        Gauss(Df,v,r,x,y);
        x=x+v[1];
        y=y+v[2];
    }
    printf("x=%.4f  y=%.4f",x,y);

}
