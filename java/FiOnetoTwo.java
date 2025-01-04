import java.io.*;
import java.util.*;

/*Read from file "abc.txt" and write the count of 
  each word in it to another file "count.txt"*/

public class FiOnetoTwo {
    public static void main(String[] args) {
        //String file1=args[0];
        BufferedReader br=null;
        FileWriter fw=null;
        try{
            fw=new FileWriter("count.txt");
            br=new BufferedReader(new FileReader("file1.txt"));
            String s;
            while((s=br.readLine())!=null)
            {
                StringTokenizer strtok=new StringTokenizer(s);
                while(strtok.hasMoreTokens()==true)
                {
                    String temp=strtok.nextToken();
                    fw.write(temp+" = "+ temp.length()+"\n");                   
                }
            }

        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
        finally{
            try{
                fw.close();
                br.close();
            }
            catch(Exception e)
            {
                System.out.println(e.getMessage());
            }
        }

    }
}
