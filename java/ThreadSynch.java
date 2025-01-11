import java.util.*;

class printer
{
    String S="Hello World";
    synchronized public String returnString()
    {
        return S;
    }
    synchronized public void addString(String S)
    {
        this.S=S;
    } 
}

class threadread extends Thread
{
    printer p;
    String s="";
    threadread(printer p)
    {
        this.p=p;
    }
    public void run()
    {
        try (Scanner sc = new Scanner(System.in)) {
            while(!s.equalsIgnoreCase("stop"))
            {
                System.out.println("Enter String: ");
                s=sc.nextLine();
                p.addString(s);
                try
            {
                Thread.sleep(5000);
            }
            catch(Exception e)
            {
                System.out.println(e);
            }
            }
        }
        
    }
}

class threadprint extends Thread{
    printer p;
    String s="";
    threadprint(printer p)
    {
        this.p=p;
    }
    public void run()
    {
        while(!s.equalsIgnoreCase("stop"))
        {
            s=p.returnString();
            System.out.println(s+'\n');
            try
        {
            Thread.sleep(5000);
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
        }
    }
}

public class ThreadSynch 
{
    public static void main(String[] args) {
        printer p=new printer();
        threadprint tp=new threadprint(p);
        threadread tr=new threadread(p);
        tp.start();
        tr.start();
    }
}
