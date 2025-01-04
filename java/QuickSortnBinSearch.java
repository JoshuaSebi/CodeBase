import java.util.*;

class Qsort
{
    int partition(int[] arr, int l, int r)
    {
        int start=l,stop=r;
        int key=arr[l];
        while(start<stop)
        {
            while(start<r && arr[start]<=key)
            {
                start++;
            }
            while(stop>l && arr[stop]>key)
            {
                stop--;
            }
            if(start<stop)
            {
                int temp=arr[start];
                arr[start]=arr[stop];
                arr[stop]=temp;
            }
        }
        int temp=arr[l];
        arr[l]=arr[stop];
        arr[stop]=temp;
        return stop;
    }

    void QuickSort(int[] arr, int l,int r)
    {
        if(l<=r)
        {
            int pos=partition(arr,l,r);
            QuickSort(arr, l,pos-1);
            QuickSort(arr, pos+1, r);
        }
    }
}

class BinSearch{
    int l,r,mid;
    BinSearch(int l,int r)
    {
        this.l=l;
        this.r=r;
    }

    int binSearch(int[] a,int key,int l,int r)
    {
        while(l<r)
        {
            mid=(l+r)/2;
            if(key==a[mid])
            {
                return mid;
            }
            else if(key<a[mid])
            {
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
}

public class QuickSortnBinSearch {
    public static void main(String[] args) {
        int[] array=new int[5];
        Scanner sc=new Scanner(System.in);
        for (int i=0;i<5;i++)
        {
            int e=sc.nextInt();
            array[i]=e;
        }
        Qsort qs=new Qsort();
        qs.QuickSort(array, 0, 4);
        for (int i=0;i<5;i++)
        {
            System.out.print(array[i]+"   ");
        }
        System.out.print("Enter key to search: ");
        int key=sc.nextInt();
        BinSearch bs=new BinSearch(0,4);
        int res=bs.binSearch(array,key,0,(array.length-1));
        if(res!=-1)
        {
            System.out.println("Element found at index "+res);
        }
        else{
            System.out.println("Element not found");
        }
    }
}
