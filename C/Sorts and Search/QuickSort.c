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

int partition(int l, int r)
{
    int pivot=a[l];
    int start=l,stop=r;
    while(start<stop)
    {
        while(start<=r && a[start]<=pivot)
        {
            start++;
        }
        while(stop>=l && a[stop]>pivot)
        {
            stop--;
        }
        if(start<stop)
        {
            swap(&a[start],&a[stop]);
        }
    }
    swap(&a[l],&a[stop]);
    return stop;
}

void QuickSort( int lb,int ub)
{
    if(lb<ub)
    {
        int pos=partition(lb,ub);
        QuickSort(lb,pos-1);
        QuickSort(pos+1,ub);
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
    QuickSort(0,t1-1);
    display(t1);
    return 0;
}