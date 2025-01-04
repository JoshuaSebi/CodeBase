import java.util.*;
import java.io.*;

class ABC
{
    void print(int c)
    {
        System.out.println("Count in parent: "+c);
    }
}
class frequency extends ABC{
    String s;
    char c;
    frequency(String s,char c)
    {
        this.s=s;
        this.c=c;
    }
    int count()
    {
        int num=0;
        int len=s.length();
        for(int i=0;i<len;i++)
        {
            if(c==s.charAt(i))
            {
                num++;
            }
        }
        return num;
    }
    void print(int c)
    {
        System.out.println("Count in child: "+c);
    }

}

public class charFreq {
    public static void main(String[] args) {
        String str;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter String and char");
        str=sc.nextLine();
        char c=sc.nextLine().charAt(0);
        frequency ob=new frequency(str, c);
        int count=ob.count();
        System.out.println("Count: "+ count);
        ob.print(count);
        ob=null;
        System.gc();
        try {
            Thread.sleep(1000);
        } catch (Exception e) {
            // TODO: handle exception
        }
    }   
}
