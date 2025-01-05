#include <stdio.h>

int a[15];

void insert(int t)
{
    printf("Enter elements\n");
    for(int i=0;i<t;i++)
    {
        scanf("%d",&a[i]);
    }
}


int merge(int l, int m, int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)
    {
        L[i]=a[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        R[j]=a[m+1+j];
    }
    int i=0,j=0;
    int k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}

void MergeSort( int l,int r)
{
    if (l<r)
    {
        int mid=(l+r)/2;
        MergeSort(l,mid);
        MergeSort(mid+1,r);
        merge(l,mid,r);
    }
}

void display(int t)
{
    for(int i=0;i<t;i++)
    {
        printf("%d\t",a[i]);
    }    
}

int main() {
    int t1;
    printf("Enter no of terms : ");
    scanf ("%d",&t1);
    insert(t1);
    MergeSort(0,t1-1);
    display(t1);
    return 0;
}