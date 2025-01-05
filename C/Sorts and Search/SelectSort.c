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
void SelectionSort( int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if (a[min]>a[j])
            {
                min=j;
            }
        }
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;
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
    SelectionSort(t1);
    display(t1);
    return 0;
}