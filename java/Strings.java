import java.util.*;

public class Strings {
    public static void main(String[] args) {
        String str="HelleH World JavaJ is BoB";
        StringTokenizer strtok=new StringTokenizer(str," ");
        while(strtok.hasMoreTokens())
        {
            String st=strtok.nextToken();
            int i=0,j=(st.length()-1),flag=0;
            while(i<=j)
            {
                if(st.charAt(i)!=st.charAt(j))
                {
                    flag=1;
                    break;
                }
                i++;
                j--;
            }
            System.out.println(st);
            System.out.println(st.startsWith("J"));
            if (flag==0)
            {
                String rep="*";
                for(int x=0;x<st.length()-1;x++)
                {
                    rep=rep+"*";
                }
                str=str.replaceAll(st,rep);
            }
        }
        System.out.println(str);
        
    }
}
