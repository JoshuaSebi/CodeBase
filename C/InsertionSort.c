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
void insort( int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int key=a[i];
        while(j>=0 && key<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        j++;
        a[j]=key;
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
    insort(t1);
    display(t1);
    return 0;
}