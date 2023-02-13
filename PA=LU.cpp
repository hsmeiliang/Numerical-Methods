#include<stdio.h>
#include<math.h>

int main()

{

    double b[4][4],x1[4],x2[4];
    double l1[4][4],l[4][4];
    double u[4][4],m,n;
    double p1[4][4],p2[4][4],p3[4][4],pp[4][4],p[4][4];
    double c[4],t[4];
    int i,j,k;
    int x=4;
    printf("Input A\n");
    for(i=0; i<x; i++)
    {
        for(j=0; j<x; j++)
            scanf("%lf",&b[i][j]);
    }

    printf("Input b\n");

       for(j=0;j<4;j++)scanf("%lf",&x1[j]);

    for(i=0; i<x; i++)
    {
        for(j=0; j<x; j++)
        {
            p1[i][j]=0.0;
            p2[i][j]=0.0;
            p3[i][j]=0.0;
            if(i==j)
            {
                p1[i][j]=1.0;
                p2[i][j]=1.0;
                p3[i][j]=1.0;
            }
        }
    }

    for(i=0; i<x; i++)
    {
        for(j=0; j<x; j++)
        {
            l1[i][j]=0.0;
            l[i][j]=0.0;
            if(i==j)
            {
                l1[i][j]=1.0;
                l[i][j]=1.0;
            }
        }
    }
    if((fabs(b[0][0])>=fabs(b[1][0]))&&(fabs(b[0][0])>=fabs(b[2][0]))&&(fabs(b[0][0])>=fabs(b[3][0])))goto A;

    else if((fabs(b[1][0])>=fabs(b[0][0]))&&(fabs(b[1][0])>=fabs(b[2][0]))&&(fabs(b[1][0])>=fabs(b[3][0])))

    {
        for(i=0; i<x; i++)
        {
            m=b[0][i];
            b[0][i]=b[1][i];
            b[1][i]=m;

            n=p1[0][i];
            p1[0][i]=p1[1][i];
            p1[1][i]=n;
        }
        goto A;
    }

    else if((fabs(b[2][0])>=fabs(b[0][0]))&&(fabs(b[2][0])>=fabs(b[1][0]))&&(fabs(b[2][0])>=fabs(b[3][0])))

    {
        for(i=0; i<x; i++)
        {
            m=b[0][i];
            b[0][i]=b[2][i];
            b[2][i]=m;

            n=p1[0][i];
            p1[0][i]=p1[2][i];
            p1[2][i]=n;
        }
        goto A;
    }

    else if((fabs(b[3][0])>=fabs(b[0][0]))&&(fabs(b[3][0])>=fabs(b[1][0]))&&(fabs(b[3][0])>=fabs(b[2][0])))

    {
        for(i=0; i<x; i++)
        {
            m=b[0][i];
            b[0][i]=b[3][i];
            b[3][i]=m;

            n=p1[0][i];
            p1[0][i]=p1[3][i];
            p1[3][i]=n;
        }
        goto A;
    }//第一次轉換

A:
    for(i=1; i<x; i++)

        for(j=x-1; j>=0; j--)
        {
            l1[i][j]=l1[i][j]-l1[0][j]*b[i][0]/b[0][0];
            b[i][j]=b[i][j]-b[0][j]*b[i][0]/b[0][0];
        }

    if((fabs(b[1][1])>=fabs(b[2][1]))&&(fabs(b[1][1])>=fabs(b[3][1])))goto B;

    else if((fabs(b[2][1])>=fabs(b[1][1]))&&(fabs(b[2][1])>=fabs(b[3][1])))

    {
        for(i=0; i<x; i++)
        {
            m=b[1][i];
            b[1][i]=b[2][i];
            b[2][i]=m;

            n=p2[1][i];
            p2[1][i]=p2[2][i];
            p2[2][i]=n;
        }
        goto B;
    }

    else if((fabs(b[3][1])>=fabs(b[1][1]))&&(fabs(b[3][1])>=fabs(b[2][1])))

    {
        for(i=0; i<x; i++)
        {
            m=b[1][i];
            b[1][i]=b[3][i];
            b[3][i]=m;

            n=p2[1][i];
            p2[1][i]=p2[3][i];
            p2[3][i]=n;
        }
        goto B;
    }//第二次轉換

B:
    for(i=2; i<x; i++)

        for(j=x-1; j>=0; j--)
        {
            l1[i][j]=l1[i][j]-l1[1][j]*b[i][1]/b[1][1];
            b[i][j]=b[i][j]-b[1][j]*b[i][1]/b[1][1];
        }

    if(fabs(b[2][2])>=fabs(b[3][2]))goto C;

    else if(fabs(b[3][2])>=fabs(b[2][2]))

    {
        for(i=0; i<4; i++)
        {
            m=b[2][i];
            b[2][i]=b[3][i];
            b[3][i]=m;

            n=p1[2][i];
            p3[2][i]=p3[3][i];
            p3[3][i]=n;
        }
        goto C;
    }//第三次轉換

C:
    for(j=3; j>=0; j--)
    {
        l1[3][j]=l1[3][j]-l1[2][j]*b[3][2]/b[2][2];
        b[3][j]=b[3][j]-b[2][j]*b[3][2]/b[2][2];
    }

    l[1][0]=0-l1[2][0];
    l[2][0]=0-l1[3][0];
    l[3][0]=0-l1[1][0];

    l[2][1]=0-l1[3][1];
    l[3][1]=0-l1[2][1];

    l[3][2]=0-l1[3][2];

    printf("P matrix:\n");

    for(i=0; i<x; i++)
    {

        for(j=0; j<x; j++)
        {
            pp[i][j]=0.0;
            for(k=0; k<4; k++)pp[i][j]=pp[i][j]+p3[i][k]*p2[k][j];
        }
    }
    //p2[]*p3[]
    for(i=0; i<x; i++)
    {

        for(j=0; j<x; j++)
        {
            p[i][j]=0.0;
            for(k=0; k<x; k++)p[i][j]=p[i][j]+pp[i][k]*p1[k][j];
        }
    }
    //p1[]*(p2[]*p3[])
    for(i=0; i<x; i++)

    {
        for(j=0; j<x; j++)printf("%.2f  ",p[i][j]);
        printf("\n");
    }

    printf("L matrix:\n");

    for(i=0; i<x; i++)
    {
        for(j=0; j<x; j++)printf("%.2f  ",l[i][j]);
        printf("\n");
    }

    printf("U matrix:\n");

    for(i=0; i<x; i++)
    {
        for(j=0; j<x; j++)
        {
            u[i][j]=b[i][j];
            printf("%.2f  ",u[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<x; i++)
    {
        x2[i]=0.0;
        for(k=0; k<x; k++)x2[i]=x2[i]+p[i][k]*x1[k];
    }

    c[0]=x2[0]/l[0][0];
    c[1]=(x2[1]-l[1][0]*c[0])/l[1][1];

    c[2]=(x2[2]-l[2][0]*c[0]-l[2][1]*c[1])/l[2][2];

    c[3]=(x2[3]-l[3][0]*c[0]-l[3][1]*c[1]-l[3][2]*c[2])/l[3][3];

    t[3]=c[3]/u[3][3];
    t[2]=(c[2]-u[2][3]*t[3])/u[2][2];

    t[1]=(c[1]-u[1][3]*t[3]-u[1][2]*t[2])/u[1][1];

    t[0]=(c[0]-u[0][3]*t[3]-u[0][2]*t[2]-u[0][1]*t[1])/u[0][0];

    printf("x:\n");

    for(i=0; i<x; i++)printf("%.2f  ",t[i]);

    return 0;

}

