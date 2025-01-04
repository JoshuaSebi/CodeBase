import java.util.*;

public class palindrome {
    public static void main(String args[])
    {
        String str;
        System.out.println("Enter String: ");
        Scanner sc=new Scanner(System.in);
        str=sc.nextLine();
        int len=str.length();
        int i=0,j=len-1;
        int flag=0;
        while(i<=j)
        {
            if(str.charAt(i)!=str.charAt(j))
            {
                flag=1;
                break;
            }
            i++;
            j--;
        }
        if (flag!=0)
        {
            System.out.println("Not a palindrome");
        }
        else{
            System.out.println(str+" is a palindrome");
        }
    }
}
