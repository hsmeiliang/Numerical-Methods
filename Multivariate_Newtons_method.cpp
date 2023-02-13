#include<stdio.h>
#include<math.h>

void Gauss(float A[4][5],float x[4],float h,float k,float r)
{
    float c=0,sum=0;
    int i=0,j=0,l=0;
    int n=3,m=4;

    A[1][1]=2*(1+h);
    A[1][2]=-2*(6-k);
    A[1][3]=-2*r;
    A[1][4]=-1*(pow(1+h,2)+pow(6-k,2)-pow(r,2));

    A[2][1]=2*(2+h);
    A[2][2]=2*(6+k);
    A[2][3]=-2*r;
    A[2][4]=-1*(pow(2+h,2)+pow(6+k,2)-pow(r,2));

    A[3][1]=-2*(5-h);
    A[3][2]=-2*k;
    A[3][3]=-2*r;
    A[3][4]=-1*(pow(5-h,2)+pow(k,2)-pow(r,2));


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
}


int main()
{
    float Df[4][5]={0},x[4]={0};
    float h=1,k=1,r=1;

    for(int a=0;a<10;a++)
    {
        Gauss(Df,x,h,k,r);
        h=h+x[1];
        k=k+x[2];
        r=r+x[3];
    }
    printf("h=%.4f  k=%.4f  r=%.4f",h,k,r);

}
