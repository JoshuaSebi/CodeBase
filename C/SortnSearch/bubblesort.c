#include<stdio.h>

int main()
{
    int n,i,j,flag,temp;
    printf("Enter number of elements: ");
    scanf("%2d",&n);                             //Accepting elementS//
    int a[n];
    printf("Enter elements\n ");
    for (i=0;i<n;i++)
    {
        scanf("\t%d",&a[i]);
    }
    for(i=0;i<n-1;i++)                          //Outer loop//
    {
        flag=0;
        for(j=0;j<n-1-i;j++)                    //Inner loop//
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
        if (flag==0)
            break;
    }
    printf("Sorted array: ");
    for (i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    printf("\n"); 
}