import java.util.*;

//implements Runnable interface
class RandInt implements Runnable
{
    int n;
    RandInt(int num){
        this.n=num;
    }
    public void run()
    {
        for(int i=0;i<n;i++)
        {
            Random rn=new Random();
            int rdm=rn.nextInt(100);
            if(rdm%2==0)
            {
                SqThread sthr=new SqThread(rdm);
                sthr.start();
            }
            else{
                CuThread cthr=new CuThread(rdm);
                cthr.start();
            }
            try {
                Thread.sleep(500);
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }      
    }
}

//Extends thread class
class SqThread extends Thread
{
    int n;
    SqThread(int num)
    {
        n=num;
    }
    public void run()
    {
        System.out.println("("+n+")^2 = "+n*n);
    }
}

class CuThread extends Thread
{
    int n;
    CuThread(int num)
    {
        n=num;
    }
    public void run()
    {
        System.out.println("("+n+")^3 = "+n*n*n);
    }
}

public class RandomThread {
    public static void main(String[] args) {
        int t;
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter Number: ");
            t=sc.nextInt();
        }
        RandInt rdi=new RandInt(t);
        /*create object of thread class since 
        rdi implements Runnable Interface*/
        Thread th=new Thread(rdi); 
        th.start();
    }
}
