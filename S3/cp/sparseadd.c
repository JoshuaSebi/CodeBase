#include <stdio.h>

int sparse(int r,int c, int a[][5])
{
          int i,j,k=0,e;
          a[0][0]=r;
          a[0][1]=c;
          printf("Enter Elements: ");
          for(i=0;i<r;i++)
          {
                for(j=0;j<c;j++)
                {
                    scanf("%d",&e);
                    if (e!=0)
                    {
                        k=k+1;
                        a[k][0]=i;
                        a[k][1]=j;
                        a[k][2]=e;
                    }
                }
          }
          a[0][2]=k;
          return k+1;
}

int disp(int r, int c, int a[][5])
{
    for (int i=0;i<r;i++)
    {
            for (int j=0;j<c;j++)
            {
                printf("%d\t",a[i][j]);
            }
            printf("\n");
    }
}

int addn(int ra, int rb,int r, int c , int a[][5],int b[][5],int s[][5])
{
    int i=1,j=1,k=0;
    s[0][0]=r;
    s[0][1]=c;
    while (i<ra && j<rb)
    {
        if(a[i][0]==b[j][0])
        {
            if(a[i][1]==b[j][1])
            {
                k=k+1;
                s[k][0]=a[i][0];
                s[k][1]=a[i][1];
                s[k][2]=a[i][2]+b[j][2];
                i++;
                j++;

            }

            else if (a[i][1]>b[j][1])
            {
                k=k+1;
                s[k][0]=b[j][0];
                s[k][1]=b[j][1];
                s[k][2]=b[j][2];
                j++;
            }
            else
            {
                k=k+1;
                s[k][0]=a[i][0];
                s[k][1]=a[i][1];
                s[k][2]=a[i][2];
                i++;
            }
        }
        else if (a[i][0]>b[j][0])
        {
            k=k+1;
            s[k][0]=b[j][0];
            s[k][1]=b[j][1];
            s[k][2]=b[j][2];
            j++;
        }

        else
        {
            k=k+1;
            s[k][0]=a[i][0];
            s[k][1]=a[i][1];
            s[k][2]=a[i][2];
            i++;
        } 
    }
    //Add remaining elements
    while(i<ra)
    {
        k=k+1;
        s[k][0]=a[i][0];
        s[k][1]=a[i][1];
        s[k][2]=a[i][2];
        i++;
    }
    while(j<rb)
    {
        k=k+1;
        s[k][0]=b[j][0];
        s[k][1]=b[j][1];
        s[k][2]=b[j][2];
        j++;        
    }
    s[0][2]=k;
    return k+1;

}

int main()
{
    int m1[10][5],m2[10][5],m3[10][5];
    int r1,r2,c1,c2;
    printf("Enter Row & Column of matrix A: ");
    scanf("%d%d",&r1,&c1);
    int k1= sparse(r1,c1,m1);
    printf("Matrix A\n");
    disp(k1,3,m1);
    printf("----------------------------\n");
    printf("Enter Row & Column of matrix B: ");
    scanf("%d%d",&r2,&c2);
    int k2= sparse(r2,c2,m2);
    printf("Matrix B\n");
    disp(k2,3,m2);
    printf("----------------------------\n");
    if (r1!=r2 || c1!=c2)
    {
        printf("Addition not possible");
    }
    else
    {
        int k3=addn(k1,k2,r1,c1,m1,m2,m3);
        disp(k3,3,m3);
    }


}