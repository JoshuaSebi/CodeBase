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

void swap(int *a, int *b)
{
    int temp= *a;
    *a=*b;
    *b=temp;
}

int heapify(int n, int i)
{
    int temp,largest=i;
    int ln=2*i+1;
    int rn=2*i+2;
    if (ln<n && a[largest]<a[ln])
        largest=ln;
    if (rn<n && a[largest]<a[rn])
        largest=rn;
    if(largest!=i)
    {
        swap(&a[largest],&a[i]);
        heapify(n,largest);
    }
}

void HeapSort( int l,int r)
{
    int n=r+1;
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(n,i);
    }
    for (int i=n-1;i>0;i--)
    {
        swap(&a[0],&a[i]);
        heapify(i,0);
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
    HeapSort(0,t1-1);
    display(t1);
    return 0;
}